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
processor: MKE02Z64xxx4
package_id: MKE02Z64VQH4
mcu_data: ksdk2_0
processor_version: 6.0.1
board: FRDM-KE02Z40M
pin_labels:
- {pin_num: '14', pin_signal: PTH1/FTM2_CH1, label: 'D4[1]/LEDRGB_RED', identifier: PTH1_RED;LED_RED}
- {pin_num: '49', pin_signal: PTA1/KBI0_P1/FTM0_CH1/ACMP0_IN1/ADC0_SE1, label: 'J1[10]/PTA1_D4_T1/PTA1_IRRX/PTA1_D4_T1', identifier: USER_LED}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
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
  - {pin_num: '14', peripheral: GPIOB, signal: 'GPIO, 25', pin_signal: PTH1/FTM2_CH1, identifier: LED_RED, direction: OUTPUT}
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

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB25 (pin 14) */
    GPIO_PinInit(BOARD_LED_RED_GPIO_PORT, BOARD_LED_RED_PIN, &LED_RED_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/