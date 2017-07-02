#include "data.h"
#include "fsl_gpio.h"

/******LED灯函数******/
LED::LED()
{
  LED_Config.outputLogic=0;
  LED_Config.pinDirection=kGPIO_DigitalOutput;
}

void LED::LED_init()
{
  GPIO_PinInit(GPIOB,21,&LED_Config);
  GPIO_PinInit(GPIOB,22,&LED_Config);
  GPIO_PinInit(GPIOE,26,&LED_Config);
}

void LED::setColor(unsigned char R,unsigned char G,unsigned char B)
{
  
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
  button_Config.pinDirection=KGPIO_DigitalIutput;
  button_Config.outputLogic=0;
}

button::button_Init()
{
    GPIO_PinInit(GPIOE,26,&LED_Config);//管脚不对
}
