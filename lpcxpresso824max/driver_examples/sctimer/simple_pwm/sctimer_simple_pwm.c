/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_sctimer.h"

#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define SCTIMER_CLK_FREQ        CLOCK_GetFreq(kCLOCK_Irc)
#define DEMO_FIRST_SCTIMER_OUT  kSCTIMER_Out_4
#define DEMO_SECOND_SCTIMER_OUT kSCTIMER_Out_2

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{
    sctimer_config_t sctimerInfo;
    sctimer_pwm_signal_param_t pwmParam;
    uint32_t event;
    uint32_t sctimerClock;

    /* Board pin, clock, debug console init */
    /* Enable clock of uart0. */
    CLOCK_EnableClock(kCLOCK_Uart0);
    /* Ser DIV of uart0. */
    CLOCK_SetClkDivider(kCLOCK_DivUsartClk, 1U);

    BOARD_InitPins();
    BOARD_BootClockIRC12M();
    BOARD_InitDebugConsole();

    /* Enable clock of sct. */
    CLOCK_EnableClock(kCLOCK_Sct);

    sctimerClock = SCTIMER_CLK_FREQ;

    /* Print a note to terminal */
    PRINTF("\r\nSCTimer example to output 2 center-aligned PWM signals\r\n");
    PRINTF("\r\nProbe the signal using an oscilloscope");

    SCTIMER_GetDefaultConfig(&sctimerInfo);

    /* Initialize SCTimer module */
    SCTIMER_Init(SCT0, &sctimerInfo);

    /* Configure first PWM with frequency 24kHZ from first output */
    pwmParam.output           = DEMO_FIRST_SCTIMER_OUT;
    pwmParam.level            = kSCTIMER_HighTrue;
    pwmParam.dutyCyclePercent = 50;
    if (SCTIMER_SetupPwm(SCT0, &pwmParam, kSCTIMER_CenterAlignedPwm, 24000U, sctimerClock, &event) == kStatus_Fail)
    {
        return -1;
    }

    /* Configure second PWM with different duty cycle but same frequency as before */
    pwmParam.output           = DEMO_SECOND_SCTIMER_OUT;
    pwmParam.level            = kSCTIMER_LowTrue;
    pwmParam.dutyCyclePercent = 20;
    if (SCTIMER_SetupPwm(SCT0, &pwmParam, kSCTIMER_CenterAlignedPwm, 24000U, sctimerClock, &event) == kStatus_Fail)
    {
        return -1;
    }

    /* Start the 32-bit unify timer */
    SCTIMER_StartTimer(SCT0, kSCTIMER_Counter_U);

    while (1)
    {
    }
}
