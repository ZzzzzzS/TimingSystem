#include "system.h"
#include "data.h"
#include "OLED.h"
#include "stdio.h"

void system_init()
{
  clockBase.PITinit();
  LEDBase.LED_init();
  //checkBase.check_Init();
  buttonBase.button_Init();
  clockBase.Set_Current_State(Ready);
  OLEDBase.SPIPins[OLED::RESET].base=GPIOB;
  OLEDBase.SPIPins[OLED::RESET].pin=4;
  OLEDBase.SPIPins[OLED::DC].base=GPIOB;
  OLEDBase.SPIPins[OLED::DC].pin=3;
  OLEDBase.SPIPins[OLED::D0].base=GPIOB;
  OLEDBase.SPIPins[OLED::D0].pin=9;
  OLEDBase.SPIPins[OLED::D1].base=GPIOB;
  OLEDBase.SPIPins[OLED::D1].pin=8;
  OLEDBase.OLED_Init();
}

void System_RunTime_Update()
{

  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  time temp;
  temp=clockBase.GetCurrentTime();
  char display[20];
  PRINTF("current time:%d\n",temp.second);
  sprintf(display,"time %d:%03d",temp.second,temp.M_Second);
  OLEDBase.OLED_Print(1,0,display);

}