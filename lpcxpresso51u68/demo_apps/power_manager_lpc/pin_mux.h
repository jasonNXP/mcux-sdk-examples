/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

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

/* FC0_RXD_SDA_MOSI (number 31), U18[4]/TO_MUX_P0_0-ISP_RX */
#define BOARD_DEBUG_UART_RX_PERIPHERAL                                 FLEXCOMM0   /*!< Device name: FLEXCOMM0 */
#define BOARD_DEBUG_UART_RX_SIGNAL                                  RXD_SDA_MOSI   /*!< FLEXCOMM0 signal: RXD_SDA_MOSI */
#define BOARD_DEBUG_UART_RX_PIN_NAME                            FC0_RXD_SDA_MOSI   /*!< Pin name */
#define BOARD_DEBUG_UART_RX_LABEL                    "U18[4]/TO_MUX_P0_0-ISP_RX"   /*!< Label */
#define BOARD_DEBUG_UART_RX_NAME                                 "DEBUG_UART_RX"   /*!< Identifier name */

/* FC0_TXD_SCL_MISO (number 32), U6[4]/U22[3]/P0_1-ISP_TX */
#define BOARD_DEBUG_UART_TX_PERIPHERAL                                 FLEXCOMM0   /*!< Device name: FLEXCOMM0 */
#define BOARD_DEBUG_UART_TX_SIGNAL                                  TXD_SCL_MISO   /*!< FLEXCOMM0 signal: TXD_SCL_MISO */
#define BOARD_DEBUG_UART_TX_PIN_NAME                            FC0_TXD_SCL_MISO   /*!< Pin name */
#define BOARD_DEBUG_UART_TX_LABEL                     "U6[4]/U22[3]/P0_1-ISP_TX"   /*!< Label */
#define BOARD_DEBUG_UART_TX_NAME                                 "DEBUG_UART_TX"   /*!< Identifier name */

/* PIO0_24 (number 2), J4[10]/JS2[1]/JS5[3]/U10[5]/U12[E6]/SW1/BRIDGE_SDA-WAKEUP */
#define BOARD_SW1_GPIO                                                      GPIO   /*!< GPIO device name: GPIO */
#define BOARD_SW1_PORT                                                        0U   /*!< PORT device index: 0 */
#define BOARD_SW1_GPIO_PIN                                                   24U   /*!< PIO0 pin index: 24 */
#define BOARD_SW1_PIN_NAME                                               PIO0_24   /*!< Pin name */
#define BOARD_SW1_LABEL "J4[10]/JS2[1]/JS5[3]/U10[5]/U12[E6]/SW1/BRIDGE_SDA-WAKEUP" /*!< Label */
#define BOARD_SW1_NAME                                                     "SW1"   /*!< Identifier name */
#define BOARD_SW1_DIRECTION                              kPIN_MUX_DirectionInput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M0P */

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
