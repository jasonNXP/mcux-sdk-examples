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

#define SOPT5_LPUART0RXSRC_LPUART_RX 0x00u /*!<@brief LPUART0 receive data source select: LPUART0_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX 0x00u /*!<@brief LPUART0 transmit data source select: LPUART0_TX pin */

/*! @name PORTC25 (coord A7), DEBUG_UART_RX
  @{ */
#define BOARD_DEBUG_UART_RX_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_DEBUG_UART_RX_PIN 25U    /*!<@brief PORTC pin index: 25 */
                                       /* @} */

/*! @name PORTC24 (coord B7), DEBUG_UART_TX
  @{ */
#define BOARD_DEBUG_UART_TX_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_DEBUG_UART_TX_PIN 24U    /*!<@brief PORTC pin index: 24 */
                                       /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*! @name PORTC29 (coord B6), ACCEL_SCL
  @{ */
#define BOARD_I2C_ACCEL_SCL_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_I2C_ACCEL_SCL_PIN 29U    /*!<@brief PORTC pin index: 29 */
                                       /* @} */

/*! @name PORTC28 (coord C6), ACCEL_SDA
  @{ */
#define BOARD_I2C_ACCEL_SDA_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_I2C_ACCEL_SDA_PIN 28U    /*!<@brief PORTC pin index: 28 */
                                       /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_I2C_ConfigurePins(void);

/*! @name PORTC29 (coord B6), ACCEL_SCL
  @{ */
#define BOARD_GPIO_ACCEL_SCL_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_GPIO_ACCEL_SCL_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_GPIO_ACCEL_SCL_PIN 29U    /*!<@brief PORTC pin index: 29 */
                                        /* @} */

/*! @name PORTC28 (coord C6), ACCEL_SDA
  @{ */
#define BOARD_GPIO_ACCEL_SDA_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_GPIO_ACCEL_SDA_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_GPIO_ACCEL_SDA_PIN 28U    /*!<@brief PORTC pin index: 28 */
                                        /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_GPIO_ConfigurePins(void);

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