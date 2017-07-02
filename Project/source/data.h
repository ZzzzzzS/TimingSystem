#ifndef __DATA_H__
#define __DATA_H__

#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_rtc.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_gpio.h"

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

class button
{
public:
  button();
  void button_Init();
  void on_PushButton_Clicked();
private:
  gpio_pin_config_t button_Config;
  
};

class check
{
public:
  button();
  void Car_Pass();              //光电管触发函数
  void check_Init();            //中断等初始化函数
private:
  gpio_pin_config_t button_Config;
};

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
  void start();
  void stop();
  void pause();
private:
  rtc_datetime_t date;
  rtc_config_t rtc_Config;
  
};

class OLED
{
public:
private:
};

#endif __DATA_H__