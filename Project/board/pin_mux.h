#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* PORTA1 (number 31), J1[10]/J9[3]/SW1/RST */
#define BOARD_SW1_GPIO                                                     GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_SW1_PORT                                                     PORTA   /*!< PORT device name: PORTA */
#define BOARD_SW1_GPIO_PIN                                                    1U   /*!< PORTA pin index: 1 */
#define BOARD_SW1_PIN_NAME                                                  PTA1   /*!< Pin name */
#define BOARD_SW1_LABEL                                   "J1[10]/J9[3]/SW1/RST"   /*!< Label */
#define BOARD_SW1_NAME                                                     "SW1"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/* PORTA3 (number 7), EXTAL */
#define BOARD_EXTAL0_PERIPHERAL                                             OSC0   /*!< Device name: OSC0 */
#define BOARD_EXTAL0_SIGNAL                                                EXTAL   /*!< OSC0 signal: EXTAL */
#define BOARD_EXTAL0_PIN_NAME                                             EXTAL0   /*!< Pin name */
#define BOARD_EXTAL0_LABEL                                               "EXTAL"   /*!< Label */
#define BOARD_EXTAL0_NAME                                               "EXTAL0"   /*!< Identifier name */

/* PORTA4 (number 8), XTAL */
#define BOARD_XTAL0_PERIPHERAL                                              OSC0   /*!< Device name: OSC0 */
#define BOARD_XTAL0_SIGNAL                                                  XTAL   /*!< OSC0 signal: XTAL */
#define BOARD_XTAL0_PIN_NAME                                               XTAL0   /*!< Pin name */
#define BOARD_XTAL0_LABEL                                                 "XTAL"   /*!< Label */
#define BOARD_XTAL0_NAME                                                 "XTAL0"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitOSC(void);

/* PORTB1 (number 17), J8[2]/ADC0_SE5/CMP0_IN3/UART0_TX/UART0_RX */
#define BOARD_DEBUG_UART0_TX_PERIPHERAL                                    UART0   /*!< Device name: UART0 */
#define BOARD_DEBUG_UART0_TX_SIGNAL                                           TX   /*!< UART0 signal: TX */
#define BOARD_DEBUG_UART0_TX_PIN_NAME                                   UART0_TX   /*!< Pin name */
#define BOARD_DEBUG_UART0_TX_LABEL   "J8[2]/ADC0_SE5/CMP0_IN3/UART0_TX/UART0_RX"   /*!< Label */
#define BOARD_DEBUG_UART0_TX_NAME                               "DEBUG_UART0_TX"   /*!< Identifier name */
#define BOARD_DEBUG_UART0_TX_DIRECTION                  kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB2 (number 18), J8[1]/ADC0_SE4/UART0_RX/UART0_TX */
#define BOARD_DEBUG_UART0_RX_PERIPHERAL                                    UART0   /*!< Device name: UART0 */
#define BOARD_DEBUG_UART0_RX_SIGNAL                                           RX   /*!< UART0 signal: RX */
#define BOARD_DEBUG_UART0_RX_PIN_NAME                                   UART0_RX   /*!< Pin name */
#define BOARD_DEBUG_UART0_RX_LABEL            "J8[1]/ADC0_SE4/UART0_RX/UART0_TX"   /*!< Label */
#define BOARD_DEBUG_UART0_RX_NAME                               "DEBUG_UART0_RX"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UART(void);

/* PORTB6 (number 1), J8[7]/LEDRGB_RED/LPTMR0_ALT3 */
#define BOARD_LED_RED_GPIO                                                 GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_RED_PORT                                                 PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_RED_GPIO_PIN                                                6U   /*!< PORTB pin index: 6 */
#define BOARD_LED_RED_PIN_NAME                                              PTB6   /*!< Pin name */
#define BOARD_LED_RED_LABEL                       "J8[7]/LEDRGB_RED/LPTMR0_ALT3"   /*!< Label */
#define BOARD_LED_RED_NAME                                             "LED_RED"   /*!< Identifier name */
#define BOARD_LED_RED_DIRECTION                         kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB7 (number 2), J8[8]/LEDRGB_GREEN */
#define BOARD_LED_GREEN_GPIO                                               GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_GREEN_PORT                                               PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_GREEN_GPIO_PIN                                              7U   /*!< PORTB pin index: 7 */
#define BOARD_LED_GREEN_PIN_NAME                                            PTB7   /*!< Pin name */
#define BOARD_LED_GREEN_LABEL                               "J8[8]/LEDRGB_GREEN"   /*!< Label */
#define BOARD_LED_GREEN_NAME                                         "LED_GREEN"   /*!< Identifier name */
#define BOARD_LED_GREEN_DIRECTION                       kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB10 (number 13), J7[1]/LEDRGB_BLUE/ADC0_SE9 */
#define BOARD_LED_BLUE_GPIO                                                GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_BLUE_PORT                                                PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_BLUE_GPIO_PIN                                              10U   /*!< PORTB pin index: 10 */
#define BOARD_LED_BLUE_PIN_NAME                                            PTB10   /*!< Pin name */
#define BOARD_LED_BLUE_LABEL                        "J7[1]/LEDRGB_BLUE/ADC0_SE9"   /*!< Label */
#define BOARD_LED_BLUE_NAME                                           "LED_BLUE"   /*!< Identifier name */
#define BOARD_LED_BLUE_DIRECTION                        kPIN_MUX_DirectionOutput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDs(void);

/* PORTA13 (number 27), E1/TOUCH */
#define BOARD_TOUCH_1_GPIO                                                 GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_TOUCH_1_PORT                                                 PORTA   /*!< PORT device name: PORTA */
#define BOARD_TOUCH_1_GPIO_PIN                                               13U   /*!< PORTA pin index: 13 */
#define BOARD_TOUCH_1_PIN_NAME                                             PTA13   /*!< Pin name */
#define BOARD_TOUCH_1_LABEL                                           "E1/TOUCH"   /*!< Label */
#define BOARD_TOUCH_1_NAME                                             "TOUCH_1"   /*!< Identifier name */
#define BOARD_TOUCH_1_DIRECTION                          kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTB12 (number 28), E1/TOUCH */
#define BOARD_TOUCH_2_GPIO                                                 GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_TOUCH_2_PORT                                                 PORTB   /*!< PORT device name: PORTB */
#define BOARD_TOUCH_2_GPIO_PIN                                               12U   /*!< PORTB pin index: 12 */
#define BOARD_TOUCH_2_PIN_NAME                                             PTB12   /*!< Pin name */
#define BOARD_TOUCH_2_LABEL                                           "E1/TOUCH"   /*!< Label */
#define BOARD_TOUCH_2_NAME                                             "TOUCH_2"   /*!< Identifier name */
#define BOARD_TOUCH_2_DIRECTION                          kPIN_MUX_DirectionInput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTOUCH(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
