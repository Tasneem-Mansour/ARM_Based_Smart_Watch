/*
 * EXTI_program.c
 *
 *  Created on: Jan 20, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "M_EXTI/MEXTI_interface.h"
#include "M_EXTI/MEXTI_private.h"
#include "M_EXTI/MEXTI_config.h"

static void (*Global_EXTIPtr[16])(void);			//array of pointers to function

void MEXTI_voidInerruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port){
	SYSCFG->EXTICR[Copy_u8Line/Div_Fac]  &=~ (Musk<<((Copy_u8Line % Div_Fac)*4));
	SYSCFG->EXTICR[Copy_u8Line/Div_Fac]  |= Copy_u8Port<<((Copy_u8Line % Div_Fac)*4);
}

void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis){
	switch (Copy_u8ENDis){
	case EXTI_Enable:	EXTI->IMR |= 1<<(Copy_u8IntLine);		break;
	case EXTI_Disable:	EXTI->IMR &= ~(1<<(Copy_u8IntLine));	break;
	default:  break;
	}
}

void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig){
	switch (Copy_u8Trig){
	case EXTI_Falling:
		EXTI->FTSR |= 1<<(Copy_u8IntLine);
		EXTI->RTSR &= ~(1<<(Copy_u8IntLine));
		break;
	case EXTI_Rising:
		EXTI->RTSR |= 1<<(Copy_u8IntLine);
		EXTI->FTSR &= ~(1<<(Copy_u8IntLine));
		break;
	case EXTI_OnChange:
		EXTI->RTSR |= 1<<(Copy_u8IntLine);
		EXTI->FTSR |= 1<<(Copy_u8IntLine);
		break;
	default:  break;
	}
}

void MEXTI0_voidCallBack(void (*ptr)(void)){
	Global_EXTIPtr[0]=ptr;
}
void MEXTI1_voidCallBack(void (*ptr)(void)){
	Global_EXTIPtr[1]=ptr;
}
//void MEXTIx_voidCallBack(uint8 u8Index, void (*ptr)(void)){
//	Global_EXTIPtr[u8Index]=ptr;
//}

void EXTI0_IRQHandler(void){
	Global_EXTIPtr[0]();
    EXTI->PR |=1;
}

void EXTI1_IRQHandler(void){
	Global_EXTIPtr[1]();
	  EXTI->PR |=1<<1;
}
