/*
 * HTFT_config.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Tasneem
 */

#ifndef HTFT_CONFIG_H_
#define HTFT_CONFIG_H_


#define TFT_RESOLUTION			   20480
#define TFT_PORT				   PORT_A
#define TFT_RESET_PORT			   PORT_C

#define TFT_RESET_PIN              GPIO_PIN15
#define TFT_A0_PIN                 GPIO_PIN1
#define TFT_SCK                    GPIO_PIN5
#define TFT_DATA_PIN               GPIO_PIN7



#define TFT_COLOR_STANDARD                            TFT_DATA_RGB_565
/*

TFT_DATA_RGB_444
TFT_DATA_RGB_565
TFT_DATA_RGB_666

*/


#define START_X_BYTE2				0
#define START_X_BYTE1				0

#define END_X_BYTE2					0
#define END_X_BYTE1					127

#define START_Y_BYTE2				0
#define START_Y_BYTE1				0

#define END_Y_BYTE2					0
#define END_Y_BYTE1					159


#endif /* HTFT_CONFIG_H_ */
