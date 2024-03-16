/*
 * GPIO_private.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Tasneem
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIO_A_BASE_ADDRESS			0x40020000
#define GPIO_B_BASE_ADDRESS			0x40020400
#define GPIO_C_BASE_ADDRESS  		0x40020800

typedef struct{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_t;

#define 	GPIO_A	((volatile GPIO_t*)(GPIO_A_BASE_ADDRESS))
#define 	GPIO_B	((volatile GPIO_t*)(GPIO_B_BASE_ADDRESS))
#define 	GPIO_C	((volatile GPIO_t*)(GPIO_C_BASE_ADDRESS))


#endif /* GPIO_PRIVATE_H_ */
