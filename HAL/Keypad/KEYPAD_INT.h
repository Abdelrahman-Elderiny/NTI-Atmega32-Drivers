/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    15 February 2023 					*/
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
#include "KEYPAD_CONFIG.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef KEYPAD_INT_H
#define KEYPAD_INT_H

/***********************************************************************/
/* Description    : This function used to intialization of KPD        */ 
/*																     */
/*					Inputs : void					  			    */
/*					Return : void		 					       */
/******************************************************************/

void keypad_vidInit(void);

/***********************************************************************/
/* Description    : This function used to get the pressed key         */ 
/*																     */
/*					Inputs : void					  			    */
/*					Return : u8 pressed switch   			       */
/******************************************************************/

u8 keypad_u8GetKey(void);

#endif /* End of the file guard*/
