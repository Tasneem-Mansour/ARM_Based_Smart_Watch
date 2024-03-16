/*
 * MRCC_program.c
 *
 *  Created on: Jan 15, 2024
 *      Author: Tasneem
 */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "M_RCC/MRCC_interface.h"
#include "M_RCC/MRCC_config.h"
#include "M_RCC/MRCC_private.h"



void MRCC_voidInitClk(void)
{
#if RCC_SYSTEM_CLK==RCC_HSE_CRYSTAL
	RCC->CR &=~(1<<RCC_BYP);
	RCC->CR |=1<<RCC_HSEON;
	while(!GET_BIT(RCC->CR, RCC_HSERDY));
	RCC->CFGR &=SWITCH_MUSK;
	RCC->CFGR |= RCC_HSE_SW;

#elif RCC_SYSTEM_CLK==RCC_HSE_RC
	SET_BIT(RCC->CR,16);
	SET_BIT(RCC->CR,18);
	SET_BIT(RCC->CFGR,0);

	//RCC->CR |= 18;
	//SET_BIT(RCC->CR,18);
#elif RCC_SYSTEM_CLK==RCC_HSI

	RCC->CR |=1<<RCC_HSION;
	while(!GET_BIT(RCC->CR,RCC_HSIRDY));
	//	CLR_BIT(RCC->CFGR,0);
	//	CLR_BIT(RCC->CFGR,1);
	RCC->CFGR &=SWITCH_MUSK;
	RCC->CFGR &=~ RCC_HSI_SW;



#elif RCC_SYSTEM_CLK==RCC_PLL
#if RCC_PLL_CLK_INPUT == HSI_DIV_2
	/* do it from 2->16*/
#if RCC_PLL_CLK_MULT_FACTOR == 2
	SET_BIT(RCC->CR,24);
	CLR_BIT(RCC->CFGR,16);
	CLR_BIT(RCC->CFGR,17);

#elif RCC_PLL_CLK_MULT_FACTOR == 3
	SET_BIT(RCC->CR,24);
	SET_BIT(RCC->CFGR,18);
#endif
#elif RCC_PLL_CLK_INPUT == HSE_DIV_2

#elif RCC_PLL_CLK_INPUT == HSE

#else
#error ("error")
#endif
#else
#error"Wrong Clock was selected"
#endif
}
void MRCC_voidEnablePeripheralClk(SYSTEM_BUS Copy_u8BusID, uint8 Copy_u8PeripheralNum)
{
	switch (Copy_u8BusID)
	{
	case RCC_AHB1: SET_BIT(RCC->AHB1ENR,Copy_u8PeripheralNum);     break;
	case RCC_AHB2: SET_BIT(RCC->AHB2ENR,Copy_u8PeripheralNum);     break;
	case RCC_APB1: SET_BIT(RCC->APB1ENR,Copy_u8PeripheralNum);     break;
	case RCC_APB2: SET_BIT(RCC->APB2ENR,Copy_u8PeripheralNum);     break;
	default: /*invalid input, return error*/					   break;
	}

}

void MRCC_voidDisablePeripheralClk(SYSTEM_BUS Copy_u8BusID, uint8 Copy_u8PeripheralNum)
{

	switch (Copy_u8BusID)
	{
	case RCC_AHB1: CLR_BIT(RCC->AHB1ENR,Copy_u8PeripheralNum);     break;
	case RCC_AHB2: CLR_BIT(RCC->AHB2ENR,Copy_u8PeripheralNum);     break;
	case RCC_APB1: CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralNum);     break;
	case RCC_APB2: CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralNum);     break;
	default: /*invalid input, return error*/					   break;
	}
}
