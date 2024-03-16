/*
 * MNVIC_interface.c
 *
 *  Created on: Jan 17, 2024
 *      Author: Tasneem
 */

#ifndef MNVIC_INTERFACE_C_
#define MNVIC_INTERFACE_C_
typedef enum{
 Group16Sub0=3,
 Group8Sub2,
 Group4Sub4,
 Group2Sub8,
 Group0Sub16

}MNVIC_Group_t;
#define Reg_div 	32

#define INTPos_EXTI0    6
#define INTPos_EXTI1    7
#define INTPos_EXTI2    8
#define INTPos_EXTI3    9
#define INTPos_EXTI4    10

void MNVIC_voidEnableInterrupt(uint8 u8positionCpy);
void MNVIC_voidDisableInterrupt(uint8 u8positionCpy);
void MNVIC_voidEnableInterruptBending(uint8 u8positionCpy);
void MNVIC_voidDisableInterruptBending(uint8 u8positionCpy);
void MNVIC_voidSetInterruptGroupMode(MNVIC_Group_t uddtGroupModeCpy); //AIRCR --> how many groups and sub-groups in our MCU
void MNVIC_voidSetInterruptPriority(uint8 u8IntPosCpy,uint8 u8GroupNumCpy,uint8 u8SubGroupNumCpy) ;
void MNVIC_u8IsInterruptActive(uint8 u8positionCpy,uint8 *ReadDataCpy) ;

#endif /* MNVIC_INTERFACE_C_ */







