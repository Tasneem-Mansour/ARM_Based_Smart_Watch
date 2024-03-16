/*
 * MGPIO_program.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Tasneem
 */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "M_GPIO/MGPIO_interface.h"
#include "M_GPIO/MGPIO_config.h"
#include "M_GPIO/MGPIO_private.h"




void MGPIO_voidSetMode(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8mode){		//input or output
	//check if PortA pin 13,14, 15 or portB pin 2,3,4
	if(((u8portCpy==PORT_A)&&(u8pinCpy==GPIO_PIN13||u8pinCpy==GPIO_PIN14||u8pinCpy==GPIO_PIN15))||((u8portCpy==PORT_B)&&(u8pinCpy==GPIO_PIN2||u8pinCpy==GPIO_PIN3||u8pinCpy==GPIO_PIN4)))
	{
		//Do Nothing
	}
	else{
		switch(u8portCpy){
		case PORT_A:
			//bitmasking
			GPIO_A -> MODER &=~(TWO_BIT_MUSK<<u8pinCpy*2);
			GPIO_A -> MODER |= (u8mode<< (u8pinCpy*2));
			break;

		case PORT_B:
			GPIO_B -> MODER &=~ (TWO_BIT_MUSK<<u8pinCpy*2);
			GPIO_B -> MODER |= (u8mode << (u8pinCpy*2));
			break;

		case PORT_C:
			GPIO_C -> MODER &=~(TWO_BIT_MUSK<<u8pinCpy*2);
			GPIO_C -> MODER |= (u8mode << (u8pinCpy*2));
			break;
		default:
			break;
		}
	}
}

void MGPIO_voidSetOutputPinMode(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8type, uint8 u8speed){		//push-pull or open-drain / speed
	//check if PortA pin 13,14, 15 or portB pin 2,3,4
	if(((u8portCpy==PORT_A)&&(u8pinCpy==GPIO_PIN13||u8pinCpy==GPIO_PIN14||u8pinCpy==GPIO_PIN15))||((u8portCpy==PORT_B)&&(u8pinCpy==GPIO_PIN2||u8pinCpy==GPIO_PIN3||u8pinCpy==GPIO_PIN4)))
	{
		//Do Nothing
	}

	else{
		switch(u8portCpy){
		case PORT_A:
			GPIO_A -> OTYPER &=~(ONE_BIT_MUSK << u8pinCpy);
			GPIO_A -> OTYPER |= (u8type<< u8pinCpy);
			//speed
			GPIO_A -> OSPEEDR &=~(TWO_BIT_MUSK << u8pinCpy*2);
			GPIO_A -> OSPEEDR |= (u8speed << (u8pinCpy*2));
			break;



		case PORT_B:
			GPIO_B -> OTYPER &=~(ONE_BIT_MUSK<<u8pinCpy);
			GPIO_B -> OTYPER |= (u8type << u8pinCpy);

			GPIO_B -> OSPEEDR &=~(TWO_BIT_MUSK << u8pinCpy*2);
			GPIO_B -> OSPEEDR |= (u8speed << (u8pinCpy*2));
			break;


		case PORT_C:
			GPIO_C -> OTYPER &=~(ONE_BIT_MUSK<<u8pinCpy);
			GPIO_C -> OTYPER |= (u8type << u8pinCpy);

			GPIO_C -> OSPEEDR &=~(TWO_BIT_MUSK << u8pinCpy*2);
			GPIO_C -> OSPEEDR |= (u8speed << (u8pinCpy*2));
			break;
		default:
			break;
		}
	}
}


void MGPIO_voidSetInputPinMode(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8pullupdown){			//pull-up/pull-down
	//check if PortA pin 13,14, 15 or portB pin 2,3,4
	if(((u8portCpy==PORT_A)&&(u8pinCpy==GPIO_PIN13||u8pinCpy==GPIO_PIN14||u8pinCpy==GPIO_PIN15))||((u8portCpy==PORT_B)&&(u8pinCpy==GPIO_PIN2||u8pinCpy==GPIO_PIN3||u8pinCpy==GPIO_PIN4)))
	{
		//Do Nothing
	}
	else{
		switch(u8portCpy){
		case PORT_A:
			//bitmasking
			GPIO_A -> PUPDR &=~(TWO_BIT_MUSK<<u8pinCpy*2);
			GPIO_A -> PUPDR |= (u8pullupdown<< (u8pinCpy*2));
			break;

		case PORT_B:
			GPIO_B -> PUPDR &=~ (TWO_BIT_MUSK<<u8pinCpy*2);
			GPIO_B -> PUPDR |= (u8pullupdown<< (u8pinCpy*2));
			break;

		case PORT_C:
			GPIO_C -> PUPDR &=~(TWO_BIT_MUSK<<u8pinCpy*2);
			GPIO_C -> PUPDR |= (u8pullupdown<< (u8pinCpy*2));
			break;
		default:
			break;
		}

	}
}
/*void MGPIO_voidGetPinValue(uint8 u8portCpy, uint8 u8pinCpy, uint8 *pData){
	//check if PortA pin 13,14, 15 or portB pin 2,3,4
	if(((u8portCpy==PORT_A)&&(u8pinCpy==GPIO_PIN13||u8pinCpy==GPIO_PIN14||u8pinCpy==GPIO_PIN15))||((u8portCpy==PORT_B)&&(u8pinCpy==GPIO_PIN2||u8pinCpy==GPIO_PIN3||u8pinCpy==GPIO_PIN4)))
		{
			//Do Nothing
		}
	else{
		switch(u8portCpy){
		case PORT_A:
			pData = GET_BIT(GPIO_A -> IDR, u8pinCpy);
			break;

		case PORT_B:
			pData = GET_BIT(GPIO_B -> IDR, u8pinCpy);
			break;

		case PORT_C:
			pData = GET_BIT(GPIO_C -> IDR, u8pinCpy);

			break;
		default:
			break;
		}

	}
}*/
uint32 MGPIO_u32GetPinValue(uint8 u8portCpy, uint8 u8pinCpy){
	uint32 u32DataCpy=0;

	switch (u8portCpy)
	{
	case PORT_A:
		u32DataCpy= GET_BIT(GPIO_A -> IDR , u8pinCpy);

		break;

	case PORT_B:
		u32DataCpy= GET_BIT(GPIO_B->IDR , u8pinCpy);

		break;

	case PORT_C:
		u32DataCpy= GET_BIT(GPIO_C->IDR , u8pinCpy);
		break;

	}
	return u32DataCpy;
}
void MGPIO_voidSetPinValue(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8Data){		// high/low
	//check if PortA pin 13,14, 15 or portB pin 2,3,4
	if(((u8portCpy==PORT_A)&&(u8pinCpy==GPIO_PIN13||u8pinCpy==GPIO_PIN14||u8pinCpy==GPIO_PIN15))||((u8portCpy==PORT_B)&&(u8pinCpy==GPIO_PIN2||u8pinCpy==GPIO_PIN3||u8pinCpy==GPIO_PIN4)))
	{
		//Do Nothing
	}
	else{
		switch(u8portCpy){
		case PORT_A:
			GPIO_A -> ODR &=~(ONE_BIT_MUSK<<u8pinCpy);
			GPIO_A -> ODR |= (u8Data<< (u8pinCpy));
			break;

		case PORT_B:
			GPIO_B -> ODR &=~ (ONE_BIT_MUSK<<u8pinCpy);
			GPIO_B -> ODR |= (u8Data<< (u8pinCpy));
			break;

		case PORT_C:
			GPIO_C -> ODR &=~(ONE_BIT_MUSK<<u8pinCpy);
			GPIO_C -> ODR |= (u8Data<< (u8pinCpy));
			break;
		default:
			break;

		}

	}
}

