/*
 * HR2RDAC_program.c
 *
 *  Created on: Jan 23, 2024
 *      Author: Tasneem
 */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "M_GPIO/MGPIO_interface.h"
#include "M_SYSTICK/MSYSTICK_interface.h"
#include "H_R2R_DAC/HR2RDAC_interface.h"

void HR2RDAC_voidInit(void){
	MGPIO_voidSetMode(PORT_B, GPIO_PIN0, GPIO_OUTPUT);
	MGPIO_voidSetMode(PORT_B, GPIO_PIN1, GPIO_OUTPUT);
	MGPIO_voidSetMode(PORT_B, GPIO_PIN5, GPIO_OUTPUT);
	MGPIO_voidSetMode(PORT_B, GPIO_PIN6, GPIO_OUTPUT);
	MGPIO_voidSetMode(PORT_B, GPIO_PIN7, GPIO_OUTPUT);
	MGPIO_voidSetMode(PORT_B, GPIO_PIN8, GPIO_OUTPUT);
	MGPIO_voidSetMode(PORT_B, GPIO_PIN9, GPIO_OUTPUT);
	MGPIO_voidSetMode(PORT_B, GPIO_PIN10, GPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN0,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN1,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN5,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN6,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN7,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN8,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN9,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN10,OUTPUT_PUSH_PULL ,MEDIUM_SPEED);
}

void HR2RDAC_voidSetData(const uint8 *arr, uint32 u32arrsize){
	for(uint32 u32Counter=0; u32Counter<u32arrsize; u32Counter++){
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN0, GET_BIT(arr[u32Counter],GPIO_PIN0));
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN1, GET_BIT(arr[u32Counter],GPIO_PIN1));
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN5, GET_BIT(arr[u32Counter],GPIO_PIN5));
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN6, GET_BIT(arr[u32Counter],GPIO_PIN6));
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN7, GET_BIT(arr[u32Counter],GPIO_PIN7));
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN8, GET_BIT(arr[u32Counter],GPIO_PIN8));
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN9, GET_BIT(arr[u32Counter],GPIO_PIN9));
		MGPIO_voidSetPinValue(PORT_B, GPIO_PIN10, GET_BIT(arr[u32Counter],GPIO_PIN10));
		MSYSTICK_voidDelayUs(125);

	}

}



