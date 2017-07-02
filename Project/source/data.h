#ifndef __DATA_H__
#define __DATA_H__

#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_rtc.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_gpio.h"

/****�ƹ���ʾ****/
class LED
{
public:
  LED();
  void LED_init();
  void setColor(unsigned char R,unsigned char G,unsigned char B);
  void setColor(bool R,bool G,bool B);
private:
  gpio_pin_config_t LED_Config;
};

extern LED LEDBase;
/****����ѡ��****/
class button
{
public:
  button();
  void button_Init();
  void on_PushButton_Clicked();
private:
  gpio_pin_config_t button_Config;
  
};

extern button buttonBase;
/****��紥��****/
class check
{
public:
  check();
  void Car_Pass();              //���ܴ�������
  void check_Init();            //�жϵȳ�ʼ������
private:
  gpio_pin_config_t button_Config;
};

extern check checkBase;
/****RTC��ʱ****/
typedef enum State
{
  Running,
  Stop,
  Ready,
  
  MAX_State
} Clock_State;
  

class clock
{
public:
  clock();
  void RTC_Init();
  struct Time
  {
    int second;
    int M_Second;
  };
  void GetCurrentTime();
  char Get_Current_State();
  void Set_Current_State(char State);
private:
  void Check_Current_State();
  void start();
  void stop();
  char Current_State;
  
};

extern clock clockBase;

/****OLED��ʾ****/
class OLED
{
public:
private:
};

extern OLED OLEDBase;

#endif __DATA_H__