/*
 * HTFT_program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "H_TFT/HTFT_interface.h"
#include "H_TFT/HTFT_config.h"
#include "H_TFT/HTFT_private.h"

#include "M_GPIO/MGPIO_interface.h"
#include "M_SPI/MSPI_interface.h"
#include "M_SYSTICK/MSYSTICK_interface.h"


static void HTFT_WriteCommand(uint8 Cpy_u8Command)
{
	/*Set TFT_A0 To LOW*/
	MGPIO_voidSetPinValue(TFT_PORT, TFT_A0_PIN, GPIO_LOW);
	/*Send Value of Command*/
	(void)MSPI1_u16Transceive(Cpy_u8Command);
}

static void HTFT_WriteData(uint8 Cpy_u8Data)
{
	/*Set TFT_A0 To LOW*/
	MGPIO_voidSetPinValue(TFT_PORT, TFT_A0_PIN, GPIO_HIGH);
	/*Send Value of Command*/
	(void)MSPI1_u16Transceive(Cpy_u8Data);

}

static void HTFT_voidReset(void)
{
	MGPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN,GPIO_HIGH);
	MSYSTICK_voidDelayUs(100);
	MGPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN,GPIO_LOW);
	MSYSTICK_voidDelayUs(3);
	MGPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN,GPIO_HIGH);
	MSYSTICK_voidDelayUs(100);
	MGPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN,GPIO_LOW);
	MSYSTICK_voidDelayUs(100);
	MGPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN,GPIO_HIGH);
	MSYSTICK_voidDelayms(120);
}
void HTFT_voidInit(void)
{
	HTFT_voidReset();
	/*Sleep Out Command*/
	HTFT_WriteCommand(TFT_CMD_SLEEP_OUT_MODE);
	MSYSTICK_voidDelayms(150);
	/*Color Mode Command*/
	HTFT_WriteCommand(TFT_CMD_COLOR_MODE);
	HTFT_WriteData(TFT_COLOR_STANDARD);
	/*Display Mode*/
	HTFT_WriteCommand(TFT_CMD_DISPLAY_MODE);
}

void HTFT_voidDisplay(const uint16* Cpy_u16Image)
{
	uint16 Local_u16Counter=0;
	/*Set X address*/
	HTFT_WriteCommand(TFT_CMD_SET_X_POSITION_MODE);
	/*Start X*/
	HTFT_WriteData(START_X_BYTE1);
	HTFT_WriteData(START_X_BYTE2);
	/*End X*/
	HTFT_WriteData(END_X_BYTE2);
	HTFT_WriteData(END_X_BYTE1);

	/*Set Y address*/
	HTFT_WriteCommand(TFT_CMD_SET_Y_POSITION_MODE);
	/*Start Y*/
	HTFT_WriteData(START_Y_BYTE1);
	HTFT_WriteData(START_Y_BYTE2);
	/*End Y*/
	HTFT_WriteData(END_Y_BYTE2);
	HTFT_WriteData(END_Y_BYTE1);

	/*Write on RAM command*/
	HTFT_WriteCommand(TFT_CMD_WRITE_ON_RAM_MODE);

	/*Display Data*/
	for(Local_u16Counter=0;Local_u16Counter<TFT_RESOLUTION;Local_u16Counter++)
	{
		HTFT_WriteData(~((uint8)(Cpy_u16Image[Local_u16Counter]>>8)));		/*Write the high byte*/
		HTFT_WriteData(~((uint8)(Cpy_u16Image[Local_u16Counter]&0x00FF)));	/*Write the low byte*/
	}

}

