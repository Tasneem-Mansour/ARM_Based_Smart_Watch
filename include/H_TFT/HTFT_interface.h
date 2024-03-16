/*
 * HTFT_interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Tasneem
 */

#ifndef HTFT_INTERFACE_H_
#define HTFT_INTERFACE_H_


void HTFT_voidInit(void);
void HTFT_voidDisplay(const uint16* Cpy_u16Image);
void HTFT_voidFillColor(uint16 Cpy_u16Color);
void HTFT_voidDrawRectangle(uint8 X1, uint8 X2, uint8 Y1, uint8 Y2, uint16 Cpy_u16Color);
void HTFT_voidDrawText(uint8* Copy_u8Text, uint8 X1, uint8 Y1, uint8 Copy_u8Size, uint16 Copy_u16Color);
void HTFT_voidDrawCharacter(uint8 Copy_u8Char, uint8 X1, uint8 Y1, uint8 Copy_u8Size,uint16 Copy_u16Color);

#endif /* HTFT_INTERFACE_H_ */
