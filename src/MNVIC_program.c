/*
 * MNVIC_program.c
 *
 *  Created on: Jan 17, 2024
 *      Author: Tasneem
 */

#include "BIT_Math.h"
#include "STD_Types.h"
#include "M_NVIC/MNVIC_interface.h"
#include "M_NVIC/MNVIC_config.h"
#include "M_NVIC/MNVIC_private.h"


static uint8 Global_u8IPR=0;

void MNVIC_voidEnableInterrupt(uint8 u8positionCpy){
	NVIC->NVIC_ISER[u8positionCpy/Reg_div] |= 1 << (u8positionCpy%Reg_div);
}
void MNVIC_voidDisableInterrupt(uint8 u8positionCpy){
	NVIC->NVIC_ICER[u8positionCpy/Reg_div] |= 1 << (u8positionCpy%Reg_div);
}

void MNVIC_voidEnableInterruptBending(uint8 u8positionCpy){
	NVIC->NVIC_ISPR[u8positionCpy/Reg_div] |= 1 << (u8positionCpy%Reg_div);
}
void MNVIC_voidDisableInterruptBending(uint8 u8positionCpy){
	NVIC->NVIC_ICPR[u8positionCpy/Reg_div] |= 1 << (u8positionCpy%Reg_div);
}


void MNVIC_voidSetInterruptGroupMode(MNVIC_Group_t uddtGroupModeCpy){
	Global_u8IPR = uddtGroupModeCpy;			//4 g4sub
	uint32 u32LocalCpy= NVIC_VECTKEY|(uddtGroupModeCpy <<8);
	SCB_AIRCR = u32LocalCpy;
}


void MNVIC_voidSetInterruptPriority(uint8 u8IntPosCpy,uint8 u8GroupNumCpy,uint8 u8SubGroupNumCpy){
	switch (Global_u8IPR)
	{
	case Group16Sub0:  	NVIC ->NVIC_IPR[u8IntPosCpy]= u8GroupNumCpy<<4;							break;
	case Group8Sub2:	NVIC ->NVIC_IPR[u8IntPosCpy]= u8GroupNumCpy<<5 |u8SubGroupNumCpy<<4 ;	break;
	case Group4Sub4:	NVIC ->NVIC_IPR[u8IntPosCpy]= u8GroupNumCpy<<6 |u8SubGroupNumCpy<<4 ;	break;
	case Group2Sub8:	NVIC ->NVIC_IPR[u8IntPosCpy]= u8GroupNumCpy<<7 |u8SubGroupNumCpy<<4 ;	break;
	case Group0Sub16:	NVIC ->NVIC_IPR[u8IntPosCpy]= u8SubGroupNumCpy<<4 ;						break;
	default:																					break;
	}
}

void MNVIC_u8IsInterruptActive(uint8 u8positionCpy,uint8 *ReadDataCpy){
	*ReadDataCpy=GET_BIT((NVIC->NVIC_IABR[u8positionCpy/Reg_div]),(u8positionCpy%Reg_div));
}
