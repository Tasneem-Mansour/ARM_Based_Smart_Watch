/*
 * HSTP_program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"

#include "M_GPIO/MGPIO_interface.h"
#include "M_SYSTICK/MSYSTICK_interface.h"

#include "H_STP/HSTP_interface.h"
#include "H_STP/HSTP_config.h"
#include "H_STP/HSTP_private.h"

void HSTP_voidInit(void)
{
	MGPIO_voidSetMode(STP_SERIAL_DATA_PORT, STP_SERIAL_DATA_PIN,GPIO_OUTPUT);
	MGPIO_voidSetMode(STP_SHIFT_CLK_PORT, STP_SHIFT_CLK_PIN,GPIO_OUTPUT);
	MGPIO_voidSetMode(STP_SEND_CLK_PORT, STP_SEND_CLK_PIN,GPIO_OUTPUT);

//	MGPIO_voidSetOutputPinMode(STP_SERIAL_DATA_PORT, STP_SERIAL_DATA_PIN, OUTPUT_PUSH_PULL, LOW_SPEED);
//	MGPIO_voidSetOutputPinMode(STP_SHIFT_CLK_PORT, STP_SHIFT_CLK_PIN, OUTPUT_PUSH_PULL, LOW_SPEED);
//	MGPIO_voidSetOutputPinMode(STP_SEND_CLK_PORT, STP_SEND_CLK_PIN, OUTPUT_PUSH_PULL, LOW_SPEED);

//	MGPIO_voidSetPinValue(STP_SERIAL_DATA_PORT, STP_SERIAL_DATA_PIN, GPIO_HIGH);
//	MGPIO_voidSetPinValue(STP_SHIFT_CLK_PORT, STP_SHIFT_CLK_PIN, GPIO_HIGH);
//	MGPIO_voidSetPinValue(STP_SEND_CLK_PORT, STP_SEND_CLK_PIN, GPIO_HIGH);
}


void HSTP_voidSendDataSynch(uint16 Cpy_u16Data)
{
	sint16 Local_s8Cntr;			/*subtracting 1 from 0 in unsigned = 256 -> endless loop*/
	uint16 Local_u8Bit;
	for(Local_s8Cntr=15; Local_s8Cntr>=0; Local_s8Cntr--)
	{
		Local_u8Bit = GET_BIT(Cpy_u16Data, Local_s8Cntr);	/*send bit by bit starting from MSB*/
		MGPIO_voidSetPinValue(STP_SERIAL_DATA_PORT, STP_SERIAL_DATA_PIN, Local_u8Bit);
		/*Send pulse to Shift clock*/
		MGPIO_voidSetPinValue(STP_SHIFT_CLK_PORT, STP_SHIFT_CLK_PIN, GPIO_HIGH);
		MSYSTICK_voidDelayUs(1);
		MGPIO_voidSetPinValue(STP_SHIFT_CLK_PORT, STP_SHIFT_CLK_PIN, GPIO_LOW);
		MSYSTICK_voidDelayUs(1);
	}
	/*Send pulse to Latch clock*/
	MGPIO_voidSetPinValue(STP_SEND_CLK_PORT, STP_SEND_CLK_PIN, GPIO_HIGH);
	MSYSTICK_voidDelayUs(1);
	MGPIO_voidSetPinValue(STP_SEND_CLK_PORT, STP_SEND_CLK_PIN, GPIO_LOW);
	MSYSTICK_voidDelayUs(1);

}
