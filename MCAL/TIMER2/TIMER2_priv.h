/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Private file for Timer 2           */
/****************************************************************/



/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _TIMER2_PRIV_H
#define _TIMER2_PRIV_H

/*************************************************/
/*            GLOBAL CONSTANT MACROS            */
/***********************************************/


/**********************************************/
/*           Address of TCCR2 register       */       
/*               and its bits               */
/*******************************************/ 

#define TCCR2	 (*(volatile u8 * )0x45)
#define FOC2     7
#define WGM20    6
#define COM21    5
#define COM20    4
#define WGM21    3
#define CS22     2 
#define CS21     1
#define CS20     0

/**********************************************/
/*           Address of TIMSK register       */       
/*               and its bits               */
/*******************************************/

#define TIMSK	 (*(volatile u8 * )0X59)
#define OCIE2   7
#define TOIE2   6

/**********************************************/
/*           Address of TIFR register        */       
/*               and its bits               */
/*******************************************/

#define TIFR	 (*(volatile u8 * )0x58)
#define OCF2    7
#define TOV2    6

/*********************************************/
/*           Address of TCNT2 register      */       
/*******************************************/

#define TCNT2	 (*(volatile u8 * )0X44)

/*********************************************/
/*           Address of OCR2 register       */       
/*******************************************/

#define OCR2 	 (*(volatile u8 * )0X43)

/*************************************************/
/*           MACROS TO SELECT MODE              */
/***********************************************/

#define TIMER2_NORMAL 		    1
#define TIMER2_CTC 			    2
#define TIMER2_FAST_PWM 	    3
#define TIMER2_PHASE_PWM 	    4

/*************************************************/
/*           MACROS TO SELECT PRESCALER         */
/***********************************************/

#define TIMER2_DIV_BY_1			1
#define TIMER2_DIV_BY_8			5
#define TIMER2_DIV_BY_64		8
#define TIMER2_DIV_BY_256		10
#define TIMER2_DIV_BY_1024		15

/*************************************************/
/*           MACROS TO SELECT  Compare-         */
/*                Match Output Mode            */
/**********************************************/

#define TIMER2_NO_ACTION	   100
#define TIMER2_TOGGLE		   12
#define TIMER2_SET			   20
#define TIMER2_CLEAR		   25

#endif  /* End of the file guard*/