void HTFT_voidFillColor(uint16 Cpy_u16Color)
{
	uint16 Local_u16Counter=0;
	/*Set X address*/
	HTFT_WriteCommand(TFT_CMD_SET_X_POSITION_MODE);
	/*Start X*/
	HTFT_WriteData(START_X_BYTE1);
	HTFT_WriteData(START_X_BYTE2);
	/*End X*/
	HTFT_WriteData(END_X_BYTE2);
	HTFT_WriteData(END_X_BYTE1);

	/*Set Y address*/
	HTFT_WriteCommand(TFT_CMD_SET_Y_POSITION_MODE);
	/*Start Y*/
	HTFT_WriteData(START_Y_BYTE1);
	HTFT_WriteData(START_Y_BYTE2);
	/*End Y*/
	HTFT_WriteData(END_Y_BYTE2);
	HTFT_WriteData(END_Y_BYTE1);

	/*Write on RAM command*/
	HTFT_WriteCommand(TFT_CMD_WRITE_ON_RAM_MODE);

	/*Display Data*/
	for(Local_u16Counter=0;Local_u16Counter<TFT_RESOLUTION;Local_u16Counter++)
	{
		HTFT_WriteData(~((uint8)(Cpy_u16Color>>8)));		/*Write the high byte*/
		HTFT_WriteData(~((uint8)(Cpy_u16Color&0x00FF)));	/*Write the low byte*/
	}
}


void HTFT_voidDrawRectangle(uint8 X1, uint8 X2, uint8 Y1, uint8 Y2, uint16 Cpy_u16Color)
{
	uint16 Local_u16Counter=0;
	uint8 Local_RecSize = (X2-X1) * (Y2-Y1);
	/*Set X address*/
	HTFT_WriteCommand(TFT_CMD_SET_X_POSITION_MODE);
	/*Start X*/
	HTFT_WriteData(START_X_BYTE1);
	HTFT_WriteData(X1);
	/*End X*/
	HTFT_WriteData(END_X_BYTE2);
	HTFT_WriteData(X2);

	/*Set Y address*/
	HTFT_WriteCommand(TFT_CMD_SET_Y_POSITION_MODE);
	/*Start Y*/
	HTFT_WriteData(START_Y_BYTE1);
	HTFT_WriteData(Y1);
	/*End Y*/
	HTFT_WriteData(END_Y_BYTE2);
	HTFT_WriteData(Y2);

	/*Write on RAM command*/
	HTFT_WriteCommand(TFT_CMD_WRITE_ON_RAM_MODE);

	/*Display Data*/
	for(Local_u16Counter=0;Local_u16Counter<Local_RecSize;Local_u16Counter++)
	{
		HTFT_WriteData(~((uint8)(Cpy_u16Color>>8)));		/*Write the high byte*/
		HTFT_WriteData(~((uint8)(Cpy_u16Color&0x00FF)));	/*Write the low byte*/
	}
}
void HTFT_voidDrawText(uint8* Copy_u8Text, uint8 X1, uint8 Y1, uint8 Copy_u8Size, uint16 Copy_u16Color){
	for(; *Copy_u8Text; Copy_u8Text++ ){
		if(*Copy_u8Text == 32){
			X1 -= 3;
		}
		else{
			X1 -= 11 * Copy_u8Size;
			HTFT_voidDrawCharacter( *Copy_u8Text,   X1,  Y1,  Copy_u8Size, Copy_u16Color);
		}
	}

}


void HTFT_voidDrawCharacter(uint8 Copy_u8Char, uint8 X1, uint8 Y1, uint8 Copy_u8Size,uint16 Copy_u16Color)
{
	if(Copy_u8Char==32){
		return;
	}
	Copy_u8Char -= 48;

	for(uint8 i =0 ; i<(13* Copy_u8Size); i++){
		for(uint8 j =0; j<(10*Copy_u8Size); j++){
			if ((Char_Array[Copy_u8Char][i/Copy_u8Size] >> (j/Copy_u8Size)) & 0x01){
				HTFT_voidDrawRectangle ( X1+(j),  X1+(j)+1,  Y1+(i),  Y1+(i), Copy_u16Color);
			}
			else {
				HTFT_voidDrawRectangle ( X1,  X1,  Y1,  Y1, Copy_u16Color);
			}
		}
	}
}
