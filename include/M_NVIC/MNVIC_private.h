/*
 * MNVIC_private.h
 *
 *  Created on: Jan 17, 2024
 *      Author: Tasneem
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_


#define  NVIC_BASE_ADDRESS		0xE000E100
#define  AIRCR_BASE_ADDRESS		0xE000ED0C		//SCB to define groups and sub-groups


typedef struct{
	uint32 NVIC_ISER[8];
	uint32 reserved0[24];
	uint32 NVIC_ICER[8];
	uint32 reserved1[24];
	uint32 NVIC_ISPR[8];
	uint32 reserved2[24];
	uint32 NVIC_ICPR[8];
	uint32 reserved3[24];
	uint32 NVIC_IABR[8];
	uint32 reserved4[56];
	uint8  NVIC_IPR[240];
	uint32 reserved5[580];
	uint32 NVIC_STIR;
}NVIC_t;


#define NVIC				((volatile NVIC_t*) (NVIC_BASE_ADDRESS))
#define SCB_AIRCR			(*(volatile uint32*) (AIRCR_BASE_ADDRESS))
#define NVIC_VECTKEY  		0x05FA0000

#endif /* MNVIC_PRIVATE_H_ */


