/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 2.0.0
board: FRDM-K64F
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
    BOARD_InitButtons();
    BOARD_InitLEDs();
    BOARD_InitDEBUG_UART();
    BOARD_InitOSC();
}

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN14_IDX                       14u   /*!< Pin number for pin 14 in a port */
#define PIN17_IDX                       17u   /*!< Pin number for pin 17 in a port */
#define PIN23_IDX                       23u   /*!< Pin number for pin 23 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: RTC, signal: CLKOUT, pin_signal: ADC1_SE4a/PTE0/SPI1_PCS1/UART1_TX/SDHC0_D1/TRACE_CLKOUT/I2C1_SDA/RTC_CLKOUT}
  - {pin_num: '29', peripheral: RTC, signal: EXTAL32, pin_signal: EXTAL32, identifier: ''}
  - {pin_num: '30', peripheral: RTC, signal: VBAT, pin_signal: VBAT}
  - {pin_num: '28', peripheral: RTC, signal: XTAL32, pin_signal: XTAL32, identifier: ''}
  - {pin_num: '44', peripheral: SPI0, signal: PCS0_SS, pin_signal: PTA14/SPI0_PCS0/UART0_TX/RMII0_CRS_DV/MII0_RXDV/I2C2_SCL/I2S0_RX_BCLK/I2S0_TXD1}
  - {pin_num: '73', peripheral: SPI0, signal: PCS1, pin_signal: CMP1_IN1/PTC3/LLWU_P7/SPI0_PCS1/UART1_RX/FTM0_CH2/CLKOUT/I2S0_TX_BCLK}
  - {pin_num: '72', peripheral: SPI0, signal: PCS2, pin_signal: ADC0_SE4b/CMP1_IN0/PTC2/SPI0_PCS2/UART1_CTS_b/FTM0_CH1/FB_AD12/I2S0_TX_FS}
  - {pin_num: '71', peripheral: SPI0, signal: PCS3, pin_signal: ADC0_SE15/PTC1/LLWU_P6/SPI0_PCS3/UART1_RTS_b/FTM0_CH0/FB_AD13/I2S0_TXD0}
  - {pin_num: '70', peripheral: SPI0, signal: PCS4, pin_signal: ADC0_SE14/PTC0/SPI0_PCS4/PDB0_EXTRG/USB_SOF_OUT/FB_AD14/I2S0_TXD1}
  - {pin_num: '69', peripheral: SPI0, signal: PCS5_PCSS, pin_signal: PTB23/SPI2_SIN/SPI0_PCS5/FB_AD28}
  - {pin_num: '94', peripheral: SPI0, signal: SCK, pin_signal: ADC0_SE5b/PTD1/SPI0_SCK/UART2_CTS_b/FTM3_CH1/FB_CS0_b}
  - {pin_num: '47', peripheral: SPI0, signal: SIN, pin_signal: ADC1_SE17/PTA17/SPI0_SIN/UART0_RTS_b/RMII0_TXD1/MII0_TXD1/I2S0_MCLK}
  - {pin_num: '78', peripheral: SPI0, signal: SOUT, pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_SOUT/PDB0_EXTRG/I2S0_RX_BCLK/FB_AD9/I2S0_MCLK}
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
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN14_IDX, kPORT_MuxAlt2);           /* PORTA14 (pin 44) is configured as SPI0_PCS0 */
  PORT_SetPinMux(PORTA, PIN17_IDX, kPORT_MuxAlt2);           /* PORTA17 (pin 47) is configured as SPI0_SIN */
  PORT_SetPinMux(PORTB, PIN23_IDX, kPORT_MuxAlt3);           /* PORTB23 (pin 69) is configured as SPI0_PCS5 */
  PORT_SetPinMux(PORTC, PIN0_IDX, kPORT_MuxAlt2);            /* PORTC0 (pin 70) is configured as SPI0_PCS4 */
  PORT_SetPinMux(PORTC, PIN1_IDX, kPORT_MuxAlt2);            /* PORTC1 (pin 71) is configured as SPI0_PCS3 */
  PORT_SetPinMux(PORTC, PIN2_IDX, kPORT_MuxAlt2);            /* PORTC2 (pin 72) is configured as SPI0_PCS2 */
  PORT_SetPinMux(PORTC, PIN3_IDX, kPORT_MuxAlt2);            /* PORTC3 (pin 73) is configured as SPI0_PCS1 */
  PORT_SetPinMux(PORTC, PIN6_IDX, kPORT_MuxAlt2);            /* PORTC6 (pin 78) is configured as SPI0_SOUT */
  PORT_SetPinMux(PORTD, PIN1_IDX, kPORT_MuxAlt2);            /* PORTD1 (pin 94) is configured as SPI0_SCK */
  PORT_SetPinMux(PORTE, PIN0_IDX, kPORT_MuxAlt7);            /* PORTE0 (pin 1) is configured as RTC_CLKOUT */
}


