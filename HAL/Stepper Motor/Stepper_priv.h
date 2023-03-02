/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    1 March 2023    					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Private file for Stepper Motor     */
/****************************************************************/


/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _STEPPER_PRIV_H
#define _STEPPER_PRIV_H

/*****************************************/
/*  GLOBAL DATA TYPES AND STRUCTURES    */
/***************************************/

typedef struct Stepper_motor 
{
	u8 blue_port ;
	u8 blue_pin ;
	u8 pink_port ;
	u8 pink_pin ;
	u8 yellow_port ;
	u8 yellow_pin ;
	u8 orange_port ;
	u8 orange_pin ;
}st_motor ;



#endif  /* End of the file guard*/
