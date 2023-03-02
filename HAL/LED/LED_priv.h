/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    20 February 2023 					*/
/*	 Version 			:    2.0V 							 	*/
/*	 Description 		:    LED Types                      	*/
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef LED_PRIV_H
#define LED_PRIV_H

/**************************************/
/*  GLOBAL DATA TYPES AND STRUCTURES  */
/**************************************/

typedef enum{
	LED_RED,
	LED_GREEN,
	LED_BLUE,
	LED_YELLOW
}led_id;

#endif /* End of the file guard*/