void MGPIO_voidPortSet_Reset(uint8 u8portCpy, uint8 u8pinCpy, uint8 u8Data){
	//check if PortA pin 13,14, 15 or portB pin 2,3,4
	if(((u8portCpy==PORT_A)&&(u8pinCpy==GPIO_PIN13||u8pinCpy==GPIO_PIN14||u8pinCpy==GPIO_PIN15))||((u8portCpy==PORT_B)&&(u8pinCpy==GPIO_PIN2||u8pinCpy==GPIO_PIN3||u8pinCpy==GPIO_PIN4)))
	{
		//Do Nothing
	}
	else{
		switch(u8portCpy){
		case PORT_A:
			GPIO_A -> BSRR &=~(ONE_BIT_MUSK<<u8pinCpy);
			GPIO_A -> BSRR |= (u8Data<< (u8pinCpy));
			break;

		case PORT_B:
			GPIO_B -> BSRR &=~ (ONE_BIT_MUSK<<u8pinCpy);
			GPIO_B -> BSRR |= (u8Data<< (u8pinCpy));
			break;

		case PORT_C:
			GPIO_C -> BSRR &=~(ONE_BIT_MUSK<<u8pinCpy);
			GPIO_C -> BSRR |= (u8Data<< (u8pinCpy));
			break;
		default:
			break;

		}

	}
}

void MGPIO_voidSetAlt(uint8 u8portCpy, uint8 u8pinCpy, PIN_ALTERNATE_t u8AltFun){
	//check if PortA pin 13,14, 15 or portB pin 2,3,4
	if(((u8portCpy==PORT_A)&&(u8pinCpy==GPIO_PIN13||u8pinCpy==GPIO_PIN14||u8pinCpy==GPIO_PIN15))||((u8portCpy==PORT_B)&&(u8pinCpy==GPIO_PIN2||u8pinCpy==GPIO_PIN3||u8pinCpy==GPIO_PIN4)))
	{
		//Do Nothing
	}
	else{

		if(u8pinCpy <= 7){
			switch (u8portCpy) {
			case PORT_A:
				GPIO_A->AFRL &=~ (FOUR_BIT_MASK << (u8pinCpy*4));
				GPIO_A->AFRL |=(u8AltFun << (u8pinCpy*4));
				break;
			case PORT_B:
				GPIO_B->AFRL &=~ (FOUR_BIT_MASK << (u8pinCpy*4));
				GPIO_B->AFRL |=(u8AltFun << (u8pinCpy*4));
				break;
			case PORT_C:
				GPIO_C->AFRL &=~ (FOUR_BIT_MASK << (u8pinCpy*4));
				GPIO_C->AFRL |=(u8AltFun << (u8pinCpy*4));
				break;
			}
		}
		else if((u8pinCpy > 7) && (u8pinCpy <=15))
		{
			switch (u8portCpy) {
			case PORT_A:
				GPIO_A->AFRH &=~ (FOUR_BIT_MASK << ((u8pinCpy%8)*4));
				GPIO_A->AFRH |=(u8AltFun << ((u8pinCpy%8)*4));
				break;
			case PORT_B:
				GPIO_B->AFRH &=~ (FOUR_BIT_MASK << ((u8pinCpy%8)*4));
				GPIO_B->AFRH |=(u8AltFun << ((u8pinCpy%8)*4));
				break;
			case PORT_C:
				GPIO_C->AFRH &=~ (FOUR_BIT_MASK << ((u8pinCpy%8)*4));
				GPIO_C->AFRH |=(u8AltFun << ((u8pinCpy%8)*4));
				break;
			}
		}
	}
}
