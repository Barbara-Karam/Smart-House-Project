#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define ROW1 0
#define ROW2 1
void LCD_voidInit(void);
void LCD_voidClear(void);
void LCD_voidSendCmd(u8 Copy_u8Cmd);
void LCD_voidSendChar(u8 Copy_u8Char);
void LCD_voidSendString(u8 *Copy_up8Arr);
void LCD_voidGoToRowColumn(u8 Copy_u8Row,u8 Copy_u8Column);
void LCD_voidSendSpecialChar(u8 Copy_u8Index,u8* Copy_pu8SpecialChar,u8 Copy_u8Row,u8 Copy_u8Column);
void LCD_voidSendNum(u32 Copy_u8Num);



#endif
