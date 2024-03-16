/*
 * KPD_program.c
 *
 *  Created on: Mar 7, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "M_GPIO/MGPIO_interface.h"
#include "M_SYSTICK/MSYSTICK_interface.h"
#include "H_KeyPad/HKPD_interface.h"
#include "H_KeyPad/HKPD_config.h"



uint16 KPD_arr[KPD_ROWS][KPD_COLS] = {
    { 'U', '-', '-', '-' },
    { 'H', 'S', '1', '2' },
    { 'D', 'C', '-', '-' },
    { '-', 'G', '-', '-' }
};
uint8 KPD_COL_PIN[KPD_COLS] = {COL_PIN12, COL_PIN13, COL_PIN14, COL_PIN15};
uint8 KPD_ROW_PIN[KPD_ROWS] = {ROW_PIN8, ROW_PIN9, ROW_PIN10, ROW_PIN11};


void HKPD_voidInit(void){
	/*********************ROWS PINS*********************/
	for (uint8 row = 0; row < KPD_ROWS; row++) {
		MGPIO_voidSetMode(KPD_ROW_PORT, KPD_ROW_PIN[row], GPIO_INPUT);
		MGPIO_voidSetInputPinMode(KPD_ROW_PORT, KPD_ROW_PIN[row], PULL_UP);
	}

	/*********************COLUMNS PINS*********************/
	for (uint8 col = 0; col < KPD_COLS; col++) {
		MGPIO_voidSetMode(KPD_COL_PORT, KPD_COL_PIN[col], GPIO_OUTPUT);
		MGPIO_voidSetPinValue(KPD_COL_PORT, KPD_COL_PIN[col], GPIO_HIGH);
	}
}

uint8 HKPD_u8GetKey(void){
	for (uint8 col = 0; col < KPD_COLS; col++) {
	        // Activate the column
		MGPIO_voidSetPinValue(KPD_COL_PORT, KPD_COL_PIN[col], GPIO_LOW);

	        // Check the rows
	        for (uint8 row = 0; row < KPD_ROWS; row++) {
	            if (MGPIO_u32GetPinValue(KPD_ROW_PORT, KPD_ROW_PIN[row]) == GPIO_LOW) {
	                // Debounce the key press
	                while (MGPIO_u32GetPinValue(KPD_ROW_PORT, KPD_ROW_PIN[row]) == GPIO_LOW);

	                // Deactivate the column
	                MGPIO_voidSetPinValue(KPD_COL_PORT, KPD_COL_PIN[col], GPIO_HIGH);

	                // Return the pressed key
	                return KPD_arr[row][col];
	            }
	        }

	        // Deactivate the column
	        MGPIO_voidSetPinValue(KPD_COL_PORT, KPD_COL_PIN[col], GPIO_HIGH);
	    }

	    // No key is pressed
	    return '\0';
}

