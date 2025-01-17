/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: LPC51U68
package_id: LPC51U68JBD64
mcu_data: ksdk2_0
processor_version: 0.0.10
board: LPCXpresso51U68
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "pin_mux.h"

/*FUNCTION**********************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 *END**************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

#define PIO00_DIGIMODE_DIGITAL        0x01u   /*!< Select Analog/Digital mode.: Digital mode. */
#define PIO00_FUNC_ALT1               0x01u   /*!< Selects pin function.: Alternative connection 1. */
#define PIO018_DIGIMODE_DIGITAL       0x01u   /*!< Select Analog/Digital mode.: Digital mode. */
#define PIO018_FUNC_ALT1              0x01u   /*!< Selects pin function.: Alternative connection 1. */
#define PIO019_DIGIMODE_DIGITAL       0x01u   /*!< Select Analog/Digital mode.: Digital mode. */
#define PIO019_FUNC_ALT1              0x01u   /*!< Selects pin function.: Alternative connection 1. */
#define PIO01_DIGIMODE_DIGITAL        0x01u   /*!< Select Analog/Digital mode.: Digital mode. */
#define PIO01_FUNC_ALT1               0x01u   /*!< Selects pin function.: Alternative connection 1. */
#define PIO020_DIGIMODE_DIGITAL       0x01u   /*!< Select Analog/Digital mode.: Digital mode. */
#define PIO020_FUNC_ALT1              0x01u   /*!< Selects pin function.: Alternative connection 1. */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI, pin_signal: PIO0_0/FC0_RXD_SDA_MOSI/FC3_CTS_SDA_SSEL0/CTIMER0_CAP0/SCT0_OUT3}
  - {pin_num: '32', peripheral: FLEXCOMM0, signal: TXD_SCL_MISO, pin_signal: PIO0_1/FC0_TXD_SCL_MISO/FC3_RTS_SCL_SSEL1/CTIMER0_CAP1/SCT0_OUT1}
  - {pin_num: '60', peripheral: FLEXCOMM5, signal: RXD_SDA_MOSI, pin_signal: PIO0_20/FC5_RXD_SDA_MOSI/FC0_SCK/CTIMER3_CAP0}
  - {pin_num: '59', peripheral: FLEXCOMM5, signal: SCK, pin_signal: PIO0_19/FC5_SCK/SCT0_OUT1/CTIMER0_MAT1}
  - {pin_num: '58', peripheral: FLEXCOMM5, signal: TXD_SCL_MISO, pin_signal: PIO0_18/FC5_TXD_SCL_MISO/SCT0_OUT0/CTIMER0_MAT0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) { /* Function assigned for the Cortex-M0P */
  CLOCK_EnableClock(kCLOCK_Iocon);                           /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */

  IOCON->PIO[0][0] = ((IOCON->PIO[0][0] &
    (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))      /* Mask bits to zero which are setting */
      | IOCON_PIO_FUNC(PIO00_FUNC_ALT1)                      /* Selects pin function.: PORT00 (pin 31) is configured as FC0_RXD_SDA_MOSI */
      | IOCON_PIO_DIGIMODE(PIO00_DIGIMODE_DIGITAL)           /* Select Analog/Digital mode.: Digital mode. */
    );
  IOCON->PIO[0][1] = ((IOCON->PIO[0][1] &
    (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))      /* Mask bits to zero which are setting */
      | IOCON_PIO_FUNC(PIO01_FUNC_ALT1)                      /* Selects pin function.: PORT01 (pin 32) is configured as FC0_TXD_SCL_MISO */
      | IOCON_PIO_DIGIMODE(PIO01_DIGIMODE_DIGITAL)           /* Select Analog/Digital mode.: Digital mode. */
    );
  IOCON->PIO[0][18] = ((IOCON->PIO[0][18] &
    (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))      /* Mask bits to zero which are setting */
      | IOCON_PIO_FUNC(PIO018_FUNC_ALT1)                     /* Selects pin function.: PORT018 (pin 58) is configured as FC5_TXD_SCL_MISO */
      | IOCON_PIO_DIGIMODE(PIO018_DIGIMODE_DIGITAL)          /* Select Analog/Digital mode.: Digital mode. */
    );
  IOCON->PIO[0][19] = ((IOCON->PIO[0][19] &
    (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))      /* Mask bits to zero which are setting */
      | IOCON_PIO_FUNC(PIO019_FUNC_ALT1)                     /* Selects pin function.: PORT019 (pin 59) is configured as FC5_SCK */
      | IOCON_PIO_DIGIMODE(PIO019_DIGIMODE_DIGITAL)          /* Select Analog/Digital mode.: Digital mode. */
    );
  IOCON->PIO[0][20] = ((IOCON->PIO[0][20] &
    (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))      /* Mask bits to zero which are setting */
      | IOCON_PIO_FUNC(PIO020_FUNC_ALT1)                     /* Selects pin function.: PORT020 (pin 60) is configured as FC5_RXD_SDA_MOSI */
      | IOCON_PIO_DIGIMODE(PIO020_DIGIMODE_DIGITAL)          /* Select Analog/Digital mode.: Digital mode. */
    );
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
