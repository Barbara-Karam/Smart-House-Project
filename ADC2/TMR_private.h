/***********************************************************************************/
/*************   			  Name : Mohamed Ahmed  	    ************************/  
/*************   			  Date : 	05/09/2022	  	    ************************/  
/*************   		 	   SWC :	 TMR		 	    ************************/     
/*************   		   Version :     1.0  			    ************************/    
/***********************************************************************************/  

#ifndef TMR_PRIVATE_H
#define TMR_PRIVATE_H

/* Macros for HW REG */
//Timer 0
#define TMR_u8_OCR0_REG             *((volatile u8*)0x5C)
#define TMR_u8_TIMSK_REG            *((volatile u8*)0x59)
#define TMR_u8_TIFR_REG             *((volatile u8*)0x58)
#define TMR_u8_TCCR0_REG            *((volatile u8*)0x53)
#define TMR_u8_TCNT0_REG            *((volatile u8*)0x52)

// Timer 1

#define TMR_u8_TCCR1A               *((volatile u8*)0x4F)
#define TMR_u8_TCCR1B               *((volatile u8*)0x4E)

#define TMR_u8_TCNT1H               *((volatile u8*)0x4D)
#define TMR_u8_TCNT1L               *((volatile u8*)0x4C)

#define TMR_u16_TCNT1               *((volatile u16*)0x4C)

#define TMR_u8_OCR1AH               *((volatile u8*)0x4B)
#define TMR_u8_OCR1AL               *((volatile u8*)0x4A)

#define TMR_u16_OCR1A               *((volatile u16*)0x4A)

#define TMR_u8_OCR1BH               *((volatile u8*)0x49)
#define TMR_u8_OCR1BL               *((volatile u8*)0x48)

#define TMR_u16_OCR1B               *((volatile u16*)0x48)

#define TMR_u8_ICR1H               *((volatile u8*)0x47)
#define TMR_u8_ICR1L               *((volatile u8*)0x46)

#define TMR_u16_ICR1               *((volatile u16*)0x46)




#endif
