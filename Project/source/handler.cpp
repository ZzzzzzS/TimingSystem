#include "data.h"
extern "C"
{
  void LPTMR0_IRQHandler()
  {
    LPTMR_ClearStatusFlags(LPTMR0, kLPTMR_TimerCompareFlag);
    clockBase.CurrentTimeAddMS(10);
    //TODOˢ����ʾ�ȣ���������һ���ж���ʵ��
  }
  
  void PORTA_IRQHandler()
  {
    if(GPIO_GetPinsInterruptFlags(GPIOA)&(1<<13))
    {
      buttonBase.on_PushButton_Clicked();
      GPIO_ClearPinsInterruptFlags(GPIOA, 1U << 13);
    }
    if(GPIO_GetPinsInterruptFlags(GPIOA)&(1<<8))
    {
      buttonBase.on_PushButton_Clicked();
      GPIO_ClearPinsInterruptFlags(GPIOA, 1U << 8);
    }
    
  }
}