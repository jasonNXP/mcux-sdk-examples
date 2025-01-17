/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_fmc.h"

#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Do software signature generation.
 *
 * @param startAddress  This variable is the starting address of where the signature generation will start.
 * @param length  The length variable is the region size to used for the signature generation.
 * @param *flashSignature  The result after generation completion will be put in the pointed location by the
 * flashSignature pointer.
 */
static void SOFT_GenerateFlashSignature(uint32_t startAddress, uint32_t length, fmc_flash_signature_t *flashSignature);

/*!
 * @brief Compare signature generated by software and FMC module, return true or false if equal or not.
 *
 * @param *pSignature1  The pointer to the first compared signature structure.
 * @param *pSignature2  The pointer to the second compared signature structure.
 * @retval true  Two signatures are equal.
 * @retval false Two signatures are different.
 */
static bool CompareSignature(fmc_flash_signature_t *pSignature1, fmc_flash_signature_t *pSignature2);

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if defined(__ICCARM__)
#pragma data_alignment = 16
const char g_testBuffer[32] =
#elif defined(__CC_ARM)
__align(16) const char g_testBuffer[32] =
#else
const char g_testBuffer[32] __attribute__((aligned(16))) =
#endif
    {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0xFF, 0xEF, 0x11, 0x22, 0x33, 0x55, 0x66, 0x77,
     0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0xFF, 0xEF, 0x11, 0x22, 0x33, 0x55, 0x66, 0x77};

/*******************************************************************************
 * Code
 ******************************************************************************/

static void SOFT_GenerateFlashSignature(uint32_t startAddress, uint32_t length, fmc_flash_signature_t *flashSignature)
{
    fmc_flash_signature_t flashWord;
    fmc_flash_signature_t refSignature = {0, 0, 0, 0};
    fmc_flash_signature_t nextSignature;
    uint32_t *pageAddress = (uint32_t *)(startAddress);

    for (uint32_t i = 0; i < (length >> 4); i++)
    {
        flashWord.word0 = *pageAddress;
        flashWord.word1 = *(pageAddress + 1);
        flashWord.word2 = *(pageAddress + 2);
        flashWord.word3 = *(pageAddress + 3);
        pageAddress     = pageAddress + 4;

        /* Update 128 bit signature. */
        nextSignature.word0 = flashWord.word0 ^ (refSignature.word0 >> 1) ^ (refSignature.word1 << 31);
        nextSignature.word1 = flashWord.word1 ^ (refSignature.word1 >> 1) ^ (refSignature.word2 << 31);
        nextSignature.word2 = flashWord.word2 ^ (refSignature.word2 >> 1) ^ (refSignature.word3 << 31);
        nextSignature.word3 = flashWord.word3 ^ (refSignature.word3 >> 1) ^ ((refSignature.word0 & (1 << 29)) << 2) ^
                              ((refSignature.word0 & (1 << 27)) << 4) ^ ((refSignature.word0 & 1 << 2) << 29) ^
                              ((refSignature.word0 & (1 << 0)) << 31);

        refSignature.word0 = nextSignature.word0;
        refSignature.word1 = nextSignature.word1;
        refSignature.word2 = nextSignature.word2;
        refSignature.word3 = nextSignature.word3;
    }

    /* Store the result. */
    flashSignature->word0 = refSignature.word0;
    flashSignature->word1 = refSignature.word1;
    flashSignature->word2 = refSignature.word2;
    flashSignature->word3 = refSignature.word3;
}

static bool CompareSignature(fmc_flash_signature_t *pSignature1, fmc_flash_signature_t *pSignature2)
{
    if (memcmp(pSignature1, pSignature2, sizeof(fmc_flash_signature_t)) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    fmc_flash_signature_t hardSignature;
    fmc_flash_signature_t softSignature;
    fmc_config_t config;

    static uint32_t relocMem[512];
    void (*fptr)(FMC_Type * base, uint32_t startAddress, uint32_t length, fmc_flash_signature_t * flashSignature);

    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitPins();
    BOARD_BootClockPLL220M();
    BOARD_InitDebugConsole();

    FMC_GetDefaultConfig(&config);
    config.waitStates = 0x0a;
    FMC_Init(FMC, &config);

    /* Copy hardware signature generation function to RAM to execute signature generation. */
    memcpy(relocMem, (void *)((uint32_t)FMC_GenerateFlashSignature & ~3U), sizeof(relocMem));

    fptr = (void (*)(FMC_Type * base, uint32_t startAddress, uint32_t length, fmc_flash_signature_t * flashSignature))(
        (uint32_t)relocMem + ((uint32_t)FMC_GenerateFlashSignature & 3U));

    fptr(FMC, (uint32_t)g_testBuffer, 32, &hardSignature);
    PRINTF(" Generate hardware signature: 0x%x %x %x %x\r\n", hardSignature.word3, hardSignature.word2,
           hardSignature.word1, hardSignature.word0);

    SOFT_GenerateFlashSignature((uint32_t)g_testBuffer, 32, &softSignature);
    PRINTF(" Generate software signature: 0x%x %x %x %x\r\n", softSignature.word3, softSignature.word2,
           softSignature.word1, softSignature.word0);

    if (CompareSignature(&hardSignature, &softSignature) == true)
    {
        PRINTF(" Success! Signature consistent !\r\n");
    }
    else
    {
        PRINTF(" Fail! Signature not consistent !\r\n");
    }

    while (1)
    {
    }
}
