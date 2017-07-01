#ifndef __DATA_H__
#define __DATA_H__

#include "fsl_gpio.h"

class LED
{
public:
  LED();
  void setColor(unsigned char R,unsigned char G,unsigned char B);
private:
  gpio_pin_config_t LED_Config;
}

class button
{
public:
  button();
  void on_PushButton_Clicked();
private:
  gpio_pin_config_t button_Config;
}

class clock
{
public:
  clock();
  struct Time
  {
    int second;
    int M_Second;
  }
  void GetCurrentTime();
  void start();
  void stop();
  void pause();
private:
  
}


#endif __DATA_H__