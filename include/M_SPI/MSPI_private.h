/*
 * MSPI_private.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Tasneem
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS  0x40013000
#define SPI2_BASE_ADDRESS  0x40003800
#define SPI3_BASE_ADDRESS  0x40003C00
#define SPI4_BASE_ADDRESS  0x40013400

typedef struct{
	uint32 SPI_CR1;
	uint32 SPI_Reserved1;
	uint32 SPI_SR;
	uint32 SPI_DR;
	uint32 SPI_CRCPR;
	uint32 SPI_RXCRCR;
	uint32 SPI_TXCRCR;
	uint32 SPI_I2SCFGR;
	uint32 SPI_I2SPR;
}SPI_t;

#define SPI1		 ((volatile SPI_t*) (SPI1_BASE_ADDRESS))
#define SPI2 		 ((volatile SPI_t*) (SPI2_BASE_ADDRESS))
#define SPI3 		 ((volatile SPI_t*) (SPI3_BASE_ADDRESS))
#define SPI4		 ((volatile SPI_t*) (SPI4_BASE_ADDRESS))
/**********SPI_CR1**********/
#define CR1_DFF 	 11
#define CR1_SSM		 9
#define CR1_SSI		 8
#define CR1_LSBFIRST 7
#define CR1_SPE 	 6
#define CR1_BR 		 3
#define CR1_MSTR 	 2
#define CR1_CPOL 	 1
#define CR1_CPHA 	 0

/**********SPI_SR***********/
#define SR_BSY  	7
#define SR_TXE  	1
#define SR_RXNE 	0


/*************************************/
#define MASTER_MODE					0
#define SLAVE_MODE					1
#define BIT_SIZE_8 		 			0
#define BIT_SIZE_16 				1

#define CLK_POLARITY_RISING_IDLE0			0
#define CLK_POLARITY_FALLING_IDLE1			1

#define CLK_PHASE_SAMPLE_FIRST 		0
#define CLK_PHASE_SETUP_FIRST	 	1

#define MUSK_3BITS					7
#define CLK_BAUDRATE_2   			0
#define CLK_BAUDRATE_4   			1
#define CLK_BAUDRATE_8   			2
#define CLK_BAUDRATE_16 			3
#define CLK_BAUDRATE_32 			4
#define CLK_BAUDRATE_64  			5
#define CLK_BAUDRATE_128 			6
#define CLK_BAUDRATE_256 			7

#define MSB_FIRST 					0
#define LSB_FIRST 					1

#define HW_MANAGED					0
#define SW_MANAGED					1


#define NSS_DISABLED				1
#define NSS_ENABLED					0
#endif /* MSPI_PRIVATE_H_ */
