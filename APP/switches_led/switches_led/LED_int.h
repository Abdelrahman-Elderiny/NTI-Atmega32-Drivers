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

#include "dio.h"
#include "LED_priv.h"
#include "LED_config.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef LED_INT_H
#define LED_INT_H

/***********************************************************************/
/* Description    : This function used to intialization of LED        */ 
/*																     */
/*					Inputs : void					  			    */
/*					Return : void		 					       */
/******************************************************************/

void led_init(void);

/***********************************************************************/
/* Description    : This function used to Turn LED ON                 */ 
/*																     */
/*					Inputs : led_id -> ledId		  			    */
/*					Return : void		 					       */
/******************************************************************/

void led_on(led_id ledId);

/***********************************************************************/
/* Description    : This function used to Turn LED OFF                */ 
/*																     */
/*					Inputs : led_id -> ledId		  			    */
/*					Return : void		 					       */
/******************************************************************/

void led_off(led_id ledId);

/***********************************************************************/
/* Description    : This function used to TOGGLE LED ON               */ 
/*																     */
/*					Inputs : led_id -> ledId	     			    */
/*					Return : void		 					       */
/******************************************************************/

void led_toggle(led_id ledId);


#endif /* End of the file guard*/