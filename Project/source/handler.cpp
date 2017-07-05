#include "data.h"
extern "C"
{
  void PORTC_IRQHandler()
  {
    if(GPIO_GetPinsInterruptFlags(GPIOC)&(1<<6))
    {
      
      PRINTF("GET");
      
      //if(clockBase.Get_Current_State()==Running)
        buttonBase.on_PushButton_Clicked();
      //else if(clockBase.Get_Current_State()==Ready)
        //buttonBase.on_PushButton_Clicked();
      
    }
  
    GPIO_ClearPinsInterruptFlags(GPIOC,1<<6);
  }
  
  void PIT0_IRQHandler()
  {
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    clockBase.CurrentTimeAddMS(10);
    //TODOˢ����ʾ�ȣ���������һ���ж���ʵ��
  }
  
  void PORTA_IRQHandler()
  {
    if(GPIO_GetPinsInterruptFlags(GPIOA)&(1<<4))
    {
      buttonBase.on_PushButton_Clicked();
    }
    GPIO_ClearPinsInterruptFlags(GPIOA, 1U << 4);
  }
}