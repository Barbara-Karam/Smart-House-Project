/*
 * KPD_main.c
 *
 *  Created on: Sep 10, 2022
 *      Author: brbar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define CPU 8000000UL
#include <util/delay.h>

#include"DIO_interface.h"

#include "LCD_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

void LED_voidBlink (void)
{
	for(u32 counter=0;counter<=4294967295;counter++)
	{
		DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);
		_delay_ms(100);
	}


}


int main()
{

	DIO_Init();
	LCD_voidInit();
	u8 Local_variable,NUM,counter=3,idk=0;
	u32 ID1=0,ID2=0;
	LCD_voidSendString("enter your pass");
	while(1)
	{
		KPD_u8GetKey(& Local_variable);
		if (Local_variable != 0xFF)
		{
			if(idk==0){LCD_voidClear();idk=1;}
			LCD_voidSendChar(Local_variable);

			switch(Local_variable)
			{
			case '0' :NUM=0;ID1=(ID1*10)+NUM;break;
			case '1' :NUM=1;ID1=(ID1*10)+NUM;break;
			case '2' :NUM=2;ID1=(ID1*10)+NUM;break;
			case '3' :NUM=3;ID1=(ID1*10)+NUM;break;
			case '4' :NUM=4;ID1=(ID1*10)+NUM;break;
			case '5' :NUM=5;ID1=(ID1*10)+NUM;break;
			case '6' :NUM=6;ID1=(ID1*10)+NUM;break;
			case '7' :NUM=7;ID1=(ID1*10)+NUM;break;
			case '8' :NUM=8;ID1=(ID1*10)+NUM;break;
			case '9' :NUM=9;ID1=(ID1*10)+NUM;break;
			case 'C':LCD_voidClear();ID1=0;ID2=0;NUM=0;break;
			default:break;
			}

			if(Local_variable == '=')
			{
				LCD_voidClear();
				_delay_ms(1000);
				if(ID1==PASS){DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);LCD_voidSendString("come on in");_delay_ms(10000);DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);LCD_voidSendCmd(0b00001000);break;}
				else {counter--;
				if(counter==0){LCD_voidSendString("wrong pass");_delay_ms(10000);LCD_voidSendCmd(0b00001000);DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_HIGH);LED_voidBlink();DIO_Init();break;}
				LCD_voidSendString("wrong pass");
				LCD_voidGoToRowColumn(1,0);
				LCD_voidSendNum(counter);
				LCD_voidSendString("tries left");
				_delay_ms(10000);
				LCD_voidClear();}
				ID1=0;NUM=0;
			};
		}
	}
	return 0;
}


