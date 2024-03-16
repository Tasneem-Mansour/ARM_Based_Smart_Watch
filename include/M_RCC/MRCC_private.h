/*
 * MRCC_private.h
 *
 *  Created on: Jan 15, 2024
 *      Author: Tasneem
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define RCC_BASE_ADDRESS 		0X40023800

/************Clock Source***********/
#define RCC_HSE_CRYSTAL     0
#define RCC_HSE_RC    		1
#define RCC_HSI    			2
#define RCC_PLL				3
/************PLL Input**************/
#define HSI_DIV_2       	0
#define HSE_DIV_2  			1
#define HSE					2

typedef struct
{
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
	uint32 AHB1RSTR;
	uint32 AHB2RSTR;
	uint32 reserved0;
	uint32 reserved1;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 reserved2;
	uint32 reserved3;
	uint32 AHB1ENR;
	uint32 AHB2ENR;
	uint32 reserved4;
	uint32 reserved5;
	uint32 APB1ENR;
	uint32 APB2ENR;
	uint32 reserved6;
	uint32 reserved7;
	uint32 AHB1LPENR;
	uint32 AHB2LPENR;
	uint32 reserved8;
	uint32 reserved9;
	uint32 APB1LPENR;
	uint32 APB2LPENR;
	uint32 reserved10;
	uint32 reserved11;
	uint32 BDCR;
	uint32 CSR;
	uint32 reserved12;
	uint32 reserved13;
	uint32 SSCGR;
	uint32 PLLI2SCFGR;
	uint32 reserved14;
	uint32 DCKCFGR;
}RCC_t;

#define RCC_BYP		18
#define RCC_HSEON	16
#define RCC_HSERDY	17

#define RCC_HSION 	0
#define RCC_HSIRDY  1

#define RCC_CFGR_RTCPRE			16

#define RCC_BDCR_RTCEN			15
#define RCC_BDCR_RTCSEL          8
#define RCC_BDCR_RTCSEL_1		9

#define SWITCH_MUSK 	0xFFFFFFFC
#define RCC_HSI_SW		0
#define RCC_HSE_SW 		1

#define RCC       ((volatile RCC_t*)(RCC_BASE_ADDRESS))



#endif /* MRCC_PRIVATE_H_ */
