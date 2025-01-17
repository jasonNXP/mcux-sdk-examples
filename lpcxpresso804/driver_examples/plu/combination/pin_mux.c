/*
 * Copyright  2018-2019 NXP
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
product: Pins v4.1
processor: LPC804
package_id: LPC804M101JDH24
mcu_data: ksdk2_0
processor_version: 0.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "fsl_swm.h"
#include "pin_mux.h"
#include "fsl_gpio.h"

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
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '15', peripheral: PLU, signal: CLKIN, pin_signal: PIO0_1/ADC_0/ACMP_I2/CLKIN}
  - {pin_num: '24', peripheral: PLU, signal: 'INPUT, 2', pin_signal: PIO0_19/DACOUT}
  - {pin_num: '13', peripheral: PLU, signal: 'INPUT, 3', pin_signal: PIO0_20}
  - {pin_num: '12', peripheral: PLU, signal: 'INPUT, 4', pin_signal: PIO0_21/ACMP_I5}
  - {pin_num: '23', peripheral: PLU, signal: 'OUT, 0', pin_signal: PIO0_14/ACMP_I3/ADC_2}
  - {pin_num: '14', peripheral: PLU, signal: 'OUT, 1', pin_signal: PIO0_15/ADC_8}
  - {pin_num: '2', peripheral: PLU, signal: 'OUT, 2', pin_signal: PIO0_16/ACMP_I4/ADC_3}
  - {pin_num: '17', peripheral: GPIO, signal: 'PIO0, 8', pin_signal: PIO0_8/ADC_5, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '16', peripheral: GPIO, signal: 'PIO0, 9', pin_signal: PIO0_9/ADC_4, identifier: '', direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '11', peripheral: GPIO, signal: 'PIO0, 10', pin_signal: PIO0_10/ADC_7, identifier: '', direction: OUTPUT, gpio_init_state: 'true'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitPins(void)
{
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t gpio0_pin0_8 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_8 (pin 17)  */
    GPIO_PinInit(GPIO, 0U, 8U, &gpio0_pin0_8);

    gpio_pin_config_t gpio0_pin0_9 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_9 (pin 16)  */
    GPIO_PinInit(GPIO, 0U, 9U, &gpio0_pin0_9);

    gpio_pin_config_t gpio0_pin0_10 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_10 (pin 11)  */
    GPIO_PinInit(GPIO, 0U, 10U, &gpio0_pin0_10);

    gpio_pin_config_t gpio0_pin0_11 = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_11 (pin 10)  */
    GPIO_PinInit(GPIO, 0U, 11U, &gpio0_pin0_11);

    gpio_pin_config_t gpio0_pin0_12 = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_12 (pin 5)  */
    GPIO_PinInit(GPIO, 0U, 12U, &gpio0_pin0_12);

    gpio_pin_config_t gpio0_pin0_13 = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_13 (pin 4)  */
    GPIO_PinInit(GPIO, 0U, 13U, &gpio0_pin0_13);

    /* USART0_TXD connect to P0_4 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_TXD, kSWM_PortPin_P0_4);

    /* USART0_RXD connect to P0_0 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_RXD, kSWM_PortPin_P0_0);

    /* PLU_CLKIN_IN connect to P0_1 */
    SWM_SetMovablePinSelect(SWM0, kSWM_PLU_CLKIN_IN, kSWM_PortPin_P0_1);

    /* PLU_INPUT2 connect to kSWM_PLU_INPUT2_PortPin_P0_19 */
    SWM_SetFixedMovablePinSelect(SWM0, kSWM_PLU_INPUT2, kSWM_PLU_INPUT2_PortPin_P0_19);

    /* PLU_INPUT3 connect to kSWM_PLU_INPUT3_PortPin_P0_20 */
    SWM_SetFixedMovablePinSelect(SWM0, kSWM_PLU_INPUT3, kSWM_PLU_INPUT3_PortPin_P0_20);

    /* PLU_INPUT4 connect to kSWM_PLU_INPUT4_PortPin_P0_21 */
    SWM_SetFixedMovablePinSelect(SWM0, kSWM_PLU_INPUT4, kSWM_PLU_INPUT4_PortPin_P0_21);

    /* PLU_OUT0 connect to kSWM_PLU_OUT0_PortPin_P0_14 */
    SWM_SetFixedMovablePinSelect(SWM0, kSWM_PLU_OUT0, kSWM_PLU_OUT0_PortPin_P0_14);

    /* PLU_OUT1 connect to kSWM_PLU_OUT1_PortPin_P0_15 */
    SWM_SetFixedMovablePinSelect(SWM0, kSWM_PLU_OUT1, kSWM_PLU_OUT1_PortPin_P0_15);

    /* PLU_OUT2 connect to kSWM_PLU_OUT2_PortPin_P0_16 */
    SWM_SetFixedMovablePinSelect(SWM0, kSWM_PLU_OUT2, kSWM_PLU_OUT2_PortPin_P0_16);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '10', peripheral: GPIO, signal: 'PIO0, 11', pin_signal: PIO0_11/ADC_6/WKTCLKIN, direction: OUTPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
  - {pin_num: '5', peripheral: GPIO, signal: 'PIO0, 12', pin_signal: PIO0_12, identifier: LED_GREEN, direction: OUTPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
  - {pin_num: '4', peripheral: GPIO, signal: 'PIO0, 13', pin_signal: PIO0_13/ADC_10, identifier: LED_RED, direction: OUTPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitLEDsPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    GPIO->DIR[0] = ((GPIO->DIR[0] &
                     /* Mask bits to zero which are setting */
                     (~(GPIO_DIR_DIRP_MASK)))

                    /* Selects pin direction for pin PIOm_n (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins
                     * depends on the specific device and package. 0 = input. 1 = output.: 0x3800u */
                    | GPIO_DIR_DIRP(0x3800u));

    const uint32_t IOCON_INDEX_PIO0_11_config = (/* Selects pull-up function */
                                                 IOCON_PIO_MODE_PULLUP |
                                                 /* Enable hysteresis */
                                                 IOCON_PIO_HYS_EN |
                                                 /* Input not invert */
                                                 IOCON_PIO_INV_DI |
                                                 /* Disables Open-drain function */
                                                 IOCON_PIO_OD_DI);
    /* PORT0 PIN11 (coords: ) is configured as  */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_11, IOCON_INDEX_PIO0_11_config);

    const uint32_t IOCON_INDEX_PIO0_12_config = (/* Selects pull-up function */
                                                 IOCON_PIO_MODE_PULLUP |
                                                 /* Enable hysteresis */
                                                 IOCON_PIO_HYS_EN |
                                                 /* Input not invert */
                                                 IOCON_PIO_INV_DI |
                                                 /* Disables Open-drain function */
                                                 IOCON_PIO_OD_DI);
    /* PORT0 PIN12 (coords: ) is configured as  */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_12, IOCON_INDEX_PIO0_12_config);

    const uint32_t IOCON_INDEX_PIO0_13_config = (/* Selects pull-up function */
                                                 IOCON_PIO_MODE_PULLUP |
                                                 /* Enable hysteresis */
                                                 IOCON_PIO_HYS_EN |
                                                 /* Input not invert */
                                                 IOCON_PIO_INV_DI |
                                                 /* Disables Open-drain function */
                                                 IOCON_PIO_OD_DI);
    /* PORT0 PIN13 (coords: ) is configured as  */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_13, IOCON_INDEX_PIO0_13_config);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}
