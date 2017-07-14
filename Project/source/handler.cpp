#include "data.h"
extern "C"
{
  void PORTB_IRQHandler()
  {
    if(GPIO_GetPinsInterruptFlags(GPIOB)&(1<<1))
    {
      
      PRINTF("GET");
      
      //if(clockBase.Get_Current_State()==Running)
        buttonBase.on_PushButton_Clicked();
      //else if(clockBase.Get_Current_State()==Ready)
        //buttonBase.on_PushButton_Clicked();
      
    }
  
    GPIO_ClearPinsInterruptFlags(GPIOB,1<<1);
  }
  
  void PIT0_IRQHandler()
  {
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    clockBase.CurrentTimeAddMS(10);
    //TODO刷新显示等，可以在另一个中断里实现
  }
  
  void PORTD_IRQHandler()
  {
    if(GPIO_GetPinsInterruptFlags(GPIOD)&(1<<7))
    {
      if(clockBase.Get_Current_State()==Stop)
        asm("nop");
      else
      buttonBase.on_PushButton_Clicked();
    }
    GPIO_ClearPinsInterruptFlags(GPIOD, 1U << 7);
  }
}