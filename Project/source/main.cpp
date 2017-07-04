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
