#include "data.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_common.h"

/****实例化****/
LED LEDBase;
button buttonBase;
check checkBase;
clock clockBase;
OLED OLEDBase;

/******LED灯函数******/
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

void LED::setColor(bool R,bool G,bool B)
{
  GPIO_WritePinOutput(GPIOB,21,B);
  GPIO_WritePinOutput(GPIOB,22,R);
  GPIO_WritePinOutput(GPIOE,26,G);
}


/*********按键函数*******/

button::button()
{
  button_Config.pinDirection=kGPIO_DigitalInput;
  button_Config.outputLogic=0;
}

void button::button_Init()
{
  PORT_SetPinInterruptConfig(PORTA,4,kPORT_InterruptFallingEdge);
  EnableIRQ(PORTA_IRQn);
  GPIO_PinInit(GPIOA,4,&button_Config);//管脚不对
}

void button::on_PushButton_Clicked()
{
  if(clockBase.Get_Current_State()==Running)
  {
    clockBase.Set_Current_State(Stop);
    LEDBase.setColor(1,0,0);
  }
  
  else if(clockBase.Get_Current_State()==Stop)
  {
    clockBase.Set_Current_State(Ready);
    LEDBase.setColor(1,1,0);
  }
  
  else if(clockBase.Get_Current_State()==Ready)
  {
    clockBase.Set_Current_State(Running);
    LEDBase.setColor(0,1,0);
  }
  else
  {
    clockBase.Set_Current_State(Stop);
    LEDBase.setColor(0,0,0);
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

/****时钟****/
clock::clock()
{

}

void clock::RTC_Init()
{
  
}

/****检测****/
check::check()
{
  
}