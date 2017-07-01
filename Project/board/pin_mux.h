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

/* PORTE0 (number 1), J15[P8]/SDHC0_D1 */
#define BOARD_SDHC0_D1_PERIPHERAL                                            RTC   /*!< Device name: RTC */
#define BOARD_SDHC0_D1_SIGNAL                                             CLKOUT   /*!< RTC signal: CLKOUT */
#define BOARD_SDHC0_D1_PIN_NAME                                       RTC_CLKOUT   /*!< Pin name */
#define BOARD_SDHC0_D1_LABEL                                  "J15[P8]/SDHC0_D1"   /*!< Label */
#define BOARD_SDHC0_D1_NAME                                           "SDHC0_D1"   /*!< Identifier name */

/* PORTA14 (number 44), U13[15]/RMII0_CRS_DV */
#define BOARD_RMII0_CRS_DV_PERIPHERAL                                       SPI0   /*!< Device name: SPI0 */
#define BOARD_RMII0_CRS_DV_SIGNAL                                        PCS0_SS   /*!< SPI0 signal: PCS0_SS */
#define BOARD_RMII0_CRS_DV_PIN_NAME                                    SPI0_PCS0   /*!< Pin name */
#define BOARD_RMII0_CRS_DV_LABEL                          "U13[15]/RMII0_CRS_DV"   /*!< Label */
#define BOARD_RMII0_CRS_DV_NAME                                   "RMII0_CRS_DV"   /*!< Identifier name */

/* PORTA17 (number 47), U13[21]/RMII0_TXD1 */
#define BOARD_RMII0_TXD1_PERIPHERAL                                         SPI0   /*!< Device name: SPI0 */
#define BOARD_RMII0_TXD1_SIGNAL                                              SIN   /*!< SPI0 signal: SIN */
#define BOARD_RMII0_TXD1_PIN_NAME                                       SPI0_SIN   /*!< Pin name */
#define BOARD_RMII0_TXD1_LABEL                              "U13[21]/RMII0_TXD1"   /*!< Label */
#define BOARD_RMII0_TXD1_NAME                                       "RMII0_TXD1"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/* PORTC6 (number 78), U8[11]/SW2 */
#define BOARD_SW2_GPIO                                                     GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_SW2_PORT                                                     PORTC   /*!< PORT device name: PORTC */
#define BOARD_SW2_GPIO_PIN                                                    6U   /*!< PORTC pin index: 6 */
#define BOARD_SW2_PIN_NAME                                                  PTC6   /*!< Pin name */
#define BOARD_SW2_LABEL                                             "U8[11]/SW2"   /*!< Label */
#define BOARD_SW2_NAME                                                     "SW2"   /*!< Identifier name */
#define BOARD_SW2_DIRECTION                              kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTA4 (number 38), SW3 */
#define BOARD_SW3_GPIO                                                     GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_SW3_PORT                                                     PORTA   /*!< PORT device name: PORTA */
#define BOARD_SW3_GPIO_PIN                                                    4U   /*!< PORTA pin index: 4 */
#define BOARD_SW3_PIN_NAME                                                  PTA4   /*!< Pin name */
#define BOARD_SW3_LABEL                                                    "SW3"   /*!< Label */
#define BOARD_SW3_NAME                                                     "SW3"   /*!< Identifier name */
#define BOARD_SW3_DIRECTION                              kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTD2 (number 95), J2[8] */
#define BOARD_UART2_RX_GPIO                                                GPIOD   /*!< GPIO device name: GPIOD */
#define BOARD_UART2_RX_PORT                                                PORTD   /*!< PORT device name: PORTD */
#define BOARD_UART2_RX_GPIO_PIN                                               2U   /*!< PORTD pin index: 2 */
#define BOARD_UART2_RX_PIN_NAME                                             PTD2   /*!< Pin name */
#define BOARD_UART2_RX_LABEL                                             "J2[8]"   /*!< Label */
#define BOARD_UART2_RX_NAME                                           "UART2_RX"   /*!< Identifier name */

/* PORTD3 (number 96), J2[10] */
#define BOARD_UART2_TX_GPIO                                                GPIOD   /*!< GPIO device name: GPIOD */
#define BOARD_UART2_TX_PORT                                                PORTD   /*!< PORT device name: PORTD */
#define BOARD_UART2_TX_GPIO_PIN                                               3U   /*!< PORTD pin index: 3 */
#define BOARD_UART2_TX_PIN_NAME                                             PTD3   /*!< Pin name */
#define BOARD_UART2_TX_LABEL                                            "J2[10]"   /*!< Label */
#define BOARD_UART2_TX_NAME                                           "UART2_TX"   /*!< Identifier name */

