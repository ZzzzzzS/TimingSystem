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
  OLEDBase.OLED_Print(1,4,"Powered by ZZS");
  
  buttonBase.on_PushButton_Clicked();
  
  while(true)
  {
    System_RunTime_Update();
  }
}
