/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v8.0
processor: MIMXRT1024xxxxx
package_id: MIMXRT1024DAG5A
mcu_data: ksdk2_0
processor_version: 0.0.0
board: MIMXRT1024-EVK
pin_labels:
- {pin_num: '106', pin_signal: GPIO_AD_B0_05, label: 'JTAG_nTRST/J16[3]/USER_LED/J17[5]', identifier: USER_LED}
- {pin_num: '96', pin_signal: GPIO_AD_B0_12, label: 'U8[6]/I2C0_SDA', identifier: ACCEL_I2C_SDA}
- {pin_num: '95', pin_signal: GPIO_AD_B0_13, label: 'U8[4]/I2C0_SCL', identifier: ACCEL_I2C_SCL}
- {pin_num: '30', pin_signal: GPIO_SD_B1_02, label: I2C4_SCL, identifier: I2C4_SCL}
- {pin_num: '28', pin_signal: GPIO_SD_B1_03, label: I2C4_SDA, identifier: I2C4_SDA}
power_domains: {NVCC_GPIO: '3.3'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
    BOARD_I2C_ConfigurePins();

/* GPIO_AD_B1_00~GPIO_AD_B1_05 can only be configured as flexspi function. Note that it can't be modified here */
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_FLEXSPI_A_DATA03,1U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_FLEXSPI_A_SCLK,1U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_FLEXSPI_A_DATA00,1U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_FLEXSPI_A_DATA02,1U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_FLEXSPI_A_DATA01,1U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_FLEXSPI_A_SS0_B,1U);
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '101', peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_07, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100,
    drive_strength: R0_6, pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: '105', peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_06, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100,
    drive_strength: R0_6, pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: '82', peripheral: GPIO1, signal: 'gpio_io, 24', pin_signal: GPIO_AD_B1_08, direction: OUTPUT, slew_rate: Slow, software_input_on: Disable, open_drain: Disable,
    speed: MHZ_100, drive_strength: R0_6, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03U */

  /* GPIO configuration on GPIO_AD_B1_08 (pin 82) */
  gpio_pin_config_t gpio1_pin82_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_B1_08 (pin 82) */
  GPIO_PinInit(GPIO1, 24U, &gpio1_pin82_config);

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_06_LPUART1_TX,        /* GPIO_AD_B0_06 is configured as LPUART1_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_07_LPUART1_RX,        /* GPIO_AD_B0_07 is configured as LPUART1_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_08_GPIO1_IO24,        /* GPIO_AD_B1_08 is configured as GPIO1_IO24 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_06_LPUART1_TX,        /* GPIO_AD_B0_06 PAD functional properties : */
      0x10B0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_07_LPUART1_RX,        /* GPIO_AD_B0_07 PAD functional properties : */
      0x10B0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B1_08_GPIO1_IO24,        /* GPIO_AD_B1_08 PAD functional properties : */
      0x10B0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '30', peripheral: LPI2C4, signal: SCL, pin_signal: GPIO_SD_B1_02, slew_rate: Slow, software_input_on: Enable, open_drain: Enable, speed: MHZ_100, drive_strength: R0_6,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Up_22K_Ohm, hysteresis_enable: Disable}
  - {pin_num: '28', peripheral: LPI2C4, signal: SDA, pin_signal: GPIO_SD_B1_03, slew_rate: Slow, software_input_on: Enable, open_drain: Enable, speed: MHZ_100, drive_strength: R0_6,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Up_22K_Ohm, hysteresis_enable: Disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_I2C_ConfigurePins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03U */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_02_LPI2C4_SCL,        /* GPIO_SD_B1_02 is configured as LPI2C4_SCL */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_02 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_03_LPI2C4_SDA,        /* GPIO_SD_B1_03 is configured as LPI2C4_SDA */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_03 */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_02_LPI2C4_SCL,        /* GPIO_SD_B1_02 PAD functional properties : */
      0xD8B0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Enabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_03_LPI2C4_SDA,        /* GPIO_SD_B1_03 PAD functional properties : */
      0xD8B0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Enabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
