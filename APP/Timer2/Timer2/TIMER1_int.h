/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "dio.h"
#include "TIMER1_priv.h"
#include "TIMER1_config.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef TIMER1_INT_H
#define TIMER1_INT_H

/****************************************************************/
/* Description    : This function used for TIMER1 INIT         	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_Init(void);

/****************************************************************/
/* Description    : This function used for Pre-loading         	*/
/*                        in TCNT1                              */
/*																*/
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetTimerReg(u8 Copy_uint8Val);

/****************************************************************/
/* Description    : This function used for entering         	*/
/*                  the value in OCR1A & OCR1B REG.             */
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetCompareVal(u8 Copy_uint8Val);

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_EnableOVInt(void);

/****************************************************************/
/* Description    : This function used for disable interrupt   	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_DisableOVInt(void);

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_EnableCTCInt(void);

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_DisableCTCInt(void);

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the ICU mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_EnableICUInt(void);

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the ICU mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_DisableICUInt(void);

/****************************************************************/
/* Description    : The call back func. for timer 1         	*/ 
/*						for the overflow mode       			*/
/*					Inputs : void (*Copy_ptr) (void)  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

/****************************************************************/
/* Description    : The call back func. for timer 1         	*/ 
/*							for CTC mode    					*/
/*					Inputs : void (*Copy_ptr) (void)   			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;

/****************************************************************/
/* Description    : The call back func. for timer 1         	*/ 
/*							for ICU mode    					*/
/*					Inputs : void (*Copy_ptr) (void)   			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetICUCallBack(void (*Copy_ptr) (void) ) ;



#endif /* End of the file guard*/