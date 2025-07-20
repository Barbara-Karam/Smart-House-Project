/*
 * ADC_main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: brbar
 */
/* include LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>


/* Include Driver Files */
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

//MCAL
#include"DIO_interface.h"
#include"TMR_interface.h"
//HAL
#include"LCD_interface.h"


int main()
{
	u8 Local_u8Temp;
	u16 Local_u16Digital,Local_u16AnalogValue;
	DIO_Init();
	LCD_voidInit();
	ADC_voidInit();
	TMR_voidTimer0Init();

	while(1)
	{
		//read digital value
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16Digital);
		//get analog value
		Local_u16AnalogValue=(Local_u16Digital*5000UL)/1024;//since the highest room temp = 50 celsius
		Local_u8Temp=Local_u16AnalogValue/10;
		//turning on the fan
		u8 Local_u8CompareMatchValue=Local_u8Temp*5;
		if(Local_u8Temp>=21)
		{TMR_voidTimer0SetCompareMatchValue(Local_u8CompareMatchValue);}
		//turning on LCD
		LCD_voidSendString("Temperature in celsius =");
		LCD_voidGoToRowColumn(1,0);
		LCD_voidSendNum(Local_u8Temp);
		_delay_ms(50);
		LCD_voidClear();
		_delay_ms(50);
	}

	return 0;
}

