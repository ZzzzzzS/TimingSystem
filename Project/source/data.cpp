#include "data.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_pit.h"
#include "fsl_debug_console.h"

/****ʵ����****/
LED LEDBase;
button buttonBase;
check checkBase;
clock clockBase;
OLED OLEDBase;

/******LED�ƺ���******/
LED::LED()
{
  this->LED_Config.outputLogic=0;
  this->LED_Config.pinDirection=kGPIO_DigitalOutput;
}

void LED::LED_init()
{
  GPIO_PinInit(GPIOB,21,&LED_Config);
  GPIO_PinInit(GPIOB,22,&LED_Config);
  GPIO_PinInit(GPIOE,26,&LED_Config);
}

void LED::setColor(unsigned char R,unsigned char G,unsigned char B)
{
  this->setColor((bool)R,(bool)G,(bool)B);
}

void LED::setColor(int R,int G,int B)
{
  this->setColor((bool)R,(bool)G,(bool)B);
}

void LED::setColor(bool R,bool G,bool B)
{
  GPIO_WritePinOutput(GPIOB,21,B);
  GPIO_WritePinOutput(GPIOB,22,R);
  GPIO_WritePinOutput(GPIOE,26,G);
}


/*********��������*******/

button::button()
{
  button_Config.pinDirection=kGPIO_DigitalInput;
  button_Config.outputLogic=0;
}

void button::button_Init()
{
  PORT_SetPinInterruptConfig(PORTA,4,kPORT_InterruptFallingEdge);
  EnableIRQ(PORTA_IRQn);
  GPIO_PinInit(GPIOA,4,&button_Config);
}

void button::on_PushButton_Clicked()
{
  if(clockBase.Get_Current_State()==Running)
  {
    if(time(5,0)>clockBase.GetCurrentTime())
    {
      return;
    }
    clockBase.Set_Current_State(Stop);
    LEDBase.setColor(true,false,false);
  }
  
  else if(clockBase.Get_Current_State()==Stop)
  {
    clockBase.Set_Current_State(Ready);
    LEDBase.setColor(true,true,false);
  }
  
  else if(clockBase.Get_Current_State()==Ready)
  {
    clockBase.Set_Current_State(Running);
    LEDBase.setColor(false,true,false);
  }
  else
  {
    clockBase.Set_Current_State(Stop);
    LEDBase.setColor(false,false,true);
  }
  
}

void PORTA_IRQHandler()
{
  if(GPIO_GetPinsInterruptFlags(GPIOA)&(1<<4))
  {
    buttonBase.on_PushButton_Clicked();
  }

  GPIO_ClearPinsInterruptFlags(GPIOA,1<<4);
}

/****ʱ��****/

time::time(unsigned int S,unsigned int MS)
{
  this->second=S;
  this->M_Second=MS;
}

time::time()
{
  this->second=0;
  this->M_Second=0;
}

bool time::operator>(const time& Another) const
{
  if(this->second<Another.second)
    return false;
  else if(this->second>Another.second)
    return true;
  else
  {
    if(this->M_Second>Another.M_Second)
      return true;
    else
      return false;
  }
}

void PIT0_IRQHandler()
{
  PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
  clockBase.CurrentTimeAddMS(1);
  //TODOˢ����ʾ�ȣ���������һ���ж���ʵ��
}

clock::clock()
{
  PIT_GetDefaultConfig(&pitConfig);
}

void clock::PITinit()
{
  PIT_Init(PIT,&pitConfig);//��ʼ��PITʱ��
  PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000U, CLOCK_GetFreq(kCLOCK_BusClk)));//��������
  PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);//����PIT��ʱ���ж�
  EnableIRQ(PIT0_IRQn);//�����ж�
  PIT_StopTimer(PIT, kPIT_Chnl_0);//��ֹͣ��ʱ
}

char clock::Get_Current_State()
{
  this->Check_Current_State();
  return this->Current_State;
}

void clock::Check_Current_State()
{
  if(this->Current_State==Stop)
    this->stop();
  else if(this->Current_State==Ready)
    this->stop();
  else if(this->Current_State==Running)
    this->start();
  else
  {
    this->stop();
    LEDBase.setColor(false,false,true);//����ϵͳ������ɫ
  }
}

void clock::Set_Current_State(char state)
{
  this->Current_State=state;//�趨״̬
  this->Check_Current_State();//ˢ��״̬��Ӧ�Ĳ���
}
  
void clock::stop()
{
  if(this->GetCurrentTime()>time(3,0))               //����3�����ֹͣ
    PIT_StopTimer(PIT, kPIT_Chnl_0);
}

void clock::start()
{
  PIT_StartTimer(PIT, kPIT_Chnl_0);
}

void clock::CurrentTimeAddMS(unsigned int MS)
{
  this->Current_Time.M_Second+=MS;
  this->Current_Time.second+=(this->Current_Time.M_Second/1000);
  this->Current_Time.M_Second%=1000;
}

time clock::GetCurrentTime()
{
  return this->Current_Time;
}

/****���****/

void PORTC_IRQHandler()
{
  if(GPIO_GetPinsInterruptFlags(GPIOC)&(1<<6))
  {
    
    PRINTF("GET");
    
    if(clockBase.Get_Current_State()==Running)
      buttonBase.on_PushButton_Clicked();
    else if(clockBase.Get_Current_State()==Ready)
      buttonBase.on_PushButton_Clicked();
    
  }

  GPIO_ClearPinsInterruptFlags(GPIOC,1<<6);
}


check::check()
{
  this->Config.outputLogic=0;
  this->Config.pinDirection=kGPIO_DigitalInput;
}

void check::check_Init()
{
  PORT_SetPinInterruptConfig(PORTC,6,kPORT_InterruptFallingEdge);
  EnableIRQ(PORTC_IRQn);
  GPIO_PinInit(GPIOC,6,&Config);
}