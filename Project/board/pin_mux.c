/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MKL02Z32xxx4
package_id: MKL02Z32VFM4
mcu_data: ksdk2_0
processor_version: 2.0.0
board: FRDM-KL02Z
pin_labels:
- {pin_num: '11', pin_signal: ADC0_SE11/PTB8, label: D1}
- {pin_num: '12', pin_signal: ADC0_SE10/PTB9, label: D0}
- {pin_num: '19', pin_signal: ADC0_SE3/PTA8/I2C1_SCL, label: check}
- {pin_num: '23', pin_signal: PTB3/IRQ_10/I2C0_SCL/UART0_TX, label: DC, identifier: ACCEL_SCL}
- {pin_num: '24', pin_signal: PTB4/IRQ_11/I2C0_SDA/UART0_RX, label: RES, identifier: ACCEL_SDA}
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
    BOARD_InitOSC();
    BOARD_InitDEBUG_UART();
    BOARD_InitLEDs();
    BOARD_InitTOUCH();
}

#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */
#define PIN8_IDX                         8u   /*!< Pin number for pin 8 in a port */
#define PIN9_IDX                         9u   /*!< Pin number for pin 9 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '19', peripheral: GPIOA, signal: 'GPIO, 8', pin_signal: ADC0_SE3/PTA8/I2C1_SCL, direction: INPUT, pull_enable: enable}
  - {pin_num: '23', peripheral: GPIOB, signal: 'GPIO, 3', pin_signal: PTB3/IRQ_10/I2C0_SCL/UART0_TX, identifier: '', pull_enable: enable}
  - {pin_num: '24', peripheral: GPIOB, signal: 'GPIO, 4', pin_signal: PTB4/IRQ_11/I2C0_SDA/UART0_RX, identifier: '', pull_enable: enable}
  - {pin_num: '11', peripheral: GPIOB, signal: 'GPIO, 8', pin_signal: ADC0_SE11/PTB8, pull_enable: enable}
  - {pin_num: '12', peripheral: GPIOB, signal: 'GPIO, 9', pin_signal: ADC0_SE10/PTB9, pull_enable: enable}
  - {pin_num: '31', peripheral: GPIOA, signal: 'GPIO, 1', pin_signal: PTA1/IRQ_1/LPTMR0_ALT1/TPM_CLKIN0/RESET_b, pull_enable: enable}
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

  const port_pin_config_t porta1_pin31_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA1 */
  };
  PORT_SetPinConfig(PORTA, PIN1_IDX, &porta1_pin31_config);  /* PORTA1 (pin 31) is configured as PTA1 */
  const port_pin_config_t porta8_pin19_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA8 */
  };
  PORT_SetPinConfig(PORTA, PIN8_IDX, &porta8_pin19_config);  /* PORTA8 (pin 19) is configured as PTA8 */
  const port_pin_config_t portb3_pin23_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB3 */
  };
  PORT_SetPinConfig(PORTB, PIN3_IDX, &portb3_pin23_config);  /* PORTB3 (pin 23) is configured as PTB3 */
  const port_pin_config_t portb4_pin24_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB4 */
  };
  PORT_SetPinConfig(PORTB, PIN4_IDX, &portb4_pin24_config);  /* PORTB4 (pin 24) is configured as PTB4 */
  const port_pin_config_t portb8_pin11_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB8 */
  };
  PORT_SetPinConfig(PORTB, PIN8_IDX, &portb8_pin11_config);  /* PORTB8 (pin 11) is configured as PTB8 */
  const port_pin_config_t portb9_pin12_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB9 */
  };
  PORT_SetPinConfig(PORTB, PIN9_IDX, &portb9_pin12_config);  /* PORTB9 (pin 12) is configured as PTB9 */
}



#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */

#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitOSC:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '7', peripheral: OSC0, signal: EXTAL, pin_signal: EXTAL0/PTA3/I2C0_SCL/I2C1_SDA, pull_enable: disable}
  - {pin_num: '8', peripheral: OSC0, signal: XTAL, pin_signal: XTAL0/PTA4/I2C0_SDA/I2C1_SCL, pull_enable: disable}
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

  const port_pin_config_t porta3_pin7_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_PinDisabledOrAnalog,                               /* Pin is configured as EXTAL0 */
  };
  PORT_SetPinConfig(PORTA, PIN3_IDX, &porta3_pin7_config);   /* PORTA3 (pin 7) is configured as EXTAL0 */
  const port_pin_config_t porta4_pin8_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_PinDisabledOrAnalog,                               /* Pin is configured as XTAL0 */
  };
  PORT_SetPinConfig(PORTA, PIN4_IDX, &porta4_pin8_config);   /* PORTA4 (pin 8) is configured as XTAL0 */
}