/* PORTD4 (number 97), J6[4]/RF_WIFI_CS */
#define BOARD_WIFI_CS_GPIO                                                 GPIOD   /*!< GPIO device name: GPIOD */
#define BOARD_WIFI_CS_PORT                                                 PORTD   /*!< PORT device name: PORTD */
#define BOARD_WIFI_CS_GPIO_PIN                                                4U   /*!< PORTD pin index: 4 */
#define BOARD_WIFI_CS_PIN_NAME                                              PTD4   /*!< Pin name */
#define BOARD_WIFI_CS_LABEL                                   "J6[4]/RF_WIFI_CS"   /*!< Label */
#define BOARD_WIFI_CS_NAME                                             "WIFI_CS"   /*!< Identifier name */

/* PORTD5 (number 98), J6[5]/RF_WIFI_SCK */
#define BOARD_WIFI_SCK_GPIO                                                GPIOD   /*!< GPIO device name: GPIOD */
#define BOARD_WIFI_SCK_PORT                                                PORTD   /*!< PORT device name: PORTD */
#define BOARD_WIFI_SCK_GPIO_PIN                                               5U   /*!< PORTD pin index: 5 */
#define BOARD_WIFI_SCK_PIN_NAME                                             PTD5   /*!< Pin name */
#define BOARD_WIFI_SCK_LABEL                                 "J6[5]/RF_WIFI_SCK"   /*!< Label */
#define BOARD_WIFI_SCK_NAME                                           "WIFI_SCK"   /*!< Identifier name */

/* PORTD6 (number 99), J6[6]/RF_WIFI_MOSI */
#define BOARD_WIFI_MOSI_GPIO                                               GPIOD   /*!< GPIO device name: GPIOD */
#define BOARD_WIFI_MOSI_PORT                                               PORTD   /*!< PORT device name: PORTD */
#define BOARD_WIFI_MOSI_GPIO_PIN                                              6U   /*!< PORTD pin index: 6 */
#define BOARD_WIFI_MOSI_PIN_NAME                                            PTD6   /*!< Pin name */
#define BOARD_WIFI_MOSI_LABEL                               "J6[6]/RF_WIFI_MOSI"   /*!< Label */
#define BOARD_WIFI_MOSI_NAME                                         "WIFI_MOSI"   /*!< Identifier name */

/* PORTD7 (number 100), J6[7]/RF_WIFI_MISO */
#define BOARD_WIFI_MISO_GPIO                                               GPIOD   /*!< GPIO device name: GPIOD */
#define BOARD_WIFI_MISO_PORT                                               PORTD   /*!< PORT device name: PORTD */
#define BOARD_WIFI_MISO_GPIO_PIN                                              7U   /*!< PORTD pin index: 7 */
#define BOARD_WIFI_MISO_PIN_NAME                                            PTD7   /*!< Pin name */
#define BOARD_WIFI_MISO_LABEL                               "J6[7]/RF_WIFI_MISO"   /*!< Label */
#define BOARD_WIFI_MISO_NAME                                         "WIFI_MISO"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitButtons(void);

