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
product: Pins v7.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 0.0.1
board: FRDM-K64F
pin_labels:
- {pin_num: '32', pin_signal: ADC0_SE18/PTE25/UART4_RX/I2C0_SDA/EWM_IN, label: 'J2[18]/U8[6]/I2C0_SDA', identifier: ACCEL_SDA}
- {pin_num: '31', pin_signal: ADC0_SE17/PTE24/UART4_TX/I2C0_SCL/EWM_OUT_b, label: 'J2[20]/U8[4]/I2C0_SCL', identifier: ACCEL_SCL}
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
  - {pin_num: '62', peripheral: UART0, signal: RX, pin_signal: PTB16/SPI1_SOUT/UART0_RX/FTM_CLKIN0/FB_AD17/EWM_IN}
  - {pin_num: '63', peripheral: UART0, signal: TX, pin_signal: PTB17/SPI1_SIN/UART0_TX/FTM_CLKIN1/FB_AD16/EWM_OUT_b}
  - {pin_num: '36', peripheral: TPIU, signal: SWO, pin_signal: PTA2/UART0_TX/FTM0_CH7/JTAG_TDO/TRACE_SWO/EZP_DO, drive_strength: low, pull_select: down, pull_enable: disable}
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
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);

    /* PORTA2 (pin 36) is configured as TRACE_SWO */
    PORT_SetPinMux(PORTA, 2U, kPORT_MuxAlt7);

    PORTA->PCR[2] = ((PORTA->PCR[2] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pulldown resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | PORT_PCR_PS(kPORT_PullDown)

                     /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
                     | PORT_PCR_PE(kPORT_PullDisable)

                     /* Drive Strength Enable: Low drive strength is configured on the corresponding pin, if pin
                      * is configured as a digital output. */
                     | PORT_PCR_DSE(kPORT_LowDriveStrength));

    /* PORTB16 (pin 62) is configured as UART0_RX */
    PORT_SetPinMux(BOARD_DEBUG_UART_RX_PORT, BOARD_DEBUG_UART_RX_PIN, kPORT_MuxAlt3);

    /* PORTB17 (pin 63) is configured as UART0_TX */
    PORT_SetPinMux(BOARD_DEBUG_UART_TX_PORT, BOARD_DEBUG_UART_TX_PIN, kPORT_MuxAlt3);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART0TXSRC_MASK)))

                  /* UART 0 transmit data source select: UART0_TX pin. */
                  | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'false', prefix: BOARD_I2C_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: I2C0, signal: SCL, pin_signal: ADC0_SE17/PTE24/UART4_TX/I2C0_SCL/EWM_OUT_b, slew_rate: fast, open_drain: enable, drive_strength: low,
    pull_select: up, pull_enable: enable, passive_filter: enable}
  - {pin_num: '32', peripheral: I2C0, signal: SDA, pin_signal: ADC0_SE18/PTE25/UART4_RX/I2C0_SDA/EWM_IN, slew_rate: fast, open_drain: enable, drive_strength: low,
    pull_select: up, pull_enable: enable, passive_filter: enable}
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
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    const port_pin_config_t ACCEL_SCL = {/* Internal pull-up resistor is enabled */
                                         kPORT_PullUp,
                                         /* Fast slew rate is configured */
                                         kPORT_FastSlewRate,
                                         /* Passive filter is enabled */
                                         kPORT_PassiveFilterEnable,
                                         /* Open drain is enabled */
                                         kPORT_OpenDrainEnable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as I2C0_SCL */
                                         kPORT_MuxAlt5,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTE24 (pin 31) is configured as I2C0_SCL */
    PORT_SetPinConfig(BOARD_I2C_ACCEL_SCL_PORT, BOARD_I2C_ACCEL_SCL_PIN, &ACCEL_SCL);

    const port_pin_config_t ACCEL_SDA = {/* Internal pull-up resistor is enabled */
                                         kPORT_PullUp,
                                         /* Fast slew rate is configured */
                                         kPORT_FastSlewRate,
                                         /* Passive filter is enabled */
                                         kPORT_PassiveFilterEnable,
                                         /* Open drain is enabled */
                                         kPORT_OpenDrainEnable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as I2C0_SDA */
                                         kPORT_MuxAlt5,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTE25 (pin 32) is configured as I2C0_SDA */
    PORT_SetPinConfig(BOARD_I2C_ACCEL_SDA_PORT, BOARD_I2C_ACCEL_SDA_PIN, &ACCEL_SDA);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_GPIO_ConfigurePins:
- options: {callFromInitBoot: 'false', prefix: BOARD_GPIO_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: GPIOE, signal: 'GPIO, 24', pin_signal: ADC0_SE17/PTE24/UART4_TX/I2C0_SCL/EWM_OUT_b, direction: OUTPUT}
  - {pin_num: '32', peripheral: GPIOE, signal: 'GPIO, 25', pin_signal: ADC0_SE18/PTE25/UART4_RX/I2C0_SDA/EWM_IN, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_GPIO_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_GPIO_ConfigurePins(void)
{
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t ACCEL_SCL_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE24 (pin 31)  */
    GPIO_PinInit(BOARD_GPIO_ACCEL_SCL_GPIO, BOARD_GPIO_ACCEL_SCL_PIN, &ACCEL_SCL_config);

    gpio_pin_config_t ACCEL_SDA_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE25 (pin 32)  */
    GPIO_PinInit(BOARD_GPIO_ACCEL_SDA_GPIO, BOARD_GPIO_ACCEL_SDA_PIN, &ACCEL_SDA_config);

    /* PORTE24 (pin 31) is configured as PTE24 */
    PORT_SetPinMux(BOARD_GPIO_ACCEL_SCL_PORT, BOARD_GPIO_ACCEL_SCL_PIN, kPORT_MuxAsGpio);

    /* PORTE25 (pin 32) is configured as PTE25 */
    PORT_SetPinMux(BOARD_GPIO_ACCEL_SDA_PORT, BOARD_GPIO_ACCEL_SDA_PIN, kPORT_MuxAsGpio);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
