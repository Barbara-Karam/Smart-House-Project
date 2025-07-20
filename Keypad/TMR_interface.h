/***********************************************************************************/
/*************   			  Name : Mohamed Ahmed  	    ************************/  
/*************   			  Date : 	05/09/2022	  	    ************************/  
/*************   		 	   SWC :	 TMR		 	    ************************/     
/*************   		   Version :     1.0  			    ************************/    
/***********************************************************************************/  

#ifndef TMR_INTERFACE_H
#define TMR_INTERFACE_H


void TMR_voidTimer0Init(void);

void TMR_voidTimer1Init(void);

void   TMR_u8Timer0OVFSetCallBack(void(*Copy_pf)(void));

void   TMR_u8Timer0CTCSetCallBack(void(*Copy_pf)(void));

void   TMR_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);

void   TMR_voidTimer1SetCompareMatchChannelA(u16 Copy_16OCR1AValue);

void   TMR_voidTimer1GetCounterValue(u16 * Copy_pu16CounterValue);



#endif
