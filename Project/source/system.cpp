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
  OLEDBase.SPIPins[OLED::DC].base=GPIOC;
  OLEDBase.SPIPins[OLED::DC].pin=16;
  OLEDBase.SPIPins[OLED::RESET].base=GPIOC;
  OLEDBase.SPIPins[OLED::RESET].pin=14;
  OLEDBase.SPIPins[OLED::D1].base=GPIOC;
  OLEDBase.SPIPins[OLED::D1].pin=12;
  OLEDBase.SPIPins[OLED::D0].base=GPIOC;
  OLEDBase.SPIPins[OLED::D0].pin=10;

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
  if(temp.second%5==0&&clockBase.Get_Current_State()==Running)
    OLEDBase.OLED_Init();//5秒初始化一次
  char display[20];
  
  
  PRINTF("current time:%d\n",temp.second);
  sprintf(display,"time %d:%03d",temp.second,temp.M_Second);
  OLEDBase.OLED_Print(1,0,display);
  //sprintf(display,"speed %d",NowTime);
  //OLEDBase.OLED_Print(2,2,display);
}