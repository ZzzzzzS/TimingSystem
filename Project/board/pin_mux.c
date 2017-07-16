/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MK60DN512xxx10
package_id: MK60DN512VLQ10
mcu_data: ksdk2_0
processor_version: 2.0.0
pin_labels:
- {pin_num: '99', pin_signal: PTB20/SPI2_PCS0/FB_AD31/CMP0_OUT, label: LED0}
- {pin_num: '100', pin_signal: PTB21/SPI2_SCK/FB_AD30/CMP1_OUT, label: LED1}
- {pin_num: '101', pin_signal: PTB22/SPI2_SOUT/FB_AD29/CMP2_OUT, label: LED2}
- {pin_num: '102', pin_signal: PTB23/SPI2_SIN/SPI0_PCS5/FB_AD28, label: LED3}
- {pin_num: '105', pin_signal: ADC0_SE4b/CMP1_IN0/TSI0_CH15/PTC2/SPI0_PCS2/UART1_CTS_b/FTM0_CH1/FB_AD12/I2S0_TX_FS, label: DC}
- {pin_num: '109', pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/FTM0_CH3/FB_AD11/CMP1_OUT, label: RES}
- {pin_num: '110', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/I2S0_RXD0/FB_AD10/CMP0_OUT, label: D1}
- {pin_num: '112', pin_signal: CMP0_IN1/PTC7/SPI0_SIN/USB_SOF_OUT/I2S0_RX_FS/FB_AD8, label: D0}
- {pin_num: '136', pin_signal: PTD7/CMT_IRO/UART0_TX/FTM0_CH7/FTM0_FLT1, label: Button}
- {pin_num: '76', pin_signal: PTA25/MII0_TXCLK/FB_A28, label: check}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/*FUNCTION**********************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 *END**************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
    BOARD_InitLED();
    BOARD_InitOLED();
    BOARD_InitButton();
}

#define PCR_PE_ENABLED                0x01u   /*!< Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input. */
#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '72', peripheral: OSC, signal: EXTAL0, pin_signal: EXTAL0/PTA18/FTM0_FLT2/FTM_CLKIN0}
  - {pin_num: '73', peripheral: OSC, signal: XTAL0, pin_signal: XTAL0/PTA19/FTM1_FLT0/FTM_CLKIN1/LPTMR0_ALT1}
  - {pin_num: '1', peripheral: RTC, signal: CLKOUT, pin_signal: ADC1_SE4a/PTE0/SPI1_PCS1/UART1_TX/SDHC0_D1/I2C1_SDA/RTC_CLKOUT}
  - {pin_num: '41', peripheral: RTC, signal: EXTAL32, pin_signal: EXTAL32}
  - {pin_num: '42', peripheral: RTC, signal: VBAT, pin_signal: VBAT}
  - {pin_num: '40', peripheral: RTC, signal: XTAL32, pin_signal: XTAL32}
  - {pin_num: '81', peripheral: GPIOB, signal: 'GPIO, 0', pin_signal: ADC0_SE8/ADC1_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/FTM1_CH0/RMII0_MDIO/MII0_MDIO/FTM1_QD_PHA,
    direction: INPUT}
  - {pin_num: '54', peripheral: GPIOA, signal: 'GPIO, 4', pin_signal: TSI0_CH5/PTA4/LLWU_P3/FTM0_CH1/NMI_b/EZP_CS_b, direction: OUTPUT, open_drain: no_init, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN18_IDX, kPORT_PinDisabledOrAnalog); /* PORTA18 (pin 72) is configured as EXTAL0 */
  PORT_SetPinMux(PORTA, PIN19_IDX, kPORT_PinDisabledOrAnalog); /* PORTA19 (pin 73) is configured as XTAL0 */
  PORT_SetPinMux(PORTA, PIN4_IDX, kPORT_MuxAsGpio);          /* PORTA4 (pin 54) is configured as PTA4 */
  PORTA->PCR[4] = ((PORTA->PCR[4] &
    (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))               /* Mask bits to zero which are setting */
      | PORT_PCR_PE(PCR_PE_ENABLED)                          /* Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input. */
    );
  PORT_SetPinMux(PORTB, PIN0_IDX, kPORT_MuxAsGpio);          /* PORTB0 (pin 81) is configured as PTB0 */
  PORT_SetPinMux(PORTE, PIN0_IDX, kPORT_MuxAlt7);            /* PORTE0 (pin 1) is configured as RTC_CLKOUT */
}


