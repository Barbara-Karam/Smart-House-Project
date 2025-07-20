/*
 * KPDprogram.c
 *
 *  Created on: Sep 10, 2022
 *      Author: brbar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define CPU 8000000UL
#include <util/delay.h>

#include"DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"


 u8 KPD_Au8RowPins[4]={KPD_u8_R1,KPD_u8_R2,KPD_u8_R3,KPD_u8_R4};
 u8 KPD_Au8ColPins[4]={KPD_u8_C1,KPD_u8_C2,KPD_u8_C3,KPD_u8_C4};

 u8 KPD_Au8Key[4][4] =KPD_Au8KEY_VALUE;
// rows output
//cols input == pullup
u8 KPD_u8GetKey(u8 *Copy_pu8ReturnedKey)
{
  u8 Local_ErrorStatus = STD_TYPES_OK;
  u8 Local_u8RowsCounter,Local_u8ColCounter,Local_u8ReturnedKey,Local_u8Flag=0;
  if (Copy_pu8ReturnedKey != NULL)
  {
	  *Copy_pu8ReturnedKey=0xFF;
	  for(Local_u8RowsCounter=0;Local_u8RowsCounter<=3;Local_u8RowsCounter++)
	  {
     //activate rows
	  DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8RowPins[Local_u8RowsCounter],DIO_u8_LOW);
	 //read 4 cols
	  for(Local_u8ColCounter=0;Local_u8ColCounter<=3;Local_u8ColCounter++)
	  {
		  DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColPins[Local_u8ColCounter],&Local_u8ReturnedKey);
		  if(Local_u8ReturnedKey==DIO_u8_LOW)
		  {
              //debouncing
			  _delay_ms(20);
			  while(Local_u8ReturnedKey==DIO_u8_LOW)
			  {
				  DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColPins[Local_u8ColCounter],&Local_u8ReturnedKey);

			  }
			  *Copy_pu8ReturnedKey = KPD_Au8Key[Local_u8RowsCounter][Local_u8ColCounter];
			  Local_u8Flag = 1;
			  break;
		  }
	  }
	  DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8RowPins[Local_u8RowsCounter],DIO_u8_HIGH);
	  if (Local_u8Flag ==1 )
	  {
		  break;
	  }
	  }
  }
  else
  {
	  Local_ErrorStatus = STD_TYPES_NOK;
  }
  return Local_ErrorStatus;
}
