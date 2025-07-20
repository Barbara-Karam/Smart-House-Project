
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{
	SET_BIT(ADC_u8_ADMUX,6);
		CLR_BIT(ADC_u8_ADMUX,7);


		//left or right adjust //right
		CLR_BIT(ADC_u8_ADMUX,5);


		CLR_BIT(ADC_u8_ADCSRA,5);


		CLR_BIT( ADC_u8_ADCSRA,0);
		CLR_BIT( ADC_u8_ADCSRA,1);
		SET_BIT(ADC_u8_ADCSRA,2);


		SET_BIT(ADC_u8_ADCSRA,7);
}

u8 ADC_u8GetDigitalValueSynchNonBlocking( u8 Copy_u8Channel ,u16 * Copy_pu16DigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8Channel<32) && ( Copy_pu16DigitalValue!=NULL))
		{
			//clear ADMUX
			ADC_u8_ADMUX &= 0b11100000;
			//select channel
			ADC_u8_ADMUX |= Copy_u8Channel;
			//start conversion
			SET_BIT(ADC_u8_ADCSRA,6);
			//wait for the interrupt flag
			while((GET_BIT(ADC_u8_ADCSRA,4))==0);

			//read output
			*Copy_pu16DigitalValue= ADC_u16_ADC;

			//remove flag
			SET_BIT(ADC_u8_ADCSRA,4);

		}
		else Local_u8ErrorState = STD_TYPES_NOK;

		return Local_u8ErrorState;

}
