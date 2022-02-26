/*
 * SEGMENT.c
 *
 * Created: 26-Feb-22 1:48:35 PM
 *  Author: lenovo
 */ 

#include "SEGMENT.h"

 static u8 SegNums[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 static u8 SegNumsRev[]={0x6F,0x7F,0x07,0x7D,0x6D,0x66,0x4F,0x5B,0x06,0x3F};
 static u8 SegNumsRevshort[]={0x06,0x3F};
	
void SEGMENT1_Display(u8 num1)
{
	DIO_SetPortValue(PORT_C,SegNumsRevshort[num1]);	
}
void SEGMENT2_Display(u8 num1)
{
	DIO_SetPortValue(PORT_D,SegNumsRev[num1]);
}