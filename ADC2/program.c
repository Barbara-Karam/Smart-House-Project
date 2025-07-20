#define CPU 8000000UL
#include <util/delay.h>


#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void LCD_voidInit(void)
{
	_delay_ms(35);
	LCD_voidSendCmd(0b00111000);//functionset
	_delay_us(40);
	LCD_voidSendCmd(0b00001100);//display
	_delay_us(40);
	LCD_voidSendCmd(0b00000001);//clr
	_delay_ms(2);
	LCD_voidSendCmd(0b00001110);//entry mode set

}
void LCD_voidSendCmd(u8 Copy_u8Cmd)
{
	//rs=0
	DIO_u8SetPinValue(CONTROL_PORT,RS_PIN,DIO_u8_LOW);
	//rw=0
	DIO_u8SetPinValue(CONTROL_PORT,RW_PIN,DIO_u8_LOW);
	//send cmd byte to the data pins of LCD
	DIO_u8SetPortValue(DATA_PORT,Copy_u8Cmd);
	//enable pulse e=1,e=0
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_LOW);
	_delay_us(1);
}
void LCD_voidSendChar(u8 Copy_u8Char)
{
	//rs=1
	DIO_u8SetPinValue(CONTROL_PORT,RS_PIN,DIO_u8_HIGH);
	//rw=0
	DIO_u8SetPinValue(CONTROL_PORT,RW_PIN,DIO_u8_LOW);
	//send cmd byte to the data pins of LCD
	DIO_u8SetPortValue(DATA_PORT,Copy_u8Char);
	//enable pulse e=1,e=0
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_LOW);
	_delay_us(1);
}
void LCD_voidSendString(u8 *Copy_up8Arr)
{
	int i=0;
	while (Copy_up8Arr[i]!=0)
	{
		LCD_voidSendChar(Copy_up8Arr[i]);
		i++;

	}


}
void LCD_voidClear(void)
{
	LCD_voidSendCmd(0b00000001);
}
void LCD_voidGoToRowColumn(u8 Copy_u8Row,u8 Copy_u8Column)
{
	if((Copy_u8Row <= ROW2) && (Copy_u8Column < 39))
	{
		switch(Copy_u8Row)
		{
		case ROW1:{LCD_voidSendCmd(0x80+Copy_u8Column);break;}
		case ROW2:{LCD_voidSendCmd(0xC0+Copy_u8Column);break;}
		}
	}
}
/*while (modules != 0)
{
	  Array[i]=num%10;
	  Array[i+1]=int(num/10);
}*/
void LCD_voidSendSpecialChar(u8 Copy_u8Index,u8* Copy_pu8SpecialChar,u8 Copy_u8Row,u8 Copy_u8Column)
{
	u8 Local;
	Local=Copy_u8Index*8;
	LCD_voidSendCmd(0b01000000+Local);//access CGRAM character 0
	for(int i=0;i<=8;i++)
	{
     LCD_voidSendChar(Copy_pu8SpecialChar[i]);
	}

	LCD_voidGoToRowColumn(Copy_u8Row,Copy_u8Column);//access DDRAM
	LCD_voidSendChar(Copy_u8Index);

}
void LCD_voidSendNum(u32 Copy_u32Num)
{
	u8 l=0;u8 Arr[10];
	while(Copy_u32Num!=0)
	{
		Arr[l]=Copy_u32Num%10;
	    Copy_u32Num=(Copy_u32Num/10);
	    l++;
	}
	for(s8 i=l-1;i>=0;i--)
	{
		LCD_voidSendChar(Arr[i]+48);
    }
}
