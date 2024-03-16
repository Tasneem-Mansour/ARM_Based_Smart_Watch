/*
 * MRCC_config.h
 *
 *  Created on: Jan 15, 2024
 *      Author: Tasneem
 */

/******************CLK_SYS OPTIONS*************/
/* 1-RCC_HSE_CRYSTAL
 * 2-RCC_HSE_RC
 * 2-RCC_HSI
 * 3-RCC_PLL
 */
#define RCC_SYSTEM_CLK				RCC_HSE_CRYSTAL



/********************PLL_OPTIONS*************/
/* PLL input -> 3 options (HSI_DIV_2, HSE_DIV_2, HSE)
 */

#define RCC_PLL_CLK_INPUT			HSI_DIV_2

/* PLL multiplication factor -> 2:16
 */
#define RCC_PLL_CLK_MULT_FACTOR		9
