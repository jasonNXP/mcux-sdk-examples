/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MKE15Z256xxx7
package_id: MKE15Z256VLL7
mcu_data: ksdk2_0
processor_version: 0.0.9
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"



/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '81', peripheral: LPUART1, signal: RX, pin_signal: ADC1_SE4/TSI0_CH15/PTC6/LPUART1_RX}
  - {pin_num: '80', peripheral: LPUART1, signal: TX, pin_signal: ADC1_SE5/TSI0_CH16/PTC7/LPUART1_TX}
  - {pin_num: '4', peripheral: FTM0, signal: 'CH, 2', pin_signal: TSI0_CH4/PTD0/FTM0_CH2/LPSPI1_SCK/FTM2_CH0/FXIO_D0/TRGMUX_OUT1}
  - {pin_num: '21', peripheral: FTM0, signal: 'CH, 1', pin_signal: PTD16/FTM0_CH1}
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
    /* Clock Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Clock Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortD);

    /* PORTC6 (pin 81) is configured as LPUART1_RX */
    PORT_SetPinMux(PORTC, 6U, kPORT_MuxAlt2);

    /* PORTC7 (pin 80) is configured as LPUART1_TX */
    PORT_SetPinMux(PORTC, 7U, kPORT_MuxAlt2);

    /* PORTD0 (pin 4) is configured as FTM0_CH2 */
    PORT_SetPinMux(PORTD, 0U, kPORT_MuxAlt2);

    /* PORTD16 (pin 21) is configured as FTM0_CH1 */
    PORT_SetPinMux(PORTD, 16U, kPORT_MuxAlt2);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
