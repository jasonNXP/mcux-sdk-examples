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

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v6.0
processor: MKE15Z256xxx7
package_id: MKE15Z256VLL7
mcu_data: ksdk2_0
processor_version: 6.0.1
board: FRDM-KE15Z
pin_labels:
- {pin_num: '72', pin_signal: ADC1_SE1/PTA3/LPI2C0_SCL/EWM_IN/LPUART0_TX, label: ACCEL_SCL, identifier: ACCEL_SCL}
- {pin_num: '73', pin_signal: ADC1_SE0/PTA2/LPI2C0_SDA/EWM_OUT_b/LPUART0_RX, label: ACCEL_SDA, identifier: ACCEL_SDA}
- {pin_num: '76', pin_signal: PTB9/LPI2C0_SCLS, label: ACCEL_RESET, identifier: ACCEL_RESET}
- {pin_num: '80', pin_signal: ADC1_SE5/TSI0_CH16/PTC7/LPUART1_TX, label: DEBUG_UART_TX, identifier: DEBUG_UART_TX}
- {pin_num: '81', pin_signal: ADC1_SE4/TSI0_CH15/PTC6/LPUART1_RX, label: DEBUG_UART_RX, identifier: DEBUG_UART_RX}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '81', peripheral: LPUART1, signal: RX, pin_signal: ADC1_SE4/TSI0_CH15/PTC6/LPUART1_RX}
  - {pin_num: '80', peripheral: LPUART1, signal: TX, pin_signal: ADC1_SE5/TSI0_CH16/PTC7/LPUART1_TX}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);

    /* PORTC6 (pin 81) is configured as LPUART1_RX */
    PORT_SetPinMux(BOARD_DEBUG_UART_RX_PORT, BOARD_DEBUG_UART_RX_PIN, kPORT_MuxAlt2);

    /* PORTC7 (pin 80) is configured as LPUART1_TX */
    PORT_SetPinMux(BOARD_DEBUG_UART_TX_PORT, BOARD_DEBUG_UART_TX_PIN, kPORT_MuxAlt2);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'false', prefix: BOARD_I2C_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '72', peripheral: LPI2C0, signal: SCL, pin_signal: ADC1_SE1/PTA3/LPI2C0_SCL/EWM_IN/LPUART0_TX, open_drain: disable, drive_strength: low, pull_select: up,
    pull_enable: enable, passive_filter: disable}
  - {pin_num: '73', peripheral: LPI2C0, signal: SDA, pin_signal: ADC1_SE0/PTA2/LPI2C0_SDA/EWM_OUT_b/LPUART0_RX, open_drain: disable, drive_strength: low, pull_select: up,
    pull_enable: enable, passive_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_I2C_ConfigurePins(void)
{
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);

    const port_pin_config_t ACCEL_SDA = {/* Internal pull-up resistor is enabled */
                                         kPORT_PullUp,
                                         /* Passive filter is disabled */
                                         kPORT_PassiveFilterDisable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as LPI2C0_SDA */
                                         kPORT_MuxAlt3,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTA2 (pin 73) is configured as LPI2C0_SDA */
    PORT_SetPinConfig(BOARD_I2C_ACCEL_SDA_PORT, BOARD_I2C_ACCEL_SDA_PIN, &ACCEL_SDA);

    const port_pin_config_t ACCEL_SCL = {/* Internal pull-up resistor is enabled */
                                         kPORT_PullUp,
                                         /* Passive filter is disabled */
                                         kPORT_PassiveFilterDisable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as LPI2C0_SCL */
                                         kPORT_MuxAlt3,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTA3 (pin 72) is configured as LPI2C0_SCL */
    PORT_SetPinConfig(BOARD_I2C_ACCEL_SCL_PORT, BOARD_I2C_ACCEL_SCL_PIN, &ACCEL_SCL);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_Init_ACCEL_Reset:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '76', peripheral: GPIOB, signal: 'GPIO, 9', pin_signal: PTB9/LPI2C0_SCLS, direction: OUTPUT, gpio_init_state: 'true'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_Init_ACCEL_Reset
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_Init_ACCEL_Reset(void)
{
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);

    gpio_pin_config_t ACCEL_RESET_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB9 (pin 76)  */
    GPIO_PinInit(BOARD_ACCEL_RESET_GPIO, BOARD_ACCEL_RESET_PIN, &ACCEL_RESET_config);

    /* PORTB9 (pin 76) is configured as PTB9 */
    PORT_SetPinMux(BOARD_ACCEL_RESET_PORT, BOARD_ACCEL_RESET_PIN, kPORT_MuxAsGpio);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
