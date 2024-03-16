/*
 * MSYSTICK_program.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "M_SYSTICK/MSYSTICK_interface.h"
#include "M_SYSTICK/MSYSTICK_private.h"
#include "M_SYSTICK/MSYSTICK_config.h"



static pf pfGLOBAL_SysTickISR = NULL_PTR;
static uint8 u8GLOBAL_MODE = 0;

void MSYSTICK_voidInit(void){
#if SYSTICK_CLK_SOURCE==AHB_DIV_8
	SYSTICK-> STK_CTRL &=~ (1<<CTRL_CLKSOURCE);

#elif SYSTICK_CLK_SOURCE==AHB_DIV_1
	SYSTICK-> STK_CTRL |= (1<<CTRL_CLKSOURCE);

#endif


//#if SYSTICK_INTERRUPT == SYSTICK_INTERRUPT_DISABLE
//	SYSTICK-> STK_CTRL &=~ (1<<CTRL_TICKINT);
//#elif SYSTICK_INTERRUPT == SYSTICK_INTERRUPT_ENABLE
//	SYSTICK-> STK_CTRL |= (1<<CTRL_TICKINT);
//#endif


	//#if SYSTICK_STATE == SYSTICK_STATE_DISABLE
	//	SYSTICK-> STK_CTRL &=~ (1<<CTRL_ENABLE);
	//#elif SYSTICK_STATE == SYSTICK_STATE_ENABLE
	//	SYSTICK-> STK_CTRL |= (1<<CTRL_ENABLE);
	//#endif
}

void MSYSTICK_voidStart(uint32 Copy_u32Loadvalue){
	SYSTICK-> STK_LOAD = Copy_u32Loadvalue;
	SYSTICK-> STK_VAL = 0;
	SYSTICK-> STK_CTRL |= (1<<CTRL_ENABLE);
}

uint8 MSYSTICK_voidReadFlag(void){
	return GET_BIT(SYSTICK-> STK_CTRL, CTRL_COUNTFLAG);
}

void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_State){
	switch(Copy_State){
	case SYSTICK_INTERRUPT_Enable:		SYSTICK->STK_CTRL |= (1<<CTRL_TICKINT);		break;
	case SYSTICK_INTERRUPT_Disable:		SYSTICK->STK_CTRL &=~ (1<<CTRL_TICKINT);	break;
	default: 																		break;
	}
}

void MSYSTICK_voidDelayUs(uint32 Copy_u32Delayvalue){
	MSYSTICK_voidCtrlIntState(SYSTICK_INTERRUPT_Disable);

#if SYSTICK_CLK_SOURCE==AHB_DIV_8
	MSYSTICK_voidStart(Copy_u32Delayvalue*2);

#elif SYSTICK_CLK_SOURCE==AHB_DIV_1
	MSYSTICK_voidStart(Copy_u32Delayvalue*16);
#endif

	while(MSYSTICK_voidReadFlag()==0);

}
void MSYSTICK_voidDelayms(uint32 Copy_u32Delayvalue){
	MSYSTICK_voidCtrlIntState(SYSTICK_INTERRUPT_Disable);

#if SYSTICK_CLK_SOURCE==AHB_DIV_8
	MSYSTICK_voidStart(Copy_u32Delayvalue*2000);

#elif SYSTICK_CLK_SOURCE==AHB_DIV_1
	MSYSTICK_voidStart(Copy_u32Delayvalue*16000);
#endif

	while(MSYSTICK_voidReadFlag()==0);
}

uint32  MSYSTICK_u32GetElapsedTime(void){
	return ((SYSTICK->STK_LOAD)-(SYSTICK->STK_VAL));
}
uint32  MSYSTICK_u32GetRemainingTime(void){
	return (SYSTICK->STK_VAL);
}

void MSYSTICK_voidSetInterval_single(uint32 Copy_u32Loadvalue, void (*CallbackFunction)(void))
{
	pfGLOBAL_SysTickISR = CallbackFunction;
	MSYSTICK_voidStart(Copy_u32Loadvalue);
	u8GLOBAL_MODE=SINGLE_MODE;
}

void MSYSTICK_voidSetInterval_periodic(uint32 Copy_u32Loadvalue, void (*CallbackFunction)(void))
{
	pfGLOBAL_SysTickISR = CallbackFunction;
	MSYSTICK_voidStart(Copy_u32Loadvalue);
	u8GLOBAL_MODE=PERIODIC_MODE;
}

void SysTick_Handler(void)
{
	if(pfGLOBAL_SysTickISR!=NULL_PTR)
	{
		pfGLOBAL_SysTickISR();
		if(u8GLOBAL_MODE==SINGLE_MODE)
		{
			pfGLOBAL_SysTickISR = NULL_PTR;
		}
	}
	else
	{
		//do nth
	}
}
