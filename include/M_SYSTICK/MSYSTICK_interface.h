/*
 * MSYSTICK_interface.h
 *
 *  Created on: Jan 21, 2024
 *      Author: Tasneem
 */

#ifndef MSYSTICK_INTERFACE_H_
#define MSYSTICK_INTERFACE_H_


typedef enum
{
	SYSTICK_INTERRUPT_Enable,
	SYSTICK_INTERRUPT_Disable
}SYSTICKState;


// clock -> AHB  ****  AHB/8
void MSYSTICK_voidInit(void);

void MSYSTICK_voidStart(uint32 Copy_u32Loadvalue);

uint8 MSYSTICK_voidReadFlag(void);

void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_State );

// 16MHZ --> /8 ---> 2MHZ
void MSYSTICK_voidDelayUs(uint32 Copy_u32Delayvalue);
void MSYSTICK_voidDelayms(uint32 Copy_u32Delayvalue);


uint32  MSYSTICK_u32GetElapsedTime(void);
uint32  MSYSTICK_u32GetRemainingTime(void);

void MSYSTICK_voidSetInterval_single(uint32 Copy_u32Loadvalue, void (*CallbackFunction)(void));
void MSYSTICK_voidSetInterval_periodic(uint32 Copy_u32Loadvalue, void (*CallbackFunction)(void));


#endif /* MSYSTICK_INTERFACE_H_ */