#define PCR_DSE_HIGH                  0x01u   /*!< Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin is configured as a digital output. */
#define PIN20_IDX                       20u   /*!< Pin number for pin 20 in a port */
#define PIN21_IDX                       21u   /*!< Pin number for pin 21 in a port */
#define PIN22_IDX                       22u   /*!< Pin number for pin 22 in a port */
#define PIN23_IDX                       23u   /*!< Pin number for pin 23 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLED:
- options: {callFromInitBoot: 'true', prefix: BOARD_INITLED_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '99', peripheral: GPIOB, signal: 'GPIO, 20', pin_signal: PTB20/SPI2_PCS0/FB_AD31/CMP0_OUT, direction: OUTPUT, pull_select: no_init, drive_strength: high}
  - {pin_num: '100', peripheral: GPIOB, signal: 'GPIO, 21', pin_signal: PTB21/SPI2_SCK/FB_AD30/CMP1_OUT, direction: OUTPUT, pull_select: no_init, drive_strength: high}
  - {pin_num: '101', peripheral: GPIOB, signal: 'GPIO, 22', pin_signal: PTB22/SPI2_SOUT/FB_AD29/CMP2_OUT, direction: OUTPUT, pull_select: no_init, drive_strength: high}
  - {pin_num: '102', peripheral: GPIOB, signal: 'GPIO, 23', pin_signal: PTB23/SPI2_SIN/SPI0_PCS5/FB_AD28, direction: OUTPUT, pull_select: no_init}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitLED
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitLED(void) {
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTB, PIN20_IDX, kPORT_MuxAsGpio);         /* PORTB20 (pin 99) is configured as PTB20 */
  PORTB->PCR[20] = ((PORTB->PCR[20] &
    (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))              /* Mask bits to zero which are setting */
      | PORT_PCR_DSE(PCR_DSE_HIGH)                           /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTB, PIN21_IDX, kPORT_MuxAsGpio);         /* PORTB21 (pin 100) is configured as PTB21 */
  PORTB->PCR[21] = ((PORTB->PCR[21] &
    (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))              /* Mask bits to zero which are setting */
      | PORT_PCR_DSE(PCR_DSE_HIGH)                           /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTB, PIN22_IDX, kPORT_MuxAsGpio);         /* PORTB22 (pin 101) is configured as PTB22 */
  PORTB->PCR[22] = ((PORTB->PCR[22] &
    (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))              /* Mask bits to zero which are setting */
      | PORT_PCR_DSE(PCR_DSE_HIGH)                           /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTB, PIN23_IDX, kPORT_MuxAsGpio);         /* PORTB23 (pin 102) is configured as PTB23 */
}


#define PIN10_IDX                       10u   /*!< Pin number for pin 10 in a port */
#define PIN12_IDX                       12u   /*!< Pin number for pin 12 in a port */
#define PIN14_IDX                       14u   /*!< Pin number for pin 14 in a port */
#define PIN16_IDX                       16u   /*!< Pin number for pin 16 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitOLED:
- options: {callFromInitBoot: 'true', prefix: BOARD_INITOLED_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '115', peripheral: GPIOC, signal: 'GPIO, 10', pin_signal: ADC1_SE6b/PTC10/I2C1_SCL/I2S0_RX_FS/FB_AD5, direction: OUTPUT}
  - {pin_num: '117', peripheral: GPIOC, signal: 'GPIO, 12', pin_signal: PTC12/UART4_RTS_b/FB_AD27, direction: OUTPUT}
  - {pin_num: '119', peripheral: GPIOC, signal: 'GPIO, 14', pin_signal: PTC14/UART4_RX/FB_AD25, direction: OUTPUT}
  - {pin_num: '123', peripheral: GPIOC, signal: 'GPIO, 16', pin_signal: PTC16/CAN1_RX/UART3_RX/ENET0_1588_TMR0/FB_CS5_b/FB_TSIZ1/FB_BE23_16_b, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitOLED
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitOLED(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTC, PIN10_IDX, kPORT_MuxAsGpio);         /* PORTC10 (pin 115) is configured as PTC10 */
  PORT_SetPinMux(PORTC, PIN12_IDX, kPORT_MuxAsGpio);         /* PORTC12 (pin 117) is configured as PTC12 */
  PORT_SetPinMux(PORTC, PIN14_IDX, kPORT_MuxAsGpio);         /* PORTC14 (pin 119) is configured as PTC14 */
  PORT_SetPinMux(PORTC, PIN16_IDX, kPORT_MuxAsGpio);         /* PORTC16 (pin 123) is configured as PTC16 */
}


#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitButton:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '136', peripheral: GPIOD, signal: 'GPIO, 7', pin_signal: PTD7/CMT_IRO/UART0_TX/FTM0_CH7/FTM0_FLT1, direction: INPUT, pull_select: no_init}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitButton
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitButton(void) {
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTD, PIN7_IDX, kPORT_MuxAsGpio);          /* PORTD7 (pin 136) is configured as PTD7 */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