#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define SOPT5_UART0ODE_DISABLED       0x00u   /*!< UART0 Open Drain Enable: Open drain is disabled on UART0 */
#define SOPT5_UART0RXSRC_UART_RX      0x00u   /*!< UART0 receive data source select: UART0_RX pin */
#define SOPT5_UART0TXSRC_UART_TX      0x00u   /*!< UART0 transmit data source select: UART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UART:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '17', peripheral: UART0, signal: TX, pin_signal: ADC0_SE5/CMP0_IN3/PTB1/IRQ_6/UART0_TX/UART0_RX, direction: OUTPUT, open_drain: disable, drive_strength: low,
    pull_enable: disable}
  - {pin_num: '18', peripheral: UART0, signal: RX, pin_signal: ADC0_SE4/PTB2/IRQ_7/UART0_RX/UART0_TX, pull_enable: disable}
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

  const port_pin_config_t portb1_pin17_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt2,                                           /* Pin is configured as UART0_TX */
  };
  PORT_SetPinConfig(PORTB, PIN1_IDX, &portb1_pin17_config);  /* PORTB1 (pin 17) is configured as UART0_TX */
  const port_pin_config_t portb2_pin18_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt2,                                           /* Pin is configured as UART0_RX */
  };
  PORT_SetPinConfig(PORTB, PIN2_IDX, &portb2_pin18_config);  /* PORTB2 (pin 18) is configured as UART0_RX */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_UART0TXSRC_MASK | SIM_SOPT5_UART0RXSRC_MASK | SIM_SOPT5_UART0ODE_MASK))) /* Mask bits to zero which are setting */
      | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)       /* UART0 transmit data source select: UART0_TX pin */
      | SIM_SOPT5_UART0RXSRC(SOPT5_UART0RXSRC_UART_RX)       /* UART0 receive data source select: UART0_RX pin */
      | SIM_SOPT5_UART0ODE(SOPT5_UART0ODE_DISABLED)          /* UART0 Open Drain Enable: Open drain is disabled on UART0 */
    );
}


#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */
#define PIN10_IDX                       10u   /*!< Pin number for pin 10 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDs:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: GPIOB, signal: 'GPIO, 6', pin_signal: PTB6/IRQ_2/LPTMR0_ALT3/TPM1_CH1/TPM_CLKIN1, direction: OUTPUT, pull_enable: enable}
  - {pin_num: '2', peripheral: GPIOB, signal: 'GPIO, 7', pin_signal: PTB7/IRQ_3/TPM1_CH0, direction: OUTPUT, pull_enable: enable}
  - {pin_num: '13', peripheral: GPIOB, signal: 'GPIO, 10', pin_signal: ADC0_SE9/PTB10/TPM0_CH1, direction: OUTPUT, pull_enable: enable}
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

  const port_pin_config_t portb10_pin13_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB10 */
  };
  PORT_SetPinConfig(PORTB, PIN10_IDX, &portb10_pin13_config); /* PORTB10 (pin 13) is configured as PTB10 */
  const port_pin_config_t portb6_pin1_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB6 */
  };
  PORT_SetPinConfig(PORTB, PIN6_IDX, &portb6_pin1_config);   /* PORTB6 (pin 1) is configured as PTB6 */
  const port_pin_config_t portb7_pin2_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB7 */
  };
  PORT_SetPinConfig(PORTB, PIN7_IDX, &portb7_pin2_config);   /* PORTB7 (pin 2) is configured as PTB7 */
}


#define PIN12_IDX                       12u   /*!< Pin number for pin 12 in a port */
#define PIN13_IDX                       13u   /*!< Pin number for pin 13 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitTOUCH:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '27', peripheral: GPIOA, signal: 'GPIO, 13', pin_signal: PTA13, direction: INPUT, drive_strength: no_init, pull_enable: no_init}
  - {pin_num: '28', peripheral: GPIOB, signal: 'GPIO, 12', pin_signal: PTB12, direction: INPUT, pull_enable: no_init}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitTOUCH
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitTOUCH(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN13_IDX, kPORT_MuxAsGpio);         /* PORTA13 (pin 27) is configured as PTA13 */
  PORT_SetPinMux(PORTB, PIN12_IDX, kPORT_MuxAsGpio);         /* PORTB12 (pin 28) is configured as PTB12 */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
