/*
 * MRTC_interface.h
 *
 *  Created on: Mar 8, 2024
 *      Author: Tasneem
 */

#ifndef MRTC_INTERFACE_H_
#define MRTC_INTERFACE_H_

#define Monday 		1
#define Tuesday 	2
#define Wednesday 	3
#define Thurday 	4
#define Friday 		5
#define Saturday	6
#define Sunday 		7

#define	January		1
#define	February	2
#define	March		3
#define	April		4
#define	May			5
#define	June		6
#define	July		7
#define	August		8
#define	September	9
#define	October		10
#define	November	11
#define	December	12

/**********************************************/


typedef struct RTC_Time{
	uint8 hours;
	uint8 minutes;
	uint8 seconds;
	uint8 milliseconds;
}RTC_Time;

typedef struct RTC_Date{
	uint8 day;
	uint8 month;
	uint16 year;
	uint8 week_day;
}RTC_Date;

/**********************************************/
void RCC_LSE_ENABLE(void);
void RTC_WPR_DISALBE(void);
void MRTC_voidInit(void);


void MRTC_voidSet_Time(RTC_Time *Time);
void MRTC_voidSet_Date(RTC_Date *Date);

void MRTC_voidGet_Time(RTC_Time *Time);
void MRTC_voidGet_Date(RTC_Date *Date);

void MRTC_voidStart(void);




#endif /* MRTC_INTERFACE_H_ */
