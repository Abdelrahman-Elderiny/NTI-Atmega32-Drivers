/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    20 February 2023 					*/
/*	 Version 			:    2.0V 							 	*/
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

#include "SWITCHES_CONFIG.h"
#include "dio.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef SWITCHES_INT_H
#define SWITCHES_INT_H

/***********************************************************************/
/* Description    : This function used to intialization of switches   */ 
/*																     */
/*					Inputs : void					  			    */
/*					Return : void		 					       */
/******************************************************************/

void switch_vidInit(void);

/***********************************************************************/
/* Description    : This function used to intialization of switches   */ 
/*																     */
/*					Inputs : switch -> from type of enum 		    */
/*					Return : state of button 				       */
/******************************************************************/

u8 switch_GetStatus(switch_id_t button);





#endif /* End of the file guard*/