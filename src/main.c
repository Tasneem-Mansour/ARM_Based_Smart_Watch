#include "STD_Types.h"
#include "BIT_Math.h"
#include <stdio.h>
#include "M_RCC/MRCC_interface.h"
#include "M_GPIO/MGPIO_interface.h"
#include "M_SYSTICK/MSYSTICK_interface.h"
#include "M_RTC/MRTC_interface.h"
#include "M_EXTI/MEXTI_interface.h"
#include "M_NVIC/MNVIC_interface.h"
#include "H_KeyPad/HKPD_interface.h"
#include "M_SPI/MSPI_interface.h"
#include "H_STP/HSTP_interface.h"
#include "H_TFT/HTFT_interface.h"
#include "H_IR/HIR_interface.h"

#include "H_TFT/F_TFT_Images/LockScreen.h"
#include "H_TFT/F_TFT_Images/HomeScreen1.h"
#include <H_TFT/F_TFT_Images/Spotify/HomeScreen2.h>
#include <H_TFT/F_TFT_Images/Spotify/HomeScreen2_1.h>
#include <H_TFT/F_TFT_Images/Spotify/HomeScreen2_1_1.h>
#include <H_TFT/F_TFT_Images/Spotify/HomeScreen2_2_1.h>
#include "H_TFT/F_TFT_Images/Contacts.h"
#include "H_TFT/F_TFT_Images/Game.h"

#include "H_R2R_DAC/HR2RDAC_interface.h"
#include "H_R2R_DAC/F_DAC_Songs/Song1.h"
#include "H_R2R_DAC/F_DAC_Songs/Song2.h"

RTC_Time TIME;
RTC_Date DATE;
uint8 Time_Str[20];
uint8 Date_Str[20];

uint8 textPosX = (127 - (8 * 9)) / 2; 		// 8 pixels per character, 9 characters in time format (including colons)
uint8 textPosY = (159 - 16) / 2; 			// 16 pixels for the font height

extern uint8 flag;
uint16 Global_u16KEY;
uint16 Global_u16KEY_S;
//const uint16 u16Arr_Images[]={u16HomeScreen2_1, u16HomeScreen2_1_1,u16HomeScreen2_2_1, u16Contacts};
//const uint16 u32Arr_Songs[]={Song1, Song2};

void LED_MATRIX_ON(void);

int main(){
	MRCC_voidInitClk();
	MRCC_voidEnablePeripheralClk(RCC_AHB1, AHB1_GPIOA);
	MRCC_voidEnablePeripheralClk(RCC_AHB1, AHB1_GPIOB);
	MRCC_voidEnablePeripheralClk(RCC_AHB1, AHB1_GPIOC);
	MRCC_voidEnablePeripheralClk(RCC_APB2, APB2_SPI1);

	MSYSTICK_voidInit();
	MRTC_voidInit();
	MSPI1_voidInit();
	HKPD_voidInit();
	HR2RDAC_voidInit();						/*DO NOT FORGET TO TURN IT OFF BEFORE USING RGB LED (same pins are used)*/
	HSTP_voidInit();

	/***************Time & Date Setting*****************/
	TIME.hours = 8;
	TIME.minutes = 2;
	TIME.seconds = 00;
	TIME.milliseconds =0;

	DATE.day   = 14;
	DATE.month = March;
	DATE.year  = 2024;
	DATE.week_day = Thurday;

	MRTC_voidSet_Time(&TIME);
	MRTC_voidSet_Date(&DATE);

	/***********************EXTI************************/
	MEXTI_voidInerruptSetPort(EXTI_LineZero,EXTI_PortA);
	MEXTI0_voidCallBack(voidGetFrame);
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero , EXTI_Enable);
	MEXTI_voidInterruptTrigger(EXTI_LineZero,EXTI_Falling);

	MNVIC_voidSetInterruptGroupMode(Group16Sub0);
	MNVIC_voidSetInterruptPriority(INTPos_EXTI0,0,0);
	MNVIC_voidEnableInterrupt(INTPos_EXTI0);

	/***********************IR PINS INIT************************/
