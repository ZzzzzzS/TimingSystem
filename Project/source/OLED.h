#ifndef __OLED_H__
#define __OLED_H__
#include "fsl_gpio.h"

typedef unsigned char byte;

struct Pins
{
  GPIO_Type *base;
  uint32_t pin;
};


class OLED
{
public:
  OLED();
  Pins SPIPins[4];
  void Set_Fonts(const byte* Idx,const byte* Fonts);
  void Set_Fonts_English(const char* EnglishFonts);
  void OLED_Init();
  void OLED_CLS();
  void OLED_Print(byte x,byte y,char ch[]);
  void OLED_PutPixel(byte x, byte y);
  enum PinType
  {
    RESET,
    DC,
    D1,
    D0,
  };
  
private:
  void OLED_WrDat(byte data);
  void OLED_WrCmd(byte cmd);
  void OLED_Set_Pos(byte x, byte y);
  void OLED_Fill(byte bmp_data);
  void OLED_P8x16Str(byte x, byte y, byte ch[]);
  void OLED_P14x16Str(byte x, byte y, byte ch[]);
  void OLED_DLY_ms(unsigned int ms);
  void GPIO_Init();
  
  const byte* Idx;            //定义字体库
  const byte* Fonts;          //定义字体库

  const char* EnglishFonts;   //英文字体无法修改
};



#endif //__OLED_H__