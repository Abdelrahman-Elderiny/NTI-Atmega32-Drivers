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
#include "TIMER2_priv.h"
#include "TIMER2_config.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _TIMER2_INT_H
#define _TIMER2_INT_H

/****************************************************************/
/* Description    : This function used for TIMER2 INIT         	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_Init(void);

/****************************************************************/
/* Description    : This function used for Pre-loading         	*/
/*                        in TCNT2                              */
/*																*/
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_SetTimerReg(u8 Copy_uint8Val);

/****************************************************************/
/* Description    : This function used for entering         	*/
/*                     the value in OCR2 REG.                   */
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_SetCompareVal(u8 Copy_uint8Val);

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_EnableOVInt(void);

/****************************************************************/
/* Description    : This function used for disable interrupt   	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_DisableOVInt(void);

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_EnableCTCInt(void);

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_DisableCTCInt(void);

/****************************************************************/
/* Description    : The call back func. for timer 2         	*/ 
/*						for the overflow mode       			*/
/*					Inputs : void (*Copy_ptr) (void)  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_vidSetOVCallBack(void (*Copy_ptr) (void) )  ;

/****************************************************************/
/* Description    : The call back func. for timer 2         	*/ 
/*							for CTC mode    					*/
/*					Inputs : void (*Copy_ptr) (void)   			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) )  ;


#endif /* End of the file guard*/