/* PORTB21 (number 67), D12[3]/LEDRGB_BLUE */
#define BOARD_LED_BLUE_GPIO                                                GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_BLUE_PORT                                                PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_BLUE_GPIO_PIN                                              21U   /*!< PORTB pin index: 21 */
#define BOARD_LED_BLUE_PIN_NAME                                            PTB21   /*!< Pin name */
#define BOARD_LED_BLUE_LABEL                                "D12[3]/LEDRGB_BLUE"   /*!< Label */
#define BOARD_LED_BLUE_NAME                                           "LED_BLUE"   /*!< Identifier name */
#define BOARD_LED_BLUE_DIRECTION                        kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB22 (number 68), D12[1]/LEDRGB_RED */
#define BOARD_LED_RED_GPIO                                                 GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_RED_PORT                                                 PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_RED_GPIO_PIN                                               22U   /*!< PORTB pin index: 22 */
#define BOARD_LED_RED_PIN_NAME                                             PTB22   /*!< Pin name */
#define BOARD_LED_RED_LABEL                                  "D12[1]/LEDRGB_RED"   /*!< Label */
#define BOARD_LED_RED_NAME                                             "LED_RED"   /*!< Identifier name */
#define BOARD_LED_RED_DIRECTION                         kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTE26 (number 33), J2[1]/D12[4]/LEDRGB_GREEN */
#define BOARD_LED_GREEN_GPIO                                               GPIOE   /*!< GPIO device name: GPIOE */
#define BOARD_LED_GREEN_PORT                                               PORTE   /*!< PORT device name: PORTE */
#define BOARD_LED_GREEN_GPIO_PIN                                             26U   /*!< PORTE pin index: 26 */
#define BOARD_LED_GREEN_PIN_NAME                                           PTE26   /*!< Pin name */
#define BOARD_LED_GREEN_LABEL                        "J2[1]/D12[4]/LEDRGB_GREEN"   /*!< Label */
#define BOARD_LED_GREEN_NAME                                         "LED_GREEN"   /*!< Identifier name */
#define BOARD_LED_GREEN_DIRECTION                       kPIN_MUX_DirectionOutput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDs(void);

/* PORTB17 (number 63), U10[1]/UART0_TX */
#define BOARD_DEBUG_UART_TX_PERIPHERAL                                     UART0   /*!< Device name: UART0 */
#define BOARD_DEBUG_UART_TX_SIGNAL                                            TX   /*!< UART0 signal: TX */
#define BOARD_DEBUG_UART_TX_PIN_NAME                                    UART0_TX   /*!< Pin name */
#define BOARD_DEBUG_UART_TX_LABEL                              "U10[1]/UART0_TX"   /*!< Label */
#define BOARD_DEBUG_UART_TX_NAME                                 "DEBUG_UART_TX"   /*!< Identifier name */
#define BOARD_DEBUG_UART_TX_DIRECTION                   kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB16 (number 62), U7[4]/UART0_RX */
#define BOARD_DEBUG_UART_RX_PERIPHERAL                                     UART0   /*!< Device name: UART0 */
#define BOARD_DEBUG_UART_RX_SIGNAL                                            RX   /*!< UART0 signal: RX */
#define BOARD_DEBUG_UART_RX_PIN_NAME                                    UART0_RX   /*!< Pin name */
#define BOARD_DEBUG_UART_RX_LABEL                               "U7[4]/UART0_RX"   /*!< Label */
#define BOARD_DEBUG_UART_RX_NAME                                 "DEBUG_UART_RX"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UART(void);

/* PORTA18 (number 50), U13[16]/RMII_RXCLK */
#define BOARD_EXTAL0_PERIPHERAL                                              OSC   /*!< Device name: OSC */
#define BOARD_EXTAL0_SIGNAL                                               EXTAL0   /*!< OSC signal: EXTAL0 */
#define BOARD_EXTAL0_PIN_NAME                                             EXTAL0   /*!< Pin name */
#define BOARD_EXTAL0_LABEL                                  "U13[16]/RMII_RXCLK"   /*!< Label */
#define BOARD_EXTAL0_NAME                                               "EXTAL0"   /*!< Identifier name */

/* EXTAL32 (number 29), Y3[2]/EXTAL32_RTC */
#define BOARD_ETAL32K_PERIPHERAL                                             RTC   /*!< Device name: RTC */
#define BOARD_ETAL32K_SIGNAL                                             EXTAL32   /*!< RTC signal: EXTAL32 */
#define BOARD_ETAL32K_PIN_NAME                                           EXTAL32   /*!< Pin name */
#define BOARD_ETAL32K_LABEL                                  "Y3[2]/EXTAL32_RTC"   /*!< Label */
#define BOARD_ETAL32K_NAME                                             "ETAL32K"   /*!< Identifier name */

/* XTAL32 (number 28), Y3[1]/XTAL32_RTC */
#define BOARD_XTAL32K_PERIPHERAL                                             RTC   /*!< Device name: RTC */
#define BOARD_XTAL32K_SIGNAL                                              XTAL32   /*!< RTC signal: XTAL32 */
#define BOARD_XTAL32K_PIN_NAME                                            XTAL32   /*!< Pin name */
#define BOARD_XTAL32K_LABEL                                   "Y3[1]/XTAL32_RTC"   /*!< Label */
#define BOARD_XTAL32K_NAME                                             "XTAL32K"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitOSC(void);

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