#define PCR_ODE_DISABLED              0x00u   /*!< Open Drain Enable: Open drain output is disabled on the corresponding pin. */
#define PCR_PE_ENABLED                0x01u   /*!< Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input. */
#define PCR_PFE_DISABLED              0x00u   /*!< Passive Filter Enable: Passive input filter is disabled on the corresponding pin. */
#define PCR_PS_UP                     0x01u   /*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_SRE_FAST                  0x00u   /*!< Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */

#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */

#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */

#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */
#define PIN5_IDX                         5u   /*!< Pin number for pin 5 in a port */

#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitButtons:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '78', peripheral: GPIOC, signal: 'GPIO, 6', pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_SOUT/PDB0_EXTRG/I2S0_RX_BCLK/FB_AD9/I2S0_MCLK, identifier: SW2,
    direction: INPUT, slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: '38', peripheral: GPIOA, signal: 'GPIO, 4', pin_signal: PTA4/LLWU_P3/FTM0_CH1/NMI_b/EZP_CS_b, direction: INPUT, slew_rate: fast, open_drain: disable,
    drive_strength: no_init, pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: '93', peripheral: GPIOD, signal: 'GPIO, 0', pin_signal: PTD0/LLWU_P12/SPI0_PCS0/UART2_RTS_b/FTM3_CH0/FB_ALE/FB_CS1_b/FB_TS_b}
  - {pin_num: '94', peripheral: GPIOD, signal: 'GPIO, 1', pin_signal: ADC0_SE5b/PTD1/SPI0_SCK/UART2_CTS_b/FTM3_CH1/FB_CS0_b}
  - {pin_num: '95', peripheral: GPIOD, signal: 'GPIO, 2', pin_signal: PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FB_AD4/I2C0_SCL}
  - {pin_num: '96', peripheral: GPIOD, signal: 'GPIO, 3', pin_signal: PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FB_AD3/I2C0_SDA}
  - {pin_num: '97', peripheral: GPIOD, signal: 'GPIO, 4', pin_signal: PTD4/LLWU_P14/SPI0_PCS1/UART0_RTS_b/FTM0_CH4/FB_AD2/EWM_IN/SPI1_PCS0}
  - {pin_num: '98', peripheral: GPIOD, signal: 'GPIO, 5', pin_signal: ADC0_SE6b/PTD5/SPI0_PCS2/UART0_CTS_b/UART0_COL_b/FTM0_CH5/FB_AD1/EWM_OUT_b/SPI1_SCK}
  - {pin_num: '99', peripheral: GPIOD, signal: 'GPIO, 6', pin_signal: ADC0_SE7b/PTD6/LLWU_P15/SPI0_PCS3/UART0_RX/FTM0_CH6/FB_AD0/FTM0_FLT0/SPI1_SOUT}
  - {pin_num: '100', peripheral: GPIOD, signal: 'GPIO, 7', pin_signal: PTD7/CMT_IRO/UART0_TX/FTM0_CH7/FTM0_FLT1/SPI1_SIN}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitButtons
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitButtons(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN4_IDX, kPORT_MuxAsGpio);          /* PORTA4 (pin 38) is configured as PTA4 */
  PORTA->PCR[4] = ((PORTA->PCR[4] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_PFE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_ENABLED)                          /* Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input. */
      | PORT_PCR_SRE(PCR_SRE_FAST)                           /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
      | PORT_PCR_PFE(PCR_PFE_DISABLED)                       /* Passive Filter Enable: Passive input filter is disabled on the corresponding pin. */
      | PORT_PCR_ODE(PCR_ODE_DISABLED)                       /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
    );
  const port_pin_config_t portc6_pin78_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC6 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTC, PIN6_IDX, &portc6_pin78_config);  /* PORTC6 (pin 78) is configured as PTC6 */
  PORT_SetPinMux(PORTD, PIN0_IDX, kPORT_MuxAsGpio);          /* PORTD0 (pin 93) is configured as PTD0 */
  PORT_SetPinMux(PORTD, PIN1_IDX, kPORT_MuxAsGpio);          /* PORTD1 (pin 94) is configured as PTD1 */
  PORT_SetPinMux(PORTD, PIN2_IDX, kPORT_MuxAsGpio);          /* PORTD2 (pin 95) is configured as PTD2 */
  PORT_SetPinMux(PORTD, PIN3_IDX, kPORT_MuxAsGpio);          /* PORTD3 (pin 96) is configured as PTD3 */
  PORT_SetPinMux(PORTD, PIN4_IDX, kPORT_MuxAsGpio);          /* PORTD4 (pin 97) is configured as PTD4 */
  PORT_SetPinMux(PORTD, PIN5_IDX, kPORT_MuxAsGpio);          /* PORTD5 (pin 98) is configured as PTD5 */
  PORT_SetPinMux(PORTD, PIN6_IDX, kPORT_MuxAsGpio);          /* PORTD6 (pin 99) is configured as PTD6 */
  PORT_SetPinMux(PORTD, PIN7_IDX, kPORT_MuxAsGpio);          /* PORTD7 (pin 100) is configured as PTD7 */
}


