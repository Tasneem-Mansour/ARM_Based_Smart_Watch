/*
 * MSYSTICK_private.h
 *
 *  Created on: Jan 21, 2024
 *      Author: Tasneem
 */

#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS		0XE000E010



#define AHB_DIV_8		0
#define AHB_DIV_1			1

#define SYSTICK_AHB_DIVBY8 0
#define SYSTICK_AHB_DIVBY1 1

#define SYSTICK_STATE_DISABLE 0
#define SYSTICK_STATE_ENABLE  1

#define SYSTICK_INTERRUPT_DISABLE 0
#define SYSTICK_INTERRUPT_ENABLE  1

typedef enum{
	PERIODIC_MODE,
	SINGLE_MODE
}enuPeriodicMode;

typedef struct{
	uint32 STK_CTRL;
	uint32 STK_LOAD;
	uint32 STK_VAL;
	uint32 STK_CALIB;
}SYSTICK_t;

/***********STK_CTRL PINS***********/
#define CTRL_ENABLE			0
#define CTRL_TICKINT		1
#define CTRL_CLKSOURCE		2
#define CTRL_COUNTFLAG 		16


#define SYSTICK		((volatile SYSTICK_t*)(SYSTICK_BASE_ADDRESS))

#endif /* MSYSTICK_PRIVATE_H_ */
