/*
 * KPD_config.h
 *
 *  Created on: Sep 10, 2022
 *      Author: brbar
 */
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define PASS 555


#define      KPD_u8_PORT     DIO_u8_PORTC

#define      KPD_u8_R1       DIO_u8_PIN0
#define      KPD_u8_R2       DIO_u8_PIN1
#define      KPD_u8_R3       DIO_u8_PIN2
#define      KPD_u8_R4       DIO_u8_PIN3

#define      KPD_u8_C1       DIO_u8_PIN4
#define      KPD_u8_C2       DIO_u8_PIN5
#define      KPD_u8_C3       DIO_u8_PIN6
#define      KPD_u8_C4       DIO_u8_PIN7


#define KPD_Au8KEY_VALUE  {          \
		  {'7','8','9','/'},   \
		  {'4','5','6','*'},   \
		  {'1','2','3','-'},   \
		   {'C','0','=','+'},  \
                    }

#endif /* KPD_CONFIG_H_ */


