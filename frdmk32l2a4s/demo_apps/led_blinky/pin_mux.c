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
processor: K32L2A41xxxxA
package_id: K32L2A41VLL1A
mcu_data: ksdk2_0
processor_version: 0.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
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
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '26', peripheral: GPIOE, signal: 'GPIO, 29', pin_signal: CMP1_IN5/CMP0_IN5/ADC0_SE4b/PTE29/EMVSIM0_CLK/TPM0_CH2/TPM0_CLKIN}
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
    /* Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTE29 (pin 26) is configured as PTE29 */
    PORT_SetPinMux(PORTE, 29U, kPORT_MuxAsGpio);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
