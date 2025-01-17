/*
 * Copyright 2018 NXP
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

#define IOCON_PIO_DIGITAL_EN 0x0100u    /*!<@brief Enables digital function */
#define IOCON_PIO_FUNC1 0x01u           /*!<@brief Selects pin function 1 */
#define IOCON_PIO_FUNC2 0x02u           /*!<@brief Selects pin function 2 */
#define IOCON_PIO_FUNC3 0x03u           /*!<@brief Selects pin function 3 */
#define IOCON_PIO_FUNC5 0x05u           /*!<@brief Selects pin function 5 */
#define IOCON_PIO_I2CDRIVE_HIGH 0x0400u /*!<@brief High drive: 20 mA */
#define IOCON_PIO_I2CFILTER_DI 0x0800u  /*!<@brief I2C 50 ns glitch filter disabled */
#define IOCON_PIO_I2CSLEW_I2C 0x00u     /*!<@brief I2C mode */
#define IOCON_PIO_INPFILT_OFF 0x0200u   /*!<@brief Input filter disabled */
#define IOCON_PIO_INPFILT_ON 0x00u      /*!<@brief Input filter enabled */
#define IOCON_PIO_INV_DI 0x00u          /*!<@brief Input function is not inverted */
#define IOCON_PIO_MODE_INACT 0x00u      /*!<@brief No addition pin function */
#define IOCON_PIO_OPENDRAIN_DI 0x00u    /*!<@brief Open drain is disabled */
#define IOCON_PIO_SLEW_FAST 0x0400u     /*!<@brief Fast mode, slew rate control is disabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u   /*!<@brief Standard mode, output slew rate control is enabled */

/*! @name FC0_RXD_SDA_MOSI (coord B13), U24[13]/P0_29-ISP_FC0_RXD
  @{ */
/* @} */

/*! @name FC0_TXD_SCL_MISO (coord A2), U24[12]/P0_30-ISP_FC0_TXD
  @{ */
/* @} */

/*! @name PDM1_CLK (coord L14), J13[18]/JS25[3]/DMIC1[4]/P1_2-PDM1_CLK
  @{ */
/* @} */

/*! @name PDM1_DATA (coord J13), JS26[3]/DMIC1[1]/P1_3-PDM1_DATA
  @{ */
/* @} */

/*! @name FC7_SCK (coord N10), U10[29]/J9[16]/P2_18-FC7_I2S_RX_SCK
  @{ */
/* @} */

/*! @name FC7_RXD_SDA_MOSI_DATA (coord P12), U10[31]/J9[20]/P2_19-FC7_I2S_RX_DAT
  @{ */
/* @} */

/*! @name FC7_TXD_SCL_MISO_WS (coord P13), U10[30]/J9[18]/P2_20-FC7_I2S_RX_WS
  @{ */
/* @} */

/*! @name MCLK (coord B2), J11[8]/J12[7]/P3_11-MCLK-PMOD2_GPIO
  @{ */
/* @} */

/*! @name FC2_CTS_SDA_SSEL0 (coord C2), J11[10]/J9[3]/U10[3]/J17[5]/U19[10]/P3_23-FC2_SDAX
  @{ */
/* @} */

/*! @name FC2_RTS_SCL_SSEL1 (coord E2), J11[9]/J9[1]/U10[2]/J17[4]/U19[2]/P3_24-FC2_SCLX
  @{ */
/* @} */

/*! @name FC6_SCK (coord G14), U10[29]/J9[14]/P4_1-FC6_I2S_TX_SCK
  @{ */
/* @} */

/*! @name FC6_RXD_SDA_MOSI_DATA (coord F14), U10[32]/J9[10]/P4_2-FC6_I2S_TX_DATA
  @{ */
/* @} */

/*! @name FC6_TXD_SCL_MISO_WS (coord F13), U10[30]/J9[12]/P4_3-FC6_I2S_TX_WS
  @{ */
/* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M4F */

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
