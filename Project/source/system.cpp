#include "system.h"
#include "data.h"

void system_init()
{
  clockBase.PITinit();
  LEDBase.LED_init();
  //checkBase.check_Init();
  buttonBase.button_Init();
  clockBase.Set_Current_State(Ready);
}

void System_RunTime_Update()
{
  time temp;
  temp=clockBase.GetCurrentTime();
  PRINTF("current time:%d\n",temp.second);
}