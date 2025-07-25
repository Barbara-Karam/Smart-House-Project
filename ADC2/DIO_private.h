/***********************************************************************************/
/*************   			  Name : Mohamed Ahmed  	    ************************/  
/*************   			  Date : 	25/08/2022	  	    ************************/  
/*************   		 	   SWC :	 DIO		 	    ************************/     
/*************   		   Version :     1.0  			    ************************/    
/***********************************************************************************/   

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* Macros for HW Registers */
#define PORTA_u8_REG       *((volatile u8*)0x3B) 
#define DDRA_u8_REG    	   *((volatile u8*)0x3A) 
#define PINA_u8_REG        *((volatile u8*)0x39)
							   
#define PORTB_u8_REG       *((volatile u8*)0x38) 
#define DDRB_u8_REG    	   *((volatile u8*)0x37) 
#define PINB_u8_REG        *((volatile u8*)0x36) 
							   
#define PORTC_u8_REG       *((volatile u8*)0x35) 
#define DDRC_u8_REG    	   *((volatile u8*)0x34) 
#define PINC_u8_REG        *((volatile u8*)0x33)  
							   
#define PORTD_u8_REG       *((volatile u8*)0x32) 
#define DDRD_u8_REG    	   *((volatile u8*)0x31) 
#define PIND_u8_REG        *((volatile u8*)0x30)   

/* Macros for the Direction of the PINS in Config File */
#define DIO_u8_INITIAL_INPUT           0
#define DIO_u8_INITIAL_OUTPUT          1

/* Macros for the Value of the PINS in Config File */
#define DIO_u8_INITIAL_INPUT_FLOATING     0
#define DIO_u8_INITIAL_INPUT_PULLUP       1
#define DIO_u8_INITIAL_OUTPUT_LOW         0
#define DIO_u8_INITIAL_OUTPUT_HIGH        1

/* Macros for CONC */
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)           0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif