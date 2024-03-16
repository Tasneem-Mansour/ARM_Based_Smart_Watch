/*
 * MRTC_program.c
 *
 *  Created on: Mar 8, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "M_RCC/MRCC_interface.h"
#include "M_RCC/MRCC_private.h"
#include "M_RCC/MRCC_config.h"
#include "M_RTC/MRTC_interface.h"
#include "M_RTC/MRTC_private.h"
#include "M_RTC/MRTC_config.h"


#define RTC_INIT_MASK           0xFFFFFFFFU
#define RTC_TR_MASK             0xFF808080U



#define _HAL_PWR_CLEAR_WUF()        ( PWR->PWR_CR |= (1 << 2))
#define _HAL_PWR_CLEAR_SPF()        ( PWR->PWR_CR |= (1 << 3))


/**********************************************************/


void MRTC_voidGet_Time(RTC_Time *Time)
{
  uint32 tmpreg = (uint32)(RTC->RTC_TR & RTC_TR_RESERVED_MASK);

  /* Fill the structure fields with the read parameters */
  Time->hours      = (uint8)((tmpreg & (RTC_TR_HT  | RTC_TR_HU))  >> RTC_TR_HU_Pos);
  Time->minutes    = (uint8)((tmpreg & (RTC_TR_MNT | RTC_TR_MNU)) >> RTC_TR_MNU_Pos);
  Time->seconds    = (uint8)( tmpreg & (RTC_TR_ST  | RTC_TR_SU));
}

void MRTC_voidGet_Date(RTC_Date *Date){
  uint32 datetmpreg = (uint32)(RTC->RTC_DR & RTC_DR_RESERVED_MASK);

  Date->year    = (uint8)((datetmpreg & (RTC_DR_YT | RTC_DR_YU)) >> 16);
  Date->month   = (uint8)((datetmpreg & (RTC_DR_MT | RTC_DR_MU)) >> 8);
  Date->day    = (uint8) (datetmpreg & (RTC_DR_DT | RTC_DR_DU));
  Date->week_day = (uint8)((datetmpreg & (RTC_DR_WDU))>> 13);
}

void RCC_LSE_ENABLE(void)
{
	RCC->BDCR |= ( 1<< RCC_BDCR_LSEON );
	while(!((RCC->BDCR) & (1<<RCC_BDCR_LSERDY)));
}

void RTC_WPR_DISALBE(void)
{
	RTC->RTC_WPR = 0xCAU;
	RTC->RTC_WPR = 0x53U;
}

void MRTC_voidInit(void)
{
	MRCC_voidEnablePeripheralClk(RCC_APB1, APB1_PWR);				/*enable peripheral clock power*/

  	PWR->PWR_CR |= (1<<PWR_CR_DBP);									/*enable access to RTC and RTC Backup registers*/

	RCC_LSE_ENABLE();

	RCC->BDCR |= ( 1 << RCC_BDCR_RTCSEL);

	RCC->BDCR |= 1<<RCC_BDCR_RTCEN;

	 RTC_WPR_DISALBE();

	RTC->RTC_ISR |= (1<<RTC_ISR_INIT);
	while(!(RTC -> RTC_ISR & RTC_ISR_INITF));

	RTC->RTC_PRER |= ((0x7F) << (RTC_PRER_PREDIV_A));
	RTC->RTC_PRER |= ((0xFF) << (RTC_PRER_PREDIV_S));

	/********configure the time format********/
	#if RTC_TIME_FORMAT==TIME_FORMAT_12H
		RTC -> RTC_CR |= 1 << RTC_CR_FMT;
	#elif RTC_TIME_FORMAT==TIME_FORMAT_24H
		RTC -> RTC_CR &=~ (1 << RTC_CR_FMT);
	#endif

	RTC -> RTC_ISR &=~ (1 << RTC_ISR_INIT); 						/*exit initialization mode*/
	RTC -> RTC_WPR = 0xFF;			 								/*disable write protection for RTC registers*/
}



