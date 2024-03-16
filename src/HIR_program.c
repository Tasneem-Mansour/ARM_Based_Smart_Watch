/*
 * HIR_program.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Tasneem
 */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "M_GPIO/MGPIO_interface.h"
#include "M_SYSTICK/MSYSTICK_interface.h"
#include "H_IR/HIR_interface.h"

volatile uint8 startflag=0;   			//to know falling edge is the first falling edge or no
volatile uint32 FrameData[50]={0};  		//frame =33 but it more
volatile uint8 EdgeCounter=0;
volatile uint8 Data=0;
uint8 i=0;
uint8 flag=0;


void voidPlay(void)
{
	switch(Data)
	{
	case 4:  			//red
		flag=4;
		break;
	case 5:  			//green
		flag=5;
		break;
	case 6:  			//blue
		flag=6;
		break;
	case 7:  			//reset
		flag=7;
		break;
	default:
		break;
	}
}



void voidTackAction()
{
	uint8 i;
	Data=0;
	if((FrameData[0]>=20000)&&(FrameData[0]<=50000))
	{
		for(i=0;i<8;i++)
		{
			//Data[17]->is the first byte in data
			if((FrameData[17+i]>=3801) && (FrameData[17+i]<=8000))
			{
				SET_BIT(Data,i);
			}
			else
			{
				CLR_BIT(Data,i);
			}
		}
		voidPlay();
	}
	else
	{
		//Invalid fram
	}
	startflag=0;
	FrameData[0]=0;
	EdgeCounter=0;
	//asm("NOP");

}

void voidGetFrame(void)
{
	if(startflag==0)  // it is a first falling edge
	{
		//start timer  ---> 1000000tick->1sec
		MSYSTICK_voidSetInterval_single(1000000,voidTackAction);
		startflag=1;
	}

	else
	{
		FrameData[EdgeCounter]=MSYSTICK_u32GetElapsedTime();
		MSYSTICK_voidSetInterval_single(1000000,voidTackAction);
		EdgeCounter++;
	}
	//asm("NOP");
}
