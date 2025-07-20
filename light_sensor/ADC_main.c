/*
 * ADC_main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: brbar
 */
/* include LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <math.h>
#define F_CPU 8000000UL
#include <util/delay.h>


/* Include Driver Files */
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

//MCAL
#include"DIO_interface.h"
//HAL
#include"LCD_interface.h"







int main()
{
	u8 Local_u8Brightness,Local_u8BrightnessLevel;
	u16 Local_u16Digital,Local_u16AnalogValue;
	DIO_Init();
	LCD_voidInit();
	ADC_voidInit();
	while(1)
	{
		//read digital value
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16Digital);
		//get analog value
		Local_u16AnalogValue=(Local_u16Digital*250000UL)/1024;//since the highest room temp = 50 celsius
		Local_u8Brightness=trunc(Local_u16AnalogValue/100);
		//turning on the lights
		switch(Local_u8Brightness)
		{
		case  2:Local_u8BrightnessLevel=1;LED1234();break;
		case  12:Local_u8BrightnessLevel=2;LED1234();break;
		case  24:Local_u8BrightnessLevel=3;LED123();break;
		case  48:Local_u8BrightnessLevel=4;LED123();break;
		case  119:Local_u8BrightnessLevel=5;LED12();break;
		case  227:Local_u8BrightnessLevel=6;LED12();break;
		case  161:Local_u8BrightnessLevel=7;LED1();break;
		case  177:Local_u8BrightnessLevel=8;LED1();break;
		case  82:Local_u8BrightnessLevel=9;NOLED();break;
		case  100:Local_u8BrightnessLevel=10;NOLED();break;
		default:NOLED();break;

		}

		//turning on LCD
		LCD_voidSendString("brightness level=");
		LCD_voidGoToRowColumn(1,5);
		LCD_voidSendNum(Local_u8BrightnessLevel);
		_delay_ms(50);
		LCD_voidClear();
		_delay_ms(50);
	}

	return 0;
}