//	MGPIO_voidSetMode(PORT_A, GPIO_PIN0, GPIO_INPUT);
//	MGPIO_voidSetInputPinMode(PORT_A, GPIO_PIN0, NO_PULL);								/*Floating there is no pull*/
//
//	/*!!!!!LIMITED I/O PINS!!!!! Do no forget to disable RGB LED if you are going to use DAC*/
//	MGPIO_voidSetMode(PORT_B, GPIO_PIN1,GPIO_OUTPUT);									/*****RED*****/
//	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN1, OUTPUT_PUSH_PULL , LOW_SPEED);
//	MGPIO_voidSetMode(PORT_B, GPIO_PIN5,GPIO_OUTPUT);									/****GREEN***/
//	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN5, OUTPUT_PUSH_PULL , LOW_SPEED);
//	MGPIO_voidSetMode(PORT_B, GPIO_PIN6,GPIO_OUTPUT);									/****BLUE****/
//	MGPIO_voidSetOutputPinMode(PORT_B, GPIO_PIN6, OUTPUT_PUSH_PULL , LOW_SPEED);

	/***********************TFT************************/
	MGPIO_voidSetMode(PORT_C, GPIO_PIN15, GPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(PORT_C, GPIO_PIN15,OUTPUT_PUSH_PULL, MEDIUM_SPEED);
	MGPIO_voidSetMode(PORT_A, GPIO_PIN1, GPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(PORT_A, GPIO_PIN1,OUTPUT_PUSH_PULL, MEDIUM_SPEED);

	MGPIO_voidSetMode(PORT_A, GPIO_PIN5, GPIO_ALTERNATIVE_MODE);
	MGPIO_voidSetMode(PORT_A, GPIO_PIN7, GPIO_ALTERNATIVE_MODE);

	MGPIO_voidSetAlt(PORT_A, GPIO_PIN5,  AF5_SPI_1_4);
	MGPIO_voidSetAlt(PORT_A, GPIO_PIN7,  AF5_SPI_1_4);
	HTFT_voidInit();
	HTFT_voidDisplay(&u16LockScreen);

	/******************Get Time & Date****************/
	while(!(Global_u16KEY == 'H')){
			MRTC_voidGet_Time(&TIME);
			MRTC_voidGet_Date(&DATE);
			sprintf(Time_Str, "%02d:%02d:%02d", TIME.hours, TIME.minutes, TIME.seconds);
			sprintf(Date_Str, "%02d:%02d:%02d",DATE.day, DATE.month, DATE.year);

			HTFT_voidDrawCharacter(Time_Str, textPosX, textPosY, 3, 0xffff);
			HTFT_voidDrawCharacter(Date_Str, textPosX, textPosY, 3, 0xffff);
	}


	while(1)
	{


		/**********LED MATRIX**********/
		LED_MATRIX_ON();
		/******************************/

		Global_u16KEY = HKPD_u8GetKey();
		MSYSTICK_voidDelayms(50);

		if(Global_u16KEY == 'H'){
/***Home***/HTFT_voidDisplay(&u16HomeScreen2);
		}

		if(Global_u16KEY == 'S'){
/***Spotify***/	HTFT_voidDisplay(&u16HomeScreen2_1);

			Global_u16KEY_S = HKPD_u8GetKey();
			MSYSTICK_voidDelayms(50);

			while(!Global_u16KEY_S);
			if(Global_u16KEY_S == '1'){
				for(uint32 i=0; i<100000; i++){
					HTFT_voidDisplay(&u16HomeScreen2_1_1);
					/**********************DAC*************************/
					HR2RDAC_voidSetData(Song1, 19226);			/**********Play Song1*********/
				}
			}
//			else if(Global_u16KEY_S == '2'){
//				HTFT_voidDisplay(&u16HomeScreen2_2_1);
//				HR2RDAC_voidSetData(Song2, 28421);				/**********Play Song2*********/
//			}
			else if(Global_u16KEY_S == 'S'){
				HTFT_voidDisplay(&u16HomeScreen2_1);
			}
		}

		if(Global_u16KEY == 'C'){
/*Contacts*/HTFT_voidDisplay(&u16Contacts);
		}

		/*************************************************************************************/
//		if(Global_u16KEY == 'G'){
///***Game***/HTFT_voidDisplay(&u16Game);
//			/*Mix colors using IR Remote control snd showing them on an RGB LED*/
//			while(!flag);
//			switch(flag){
//			case 4:
//				MGPIO_voidSetPinValue(PORT_B, GPIO_PIN1, GPIO_HIGH);			/*****RED*****/
//				break;
//			case 5:
//				MGPIO_voidSetPinValue(PORT_B, GPIO_PIN5, GPIO_HIGH);			/****GREEN****/
//				break;
//			case 6:
//				MGPIO_voidSetPinValue(PORT_B, GPIO_PIN6, GPIO_HIGH);			/*****BLUE****/
//				break;
//			case 7:
//				MGPIO_voidSetPinValue(PORT_B, GPIO_PIN1, GPIO_LOW);
//				MGPIO_voidSetPinValue(PORT_B, GPIO_PIN5, GPIO_LOW);
//				MGPIO_voidSetPinValue(PORT_B, GPIO_PIN6, GPIO_LOW);
//				break;
//			default:
//				break;
//			}
//		}
		/*************************************************************************************/

	}
	return 0;
}


void LED_MATRIX_ON(void){
	HSTP_voidSendDataSynch(0xFF00);
	MSYSTICK_voidDelayUs(20);
	HSTP_voidSendDataSynch(0xFB14);
	MSYSTICK_voidDelayUs(20);
	HSTP_voidSendDataSynch(0x8522);
	MSYSTICK_voidDelayUs(20);
	HSTP_voidSendDataSynch(0x4F1C);
	MSYSTICK_voidDelayUs(20);
	HSTP_voidSendDataSynch(0x851C);
	MSYSTICK_voidDelayUs(20);
	HSTP_voidSendDataSynch(0xFB1C);
	MSYSTICK_voidDelayUs(20);
	HSTP_voidSendDataSynch(0xFF1C);
	MSYSTICK_voidDelayUs(20);
	HSTP_voidSendDataSynch(0xFF00);
	MSYSTICK_voidDelayUs(20);
}
