/*
 * MSPI_program.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "M_SPI/MSPI_interface.h"
#include "M_SPI/MSPI_config.h"
#include "M_SPI/MSPI_private.h"


void MSPI1_voidInit(void){
//	/*disable SPI*/
//	SPI1-> SPI_CR1 &=~ (1<<CR1_SPE);
	/*Set data frame size*/
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_DFF)) | (DATA_SIZE<<CR1_DFF);
	/*Clock polarity*/
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_CPOL)) | (CLK_POLARITY<<CR1_CPOL);
	/*Clock phase*/
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_CPHA)) | (CLK_PHASE<<CR1_CPHA);
	/*Set Frame Format*/
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_LSBFIRST)) | (FRAME_FORMAT<<CR1_LSBFIRST);


#if SPI_OPERATION_MODE == MASTER_MODE
	/*Set BaudRate*/
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(MUSK_3BITS<<CR1_BR)) | (CLK_BAUDRATE<<CR1_BR);

	/*Master selection*/
	SPI1->SPI_CR1 |= (1<<CR1_MSTR);
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_SSM))| (MASTER_SSM_MODE<<CR1_SSM);			/*0->managed by HW(needs pin), 1->managed by SW*/
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_SSI))| (MASTER_SSI_MODE<<CR1_SSI);      		/*Disable NSS*/

#elif SPI_OPERATION_MODE == SLAVE_MODE
	/*Slave selection*/
	SPI1->SPI_CR1 &=~ (1<<CR1_MSTR);
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_SSM))| (SLAVE_SSM_MODE<<CR1_SSM);
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CR1_SSI))| (SLAVE_SSI_MODE<<CR1_SSI);				/*Enable NSS*/
#endif

	/*disable SPI*/
	SPI1-> SPI_CR1 |= (1<<CR1_SPE);
}

uint16 MSPI1_u16Transceive(uint16 Cpy_u16SendData){

	SPI1-> SPI_DR = Cpy_u16SendData;
	while(GET_BIT(SPI1->SPI_SR, SR_BSY)==1);

	return (uint16)(SPI1-> SPI_DR);
}


