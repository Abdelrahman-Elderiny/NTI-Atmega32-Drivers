/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configuration file for Timer 1     */
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef TIMER1_CONFIG_H
#define TIMER1_CONFIG_H

/*************************************************/
/*           MACROS TO SELECT MODE              */
/***********************************************/

/*
TIMER1_NORMAL 	
TIMER1_CTC 		
TIMER1_FAST_PWM 
TIMER1_PHASE_PWM
*/

#define  TIMER1_MODE      TIMER1_NORMAL

/**************************************************/
/*           MACROS TO SELECT WHICH              */
/*            REG FROM ( A & B )                */
/***********************************************/

/*
ENABLE 
DISABLE
*/

#define TIMER1_A      ENABLE
#define TIMER1_B      DISABLE

/*************************************************/
/*           MACROS TO SELECT PRESCALER         */
/***********************************************/

/*
TIMER1_DIV_BY_1	
TIMER1_DIV_BY_8	
TIMER1_DIV_BY_64
TIMER1_DIV_BY_256
TIMER1_DIV_BY_1024
*/

#define TIMER1_PRESCALER  	TIMER1_DIV_BY_1024

/*************************************************/
/*           MACROS TO SELECT  Compare-         */
/*                Match Output Mode            */
/**********************************************/

/*
TIMER1_NO_ACTION	
TIMER1_TOGGLE		
TIMER1_SET			
TIMER1_CLEAR		
*/

#define TIMER1_COM_EVENT   TIMER1_NO_ACTION


#endif  /* End of the file guard*/