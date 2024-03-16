/*
 * GPIO_interface.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Tasneem
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

//PORTA -> 13,14,15 PINS DON'T USE
//PORTB -> 2,3,4    PINS DON'T USE
/*********GPIO Ports***********/
#define PORT_A			    0
#define PORT_B			    1
#define PORT_C			    2

/*********GPIO Pins***********/
#define GPIO_PIN0	    	0
#define GPIO_PIN1	    	1
#define GPIO_PIN2	    	2
#define GPIO_PIN3	    	3
#define GPIO_PIN4	    	4
#define GPIO_PIN5	    	5
#define GPIO_PIN6	    	6
#define GPIO_PIN7	    	7
#define GPIO_PIN8	    	8
#define GPIO_PIN9	    	9
#define GPIO_PIN10	    	10
#define GPIO_PIN11	    	11
#define GPIO_PIN12	    	12
#define GPIO_PIN13	    	13
#define GPIO_PIN14	    	14
#define GPIO_PIN15	    	15

#define ONE_BIT_MUSK         		1
#define TWO_BIT_MUSK         		3
#define FOUR_BIT_MASK				0xF

///**********Mode***********/
#define GPIO_INPUT 				0
#define GPIO_OUTPUT 			1
#define GPIO_ALTERNATIVE_MODE 	2
#define GPIO_ANALOG 			3

// push-pull OR open drain
#define OUTPUT_PUSH_PULL	0
#define OUTPUT_OPEN_DRAIN	1

//Speed
#define LOW_SPEED			0
#define MEDIUM_SPEED		1
#define HIGH_SPEED			2
#define VERY_HIGH_SPEED		3

//PULL UP-DOWN
#define NO_PULL				0
#define PULL_UP				1
#define PULL_DOWN 			2
#define RESERVED			3

#define GPIO_LOW         	0
#define GPIO_HIGH      	 	1

typedef enum
{
	PIN_RESET = 0,
	PIN_SET,
}PIN_SETRESET_t;

typedef enum
{
	AF1_TIM_1_2 = 1,
	AF2_TIM_3_5,
	AF3_TIM_9_11,
	AF4_I2C_1_3,
	AF5_SPI_1_4,
	AF6_SPI_3,
	AF7_USART_1_2,
	AF8_USART_6,
	AF9_I2C_2_3,
	AF10_OTG_FS,
	AF11,
	AF12_SDIO,
	AF13,
	AF14,
	AF15_EVENOUT
}PIN_ALTERNATE_t;


void MGPIO_voidSetMode(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8mode);
void MGPIO_voidSetOutputPinMode(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8type, uint8 u8speed);
void MGPIO_voidSetInputPinMode(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8pullupdown);

//void MGPIO_voidGetPinValue(uint8 u8portCpy, uint8 u8pinCpy, uint8 *pData);
uint32 MGPIO_u32GetPinValue(uint8 u8portCpy, uint8 u8pinCpy);
void MGPIO_voidSetPinValue(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8Data);

void MGPIO_voidPortSet_Reset(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8Data);

void MGPIO_voidSetAlt(uint8 u8portCpy, uint8 u8pinCpy, PIN_ALTERNATE_t u8AltFun);

#endif /* GPIO_INTERFACE_H_ */
