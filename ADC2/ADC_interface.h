

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_u8_CHANNEL_0       0 
#define ADC_u8_CHANNEL_1       1  
#define ADC_u8_CHANNEL_2       2  
#define ADC_u8_CHANNEL_3       3  
#define ADC_u8_CHANNEL_4       4  
#define ADC_u8_CHANNEL_5       5  
#define ADC_u8_CHANNEL_6       6
#define ADC_u8_CHANNEL_7       7   



void ADC_voidInit(void);

u8 ADC_u8GetDigitalValueSynchNonBlocking( u8 Copy_u8ChannelNb ,u16 * Copy_pu16DigitalValue);



#endif
