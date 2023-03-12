/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configuration file for Timer 2           */
/****************************************************************/
#ifndef _TIMER2_CONFIG_H
#define _TIMER2_CONFIG_H

/*************************************************/
/*           MACROS TO SELECT MODE              */
/***********************************************/

/*
TIMER2_NORMAL 	
TIMER2_CTC 		
TIMER2_FAST_PWM 
TIMER2_PHASE_PWM
*/

#define TIMER2_MODE 		TIMER2_NORMAL

/*************************************************/
/*           MACROS TO SELECT PRESCALER         */
/***********************************************/

/*
TIMER2_DIV_BY_1	
TIMER2_DIV_BY_8	
TIMER2_DIV_BY_64
TIMER2_DIV_BY_256
TIMER2_DIV_BY_1024
*/

#define TIMER2_PRESCALER  	TIMER2_DIV_BY_1024

/*************************************************/
/*           MACROS TO SELECT  Compare-         */
/*                Match Output Mode            */
/**********************************************/

/*
TIMER2_NO_ACTION	
TIMER2_TOGGLE		
TIMER2_SET			
TIMER2_CLEAR		
*/

#define TIMER2_COM_EVENT   TIMER2_NO_ACTION


#endif /* End of the file guard*/