void MRTC_voidSet_Time(RTC_Time *Time){
	uint8 HourTens,HourUints,MinTens,MinUnits,SecTens,SecUints;

	uint32 RTC_Time;
	RTC_WPR_DISALBE();
	RTC->RTC_ISR |= (1<<RTC_ISR_INIT);
	while(!(RTC -> RTC_ISR & RTC_ISR_INITF));

	HourTens = Time->hours / 10;
	HourUints = Time->hours % 10;

	MinTens = Time->minutes / 10;
	MinUnits = Time->minutes % 10;

	SecTens =  Time->seconds / 10;
	SecUints = Time->seconds % 10;

	RTC_Time = (uint32)((((HourTens << RTC_TR_HT_Pos) | (HourUints << RTC_TR_HU_Pos)) &((RTC_TR_HT) | (RTC_TR_HU)))| \
			(((MinTens << RTC_TR_MNT_Pos) | (MinUnits << RTC_TR_MNU_Pos)) &((RTC_TR_MNT) | (RTC_TR_MNU)))| \
			(((SecTens << RTC_TR_ST_Pos) | (SecUints << RTC_TR_SU_Pos)) &((RTC_TR_ST) | (RTC_TR_SU))));
	RTC->RTC_TR = RTC_Time;
	RTC->RTC_CR &= (uint32)~(0x1UL << 18U);

	RTC -> RTC_ISR &=~ (1 << RTC_ISR_INIT); 				/*exit initialization mode*/
	RTC -> RTC_WPR = 0xFF;			 						/*disable write protection for RTC registers*/
//	MRTC_voidStart();
}
void MRTC_voidSet_Date(RTC_Date *Date){
	uint8 YearTens, YearUints, WeekDay, MonthTens, MonthUints, DateTens, DateUnits;
	uint32 RTC_Date;
	RTC_WPR_DISALBE();
	RTC->RTC_ISR |= (1<<RTC_ISR_INIT);
	while(!(RTC -> RTC_ISR & RTC_ISR_INITF));

	Date->year = Date -> year - 2000;

	YearTens = Date->year / 10;
	YearUints = Date->year % 10;

	MonthTens = Date->month / 10;
	MonthUints = Date->month % 10;

	WeekDay = Date->week_day;

	DateTens = Date->day / 10;
	DateUnits = Date->day % 10;

	RTC_Date = (uint32)((((YearTens << RTC_DR_YT_Pos) | (YearUints << RTC_DR_YU_Pos)) &((RTC_DR_YT) | (RTC_DR_YU)))| \
				((WeekDay << RTC_DR_WDU_Pos)&(RTC_DR_WDU))|\
				(((MonthTens << RTC_DR_MT_Pos) | (MonthUints << RTC_DR_MU_Pos)) &((RTC_DR_MT) | (RTC_DR_MU)))| \
				(((DateTens << RTC_DR_DT_Pos) | (DateUnits << RTC_DR_DU_Pos)) &((RTC_DR_DT) | (RTC_DR_DU))));

	RTC->RTC_DR = RTC_Date;

	MRTC_voidStart();
}
void MRTC_voidStart(void){

//	RTC->RTC_TR = (uint32)( 0x00081233 & RTC_TR_RESERVED_MASK);
	RTC->RTC_CR &= (uint32)~(0x1UL << 18U);
	
	RTC -> RTC_ISR &=~ (1 << RTC_ISR_INIT); 				/*exit initialization mode*/
	RTC -> RTC_WPR = 0xFF;			 						/*disable write protection for RTC registers*/
}






//void MRTC_voidGet_Time(RTC_Time *Time){
//	uint8 HourTens, HourUints, MinTens, MinUnits, SecTens, SecUints;
//	while (!(RTC->RTC_ISR & RTC_ISR_INITS));
//	uint32 RTC_Time=0;
//	RTC_Time = RTC->RTC_TR & RTC_TR_RESERVED_MASK;

//	HourTens  =	(uint8)((RTC_Time & RTC_TR_HT_Msk)>> RTC_TR_HT);
//	HourUints = (uint8)((RTC_Time & RTC_TR_HU_Msk)>> RTC_TR_HU);
//	Time->hours = (uint8)((HourTens * 10) + HourUints);

//	MinTens   = (uint8)((RTC_Time & RTC_TR_MT_Msk)>> RTC_TR_MT);
//	MinUnits  = (uint8)((RTC_Time & RTC_TR_MU_Msk)>> RTC_TR_MU);
//	Time->minutes = (uint8)((MinTens * 10) + MinUnits);

//	SecTens   = (uint8)((RTC_Time & RTC_TR_ST_Msk)>> RTC_TR_ST);
//	SecUints  = (uint8)((RTC_Time & RTC_TR_SU_Msk)>> RTC_TR_SU);
//	Time->seconds = (uint8)((SecTens * 10) + SecUints);
//}




//void MRTC_voidGet_Date(RTC_Date *Date){
//	uint8 YearTens,YearUints, MonthTens,MonthUints, DayTens, DayUnits;
//	while (!(RTC->RTC_ISR & RTC_ISR_INITS));
//	uint32 RTC_Date=0;
//	RTC_Date = RTC->RTC_TR & RTC_DR_RESERVED_MASK;

//	YearTens   = (uint8) ((RTC_Date & RTC_DR_YT_Msk)) >> RTC_DR_YT;
//	YearUints  = (uint8) ((RTC_Date & RTC_DR_YU_Msk)) >> RTC_DR_YU;
//	Date -> year =(uint16)(2000 + (YearTens * 10) + YearUints);

//	MonthTens  = (uint8) ((RTC_Date & RTC_DR_MT_Msk)) >> RTC_DR_MT;
//	MonthUints = (uint8) ((RTC_Date & RTC_DR_MU_Msk)) >> RTC_DR_MU;
//	Date -> month = (uint8) ((MonthTens * 10) + MonthUints);

//	DayTens   = (uint8) ((RTC_Date & RTC_DR_DT_Msk)) >> RTC_DR_DT;
//	DayUnits  = (uint8) ((RTC_Date & RTC_DR_DU_Msk)) >> RTC_DR_DU;
//	Date -> day = (uint8) ((DayTens * 10) + DayUnits);

//}






