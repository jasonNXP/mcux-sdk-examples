/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*! @name PORTC6 (number 81), UART1_RX_TGTMCU
  @{ */
#define BOARD_DEBUG_UART_RX_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_DEBUG_UART_RX_PIN 6U     /*!<@brief PORTC pin index: 6 */
                                       /* @} */

/*! @name PORTC7 (number 80), UART1_TX_TGTMCU
  @{ */
#define BOARD_DEBUG_UART_TX_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_DEBUG_UART_TX_PIN 7U     /*!<@brief PORTC pin index: 7 */
                                       /* @} */

/*! @name PORTA3 (number 72), J4[12]/Arduino_A5_ADC1_SE1/FXOS_SCL
  @{ */
#define BOARD_ACCEL_I2C_SCL_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_ACCEL_I2C_SCL_PIN 3U     /*!<@brief PORTA pin index: 3 */
                                       /* @} */

/*! @name PORTA2 (number 73), J4[10]/Arduino_A4_ADC1_SE0/FXOS_SDA
  @{ */
#define BOARD_ACCEL_I2C_SDA_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_ACCEL_I2C_SDA_PIN 2U     /*!<@brief PORTA pin index: 2 */
                                       /* @} */

/*! @name PORTB9 (number 76), U1[3]/FXOS_RST
  @{ */
#define BOARD_ACCEL_RST_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_ACCEL_RST_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_ACCEL_RST_PIN 9U     /*!<@brief PORTB pin index: 9 */
                                   /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
