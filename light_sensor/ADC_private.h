/*
 * ADC_private.h
 *
 *  Created on: Sep 19, 2022
 *      Author: brbar
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_u8_ADMUX     *((volatile u8 *) 0x27)
#define ADC_u8_ADCSRA    *((volatile u8 *) 0x26)
#define ADC_u8_ADCH      *((volatile u8 *) 0x25)
#define ADC_u8_ADCL      *((volatile u8 *) 0x24)

#define ADC_u16_ADC      *((volatile u16*) 0x24)

#define ADC_u8_SFIOR     *((volatile u8 *) 0x50)


#endif /* ADC_PRIVATE_H_ */
