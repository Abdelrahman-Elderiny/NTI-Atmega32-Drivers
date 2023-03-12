/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    6 March 2023     					*/
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
#include "uart_priv.h"
#include "uart_config.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _UART_INT_H
#define _UART_INT_H

/****************************************************************/
/* Description    : This function used for UART INIT         	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
 
void UART_Init(void);

/****************************************************************/
/* Description    : This function used for UART Sending        	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void UART_TransmitChr(u8 data);
void UART_TransmitString (u16 *str);

/****************************************************************/
/* Description    : This function used for UART Receive      	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

u8 UART_ReceiveChr(void);

#endif  /* End of the file guard*/

/********************************************
 *  END OF FILE: uart_int.h
 *******************************************/