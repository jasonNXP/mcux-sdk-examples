/*
 * Copyright 2017-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pin_mux.h"
#include "board.h"
#include "fsl_capt.h"
#include "fsl_debug_console.h"

#include <stdbool.h>
#include "fsl_power.h"
#include "fsl_gpio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_CAPT_BASE       CAPT
#define DEMO_CAPT_IRQn       CMP_CAPT_IRQn
#define DEMO_CAPT_IRQHandler CMP_CAPT_IRQHandler
#define DEMO_CAPT_ENABLE_PINS_ARRAY                                     \
    {                                                                   \
        kCAPT_X0Pin, kCAPT_X1Pin, kCAPT_X2Pin, kCAPT_X3Pin, kCAPT_X4Pin \
    }
#define DEMO_CAPT_ENABLE_PINS_NUM 5
#define DEMO_CAPT_CLOCK_FREQ      CLOCK_GetFroFreq()

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static const uint16_t g_captEnabledPins[] = DEMO_CAPT_ENABLE_PINS_ARRAY;
volatile uint16_t g_captRawData[DEMO_CAPT_ENABLE_PINS_NUM];
volatile bool g_captPollDone;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief ISR for CAPT.
 */
void DEMO_CAPT_IRQHandler(void)
{
    uint32_t intStat;

    intStat = CAPT_GetInterruptStatusFlags(DEMO_CAPT_BASE);

    CAPT_ClearInterruptStatusFlags(DEMO_CAPT_BASE, intStat);

    if (intStat & kCAPT_InterruptOfPollDoneStatusFlag)
    {
        g_captPollDone = true;
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    capt_config_t captConfig;
    uint32_t captClockFreq;

    /* Initialize board hardware. */
    /* Attach 12 MHz clock to USART0 (debug console) */
    CLOCK_Select(BOARD_DEBUG_USART_CLK_ATTACH);

    /* Attach main clock to CAPT */
    CLOCK_Select(kCAPT_Clk_From_Fro);
    POWER_DisablePD(kPDRUNCFG_PD_ACMP);

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    PRINTF("CAPT basic example.\r\n");

    /* Initialize CAPT module. */
    CAPT_GetDefaultConfig(&captConfig);

    /* Calculate the clock divider to make sure CAPT work in 2Mhz fclk. */
    captClockFreq           = DEMO_CAPT_CLOCK_FREQ;
    captConfig.clockDivider = (captClockFreq / 2000000U - 1U);
    captConfig.enableXpins  = 0;
    CAPT_Init(DEMO_CAPT_BASE, &captConfig);

    /* Enable the interrupts. */
    CAPT_EnableInterrupts(DEMO_CAPT_BASE, kCAPT_InterruptOfPollDoneEnable);
    NVIC_EnableIRQ(DEMO_CAPT_IRQn);

    while (1)
    {
        capt_touch_data_t s_captData;

        for (uint8_t i = 0; i < ARRAY_SIZE(g_captEnabledPins); i++)
        {
            g_captPollDone = false;

            CAPT_PollNow(DEMO_CAPT_BASE, g_captEnabledPins[i]);

            while (!g_captPollDone)
            {
            }

            CAPT_GetTouchData(DEMO_CAPT_BASE, &s_captData);

            g_captRawData[i] = s_captData.count;
        }

        /* Output the captured data. */
        PRINTF("CAPT Data: ");

        for (uint8_t i = 0; i < ARRAY_SIZE(g_captRawData); i++)
        {
            PRINTF("%u\t", g_captRawData[i]);
        }

        PRINTF("\r\n");

        g_captPollDone = false;
    }
}
