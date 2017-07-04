#include "system.h"
#include "data.h"

void system_init()
{
  //clockBase.PITinit();
  LEDBase.LED_init();
  //checkBase.check_Init();
  buttonBase.button_Init();
  //clockBase.Set_Current_State(Running);
}

void System_RunTime_Update()
{
 time temp;
 temp=clockBase.GetCurrentTime();
 PRINTF("%d %d",temp.second,temp.M_Second);
}