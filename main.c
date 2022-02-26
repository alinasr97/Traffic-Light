/*
 * Drivers.c
 *
 * Created: 23-Feb-22 6:27:18 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "UTILS.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "HB_Interface.h"
#include "SEGMENT.h"

 
/**************************Traffic Lights*************************/

int main(void)
{
	DIO_SetPortDirection(PORT_A,OUTPUT);
	DIO_SetPortDirection(PORT_C,OUTPUT);
	DIO_SetPortDirection(PORT_D,OUTPUT);
	u8 lamps[]={0,1,2};
	u8 *p=lamps;
    while (1) 
    {
		u8 i,j;
		if(*p==0) //red
		{
			DIO_SetPinValue(PORT_A,PIN0,HIGH);
			DIO_SetPinValue(PORT_A,PIN1,LOW);
			DIO_SetPinValue(PORT_A,PIN2,LOW);
			for(i=0;i<=1;i++)
			{
				SEGMENT1_Display(i);
				for(j=0;j<=9;j++)
				{
					SEGMENT2_Display(j);
					_delay_ms(400);
				}
			}
			p++;
		}
		if(*p==1) //yellow
		{
			DIO_SetPinValue(PORT_A,PIN0,LOW);
			DIO_SetPinValue(PORT_A,PIN1,HIGH);
			DIO_SetPinValue(PORT_A,PIN2,LOW);
			for(i=1;i>0;i--)
			{
				SEGMENT1_Display(i);
				for(j=0;j<=9;j++)
				{
					SEGMENT2_Display(j);
					_delay_ms(400);
				}
			}
			p++;
		}
		if(*p==2) //green
		{
			DIO_SetPinValue(PORT_A,PIN0,LOW);
			DIO_SetPinValue(PORT_A,PIN1,LOW);
			DIO_SetPinValue(PORT_A,PIN2,HIGH);
			for(i=0;i<=1;i++)
			{
				SEGMENT1_Display(i);
				for(j=0;j<=9;j++)
				{
					SEGMENT2_Display(j);
					_delay_ms(400);
				}
			}
			p=lamps;
			}
	}
}

