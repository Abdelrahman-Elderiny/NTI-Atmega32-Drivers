/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    25 February 2023 					*/
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

#include "GIE_PRIVATE.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/
#ifndef _GIE_INT_H
#define _GIE_INT_H


/****************************************************************/
/* Description    : This function used to Enable GIE 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void GIE_vidEnable (void);

/****************************************************************/
/* Description    : This function used to Disable GIE 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void GIE_vidDisable (void);

#endif /* End of the file guard*/