#define PIN21_IDX                       21u   /*!< Pin number for pin 21 in a port */
#define PIN22_IDX                       22u   /*!< Pin number for pin 22 in a port */
#define PIN26_IDX                       26u   /*!< Pin number for pin 26 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDs:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '67', peripheral: GPIOB, signal: 'GPIO, 21', pin_signal: PTB21/SPI2_SCK/FB_AD30/CMP1_OUT, direction: OUTPUT, slew_rate: slow, open_drain: disable, drive_strength: low,
    pull_select: down, pull_enable: disable, passive_filter: disable}
  - {pin_num: '68', peripheral: GPIOB, signal: 'GPIO, 22', pin_signal: PTB22/SPI2_SOUT/FB_AD29/CMP2_OUT, direction: OUTPUT, slew_rate: slow, open_drain: disable,
    drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable}
  - {pin_num: '33', peripheral: GPIOE, signal: 'GPIO, 26', pin_signal: PTE26/ENET_1588_CLKIN/UART4_CTS_b/RTC_CLKOUT/USB_CLKIN, direction: OUTPUT, slew_rate: slow,
    open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitLEDs
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitLEDs(void) {
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  const port_pin_config_t portb21_pin67_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB21 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTB, PIN21_IDX, &portb21_pin67_config); /* PORTB21 (pin 67) is configured as PTB21 */
  const port_pin_config_t portb22_pin68_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB22 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTB, PIN22_IDX, &portb22_pin68_config); /* PORTB22 (pin 68) is configured as PTB22 */
  const port_pin_config_t porte26_pin33_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTE26 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTE, PIN26_IDX, &porte26_pin33_config); /* PORTE26 (pin 33) is configured as PTE26 */
}


#define PIN16_IDX                       16u   /*!< Pin number for pin 16 in a port */

#define PIN17_IDX                       17u   /*!< Pin number for pin 17 in a port */
#define SOPT5_UART0TXSRC_UART_TX      0x00u   /*!< UART 0 transmit data source select: UART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UART:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '63', peripheral: UART0, signal: TX, pin_signal: PTB17/SPI1_SIN/UART0_TX/FTM_CLKIN1/FB_AD16/EWM_OUT_b, direction: OUTPUT, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable}
  - {pin_num: '62', peripheral: UART0, signal: RX, pin_signal: PTB16/SPI1_SOUT/UART0_RX/FTM_CLKIN0/FB_AD17/EWM_IN, slew_rate: fast, open_drain: disable, drive_strength: low,
    pull_select: down, pull_enable: disable, passive_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UART
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitDEBUG_UART(void) {
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */

  const port_pin_config_t portb16_pin62_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt3,                                           /* Pin is configured as UART0_RX */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTB, PIN16_IDX, &portb16_pin62_config); /* PORTB16 (pin 62) is configured as UART0_RX */
  const port_pin_config_t portb17_pin63_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt3,                                           /* Pin is configured as UART0_TX */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTB, PIN17_IDX, &portb17_pin63_config); /* PORTB17 (pin 63) is configured as UART0_TX */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_UART0TXSRC_MASK)))                          /* Mask bits to zero which are setting */
      | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)       /* UART 0 transmit data source select: UART0_TX pin */
    );
}


#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitOSC:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '50', peripheral: OSC, signal: EXTAL0, pin_signal: EXTAL0/PTA18/FTM0_FLT2/FTM_CLKIN0, identifier: EXTAL0, slew_rate: no_init, open_drain: no_init, drive_strength: no_init,
    pull_select: no_init, pull_enable: no_init, passive_filter: no_init}
  - {pin_num: '29', peripheral: RTC, signal: EXTAL32, pin_signal: EXTAL32}
  - {pin_num: '28', peripheral: RTC, signal: XTAL32, pin_signal: XTAL32}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitOSC
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitOSC(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN18_IDX, kPORT_PinDisabledOrAnalog); /* PORTA18 (pin 50) is configured as EXTAL0 */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
