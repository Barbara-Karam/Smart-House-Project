/************************************************************
 ***********************/
/*************   			  Name : Mohamed Ahmed  	    
 ************************/
/*************   			  Date : 	05/09/2022	  	    
 ************************/
/*************   		 	   SWC :	 TMR		 	    
 ************************/
/*************   		   Version :     1.0  			    
 ************************/
/************************************************************
 ***********************/

/* include LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Driver Files */
#include "TMR_interface.h"
#include "TMR_private.h"
#include "TMR_config.h"

void (*TMR_pfTimer0OVF)(void) = NULL;
void (*TMR_pfTimer0CTC)(void) = NULL;

void TMR_voidTimer0Init(void)
{
	//	/* Select Mode of Timer = > Normal Mode */
//		CLR_BIT(TMR_u8_TCCR0_REG,6);
//		CLR_BIT(TMR_u8_TCCR0_REG,3);
//
//		/* set Preload Value */
//		TMR_u8_TCNT0_REG = 192;
//
//		/* Enable PIE of OVF */
//		SET_BIT(TMR_u8_TIMSK_REG,0);
//
//		/* prescaler => 8 */
//		CLR_BIT(TMR_u8_TCCR0_REG,0);
//		SET_BIT(TMR_u8_TCCR0_REG,1);
//		CLR_BIT(TMR_u8_TCCR0_REG,2);


//			/* Select Mode of Timer = > CTC Mode */
//			CLR_BIT(TMR_u8_TCCR0_REG,6);
//			SET_BIT(TMR_u8_TCCR0_REG,3);
//
//			TMR_u8_OCR0_REG = 99;
//
//			/* Enable PIE of CTC clear on compare match */
//			SET_BIT(TMR_u8_TIMSK_REG,1);
//
//			/* prescaler => 8 */
//			CLR_BIT(TMR_u8_TCCR0_REG,0);
//			SET_BIT(TMR_u8_TCCR0_REG,1);
//			CLR_BIT(TMR_u8_TCCR0_REG,2);

	/* Select Mode of Timer = > FAST PWM Mode */
	SET_BIT(TMR_u8_TCCR0_REG,6);
	SET_BIT(TMR_u8_TCCR0_REG,3);

	/* Select Action on OC0 PIN => Non - Inverting */
	SET_BIT(TMR_u8_TCCR0_REG,5);
	CLR_BIT(TMR_u8_TCCR0_REG,4);


	/* prescaler => 8 */
	CLR_BIT(TMR_u8_TCCR0_REG,0);
	SET_BIT(TMR_u8_TCCR0_REG,1);
	CLR_BIT(TMR_u8_TCCR0_REG,2);


}


void   TMR_voidTimer1GetCounterValue(u16 * Copy_pu16CounterValue)
{
	*Copy_pu16CounterValue = TMR_u16_TCNT1;
}


void TMR_voidTimer1Init(void)
{
//	/* Timer 1 Select Mode 14 => ICR1 top Value */
//	CLR_BIT(TMR_u8_TCCR1A,0);
//	SET_BIT(TMR_u8_TCCR1A,1);
//	SET_BIT(TMR_u8_TCCR1B,3);
//	SET_BIT(TMR_u8_TCCR1B,4);
//
//	/* Channel A => Non - Inverting */
//	CLR_BIT(TMR_u8_TCCR1A,6);
//	SET_BIT(TMR_u8_TCCR1A,7);
//
//	/* Set Max Value */
//	TMR_u16_ICR1 = 19999;
//
//	/* Set Prescaler => 8 / start timer 1*/
//	CLR_BIT(TMR_u8_TCCR1B,0);
//	SET_BIT(TMR_u8_TCCR1B,1);
//	CLR_BIT(TMR_u8_TCCR1B,2);


	/* Timer 1 Select Mode 1 =>  Normal Mode */
	CLR_BIT(TMR_u8_TCCR1A,0);
	CLR_BIT(TMR_u8_TCCR1A,1);
	CLR_BIT(TMR_u8_TCCR1B,3);
	CLR_BIT(TMR_u8_TCCR1B,4);


	/* Set Prescaler => 8 / start timer 1*/
	CLR_BIT(TMR_u8_TCCR1B,0);
	SET_BIT(TMR_u8_TCCR1B,1);
	CLR_BIT(TMR_u8_TCCR1B,2);



}

void   TMR_voidTimer1SetCompareMatchChannelA(u16 Copy_16OCR1AValue)
{
	TMR_u16_OCR1A = Copy_16OCR1AValue;
}

void   TMR_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value)
{
		TMR_u8_OCR0_REG = Copy_u8OCR0Value;
}

void   TMR_u8Timer0OVFSetCallBack(void(*Copy_pf)(void))
{
	TMR_pfTimer0OVF = Copy_pf;
}

void   TMR_u8Timer0CTCSetCallBack(void(*Copy_pf)(void))
{
	TMR_pfTimer0CTC = Copy_pf;
}

/* prototype if ISR Timer0 CTC */
void __vector_10(void)     __attribute__((signal));
void __vector_10(void)
{
	static u16 Local_u16Counter = 0;
	Local_u16Counter ++;

	if(Local_u16Counter == 10000)
	{

		/* Reset Counter */
		Local_u16Counter = 0;

		/* Call Back Fuunction */
		TMR_pfTimer0CTC();

	}
}


/* prototype if ISR Timer0 OVF */
void __vector_11(void)     __attribute__((signal));
void __vector_11(void)
{
	static u16 Local_u16Counter = 0;
	Local_u16Counter ++;

	if(Local_u16Counter == 3907)
	{
		/* set Preload Value */
		TMR_u8_TCNT0_REG = 192;

		/* Reset Counter */
		Local_u16Counter = 0;

		/* Call Back Fuunction */
		TMR_pfTimer0OVF();

	}
}

