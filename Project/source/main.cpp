/**
 * This is template for main module created by MCUXpresso Project Generator. Enjoy!
 **/

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "system.h"
#include "data.h"

/*!
 * @brief Application entry point.
 */
   
void PIT0_IRQHandler()
{
  PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
  clockBase.CurrentTimeAddMS(10);
  //TODO刷新显示等，可以在另一个中断里实现
}

void PORTA_IRQHandler()
{
  GPIO_ClearPinsInterruptFlags(GPIOA, 1U << 4);
  LEDBase.setColor(0,0,1);
}


int main(void) {
  /* Init board hardware. */
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();
  
  system_init();
  LEDBase.setColor(true,false,false);
  while(true)
  {
    //System_RunTime_Update();
  }

  /* Add your code here */
}
