#include "data.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_lptmr.h"
#include "board.h"
#include "fsl_debug_console.h"

/****实例化****/
LED LEDBase;
button buttonBase;
check checkBase;
clock clockBase;
OLED OLEDBase;

/******LED灯函数******/
LED::LED()
{
  this->LED_Config.outputLogic=1;
  this->LED_Config.pinDirection=kGPIO_DigitalOutput;
}

void LED::LED_init()
{
  GPIO_PinInit(GPIOB,6,&LED_Config);
  GPIO_PinInit(GPIOB,7,&LED_Config);
  GPIO_PinInit(GPIOB,10,&LED_Config);
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
  GPIO_WritePinOutput(GPIOB,6,!R);
  GPIO_WritePinOutput(GPIOB,7,!G);
  GPIO_WritePinOutput(GPIOB,10,!B);
}


/*********按键函数*******/

button::button()
{
  button_Config.pinDirection=kGPIO_DigitalInput;
  button_Config.outputLogic=0;
}

void button::button_Init()
{
  PORT_SetPinInterruptConfig(PORTA,1,kPORT_InterruptFallingEdge);
  EnableIRQ(PORTA_IRQn);
  GPIO_PinInit(GPIOA,1,&button_Config);
  PRINTF("OK");
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
    
  }
  
  else if(clockBase.Get_Current_State()==Stop)
  {
    clockBase.Set_Current_State(Ready);
    clockBase.SetCurrentTime(time(0,0));
    
  }
  
  else if(clockBase.Get_Current_State()==Ready)
  {
    OLEDBase.OLED_Init();
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    clockBase.Set_Current_State(Running);
  }
  else
  {
    clockBase.Set_Current_State(Stop);
    LEDBase.setColor(false,false,true);
  }
  
}

/****时钟****/

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


clock::clock()
{
  LPTMR_GetDefaultConfig(&pitConfig);
  this->Set_Current_State(Stop);
}

void clock::PITinit()
{
  LPTMR_Init(LPTMR0,&pitConfig);//初始化PIT时钟
  LPTMR_SetTimerPeriod(LPTMR0, USEC_TO_COUNT(10000U, CLOCK_GetFreq(kCLOCK_LpoClk)));//设置周期
  LPTMR_EnableInterrupts(LPTMR0, kLPTMR_TimerInterruptEnable);//允许PIT定时器中断
  EnableIRQ(LPTMR0_IRQn);//允许中断
  LPTMR_StopTimer(LPTMR0);//先停止计时
}

char clock::Get_Current_State()
{
  this->Check_Current_State();
  return this->Current_State;
}

void clock::SetCurrentTime(time set)
{
  this->Current_Time.second=set.second;
  this->Current_Time.M_Second=set.M_Second;
}

void clock::Check_Current_State()
{
  if(this->Current_State==Stop)
  {
    LEDBase.setColor(true,false,false);
    this->stop();
  }
  else if(this->Current_State==Ready)
  {
    LEDBase.setColor(true,true,false);
    this->stop();
  }
  else if(this->Current_State==Running)
  {
    this->start();
    LEDBase.setColor(false,true,false);
  }
  else
  {
    this->stop();
    LEDBase.setColor(false,false,true);//设置系统错误颜色
  }
}

void clock::Set_Current_State(char state)
{
  this->Current_State=state;//设定状态
  this->Check_Current_State();//刷新状态对应的操作
}
  
void clock::stop()
{
  if(this->GetCurrentTime()>time(3,0))               //大于3秒才能停止
    LPTMR_StopTimer(LPTMR0);
}

void clock::start()
{
  LPTMR_StartTimer(LPTMR0);
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

/****检测****/

check::check()
{
  this->Config.outputLogic=0;
  this->Config.pinDirection=kGPIO_DigitalInput;
}

void check::check_Init()
{
  PORT_SetPinInterruptConfig(PORTA,8,kPORT_InterruptEitherEdge);
  EnableIRQ(PORTA_IRQn);
  NVIC_EnableIRQ(PORTA_IRQn);
  GPIO_PinInit(GPIOA,8,&Config);
}