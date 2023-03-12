/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Private file for Timer 1           */
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/
#ifndef _TIMER1_PRIV_H
#define _TIMER1_PRIV_H

/*************************************************/
/*            GLOBAL CONSTANT MACROS            */
/***********************************************/

/**********************************************/
/*           Address of TCCR1A register      */       
/*               and its bits               */
/*******************************************/ 

#define TCCR1A	 (*(volatile u8 * )0x4F)
#define COM1A1     7
#define COM1A0     6
#define COM1B1     5
#define COM1B0     4
#define FOC1A      3
#define FOC1B      2 
#define WGM11      1
#define WGM10      0

/**********************************************/
/*           Address of TCCR1B register      */       
/*               and its bits               */
/*******************************************/ 
  
#define TCCR1B	 (*(volatile u8 * )0x4E)
#define ICNC1     7
#define ICES1     6 
#define WGM13     4
#define WGM12     3
#define CS12      2
#define CS11      1
#define CS10      0

/**********************************************/
/*           Address of TIMSK register       */       
/*               and its bits               */
/*******************************************/

#define TIMSK	 (*(volatile u8 * )0X59)
#define TICIE1    5
#define OCIE1A    4
#define OCIE1B    3
#define TOIE1     2

/**********************************************/
/*           Address of TIFR register        */       
/*               and its bits               */
/*******************************************/

#define TIFR	 (*(volatile u8 * )0x58)
#define ICF1     5
#define OCF1A    4
#define OCF1B    3
#define TOV1     2


/*********************************************/
/*           Address of TCNT1 register      */       
/*******************************************/

#define TCNT1	 (*(volatile u16 * )0X4C)

/**********************************************/
/*           Address of OCR1A register       */       
/********************************************/

#define OCR1A 	 (*(volatile u16 * )0X4A)

/**********************************************/
/*           Address of OCR1A register       */       
/********************************************/

#define OCR1B 	 (*(volatile u16 * )0X48)

/**********************************************/
/*           Address of ICR1 register        */       
/********************************************/

#define ICR1 	 (*(volatile u16 * )0X46)

/*************************************************/
/*           MACROS TO SELECT MODE              */
/***********************************************/

#define TIMER1_NORMAL 		    1
#define TIMER1_CTC 			    2
#define TIMER1_FAST_PWM 	    3
#define TIMER1_PHASE_PWM 	    4

/*************************************************/
/*           MACROS TO SELECT PRESCALER         */
/***********************************************/

#define TIMER1_DIV_BY_1			1
#define TIMER1_DIV_BY_8			5
#define TIMER1_DIV_BY_64		8
#define TIMER1_DIV_BY_256		10
#define TIMER1_DIV_BY_1024		15

/*************************************************/
/*           MACROS TO SELECT  Compare-         */
/*                Match Output Mode            */
/**********************************************/

#define TIMER1_NO_ACTION	   100
#define TIMER1_TOGGLE		   12
#define TIMER1_SET			   20
#define TIMER1_CLEAR		   25

/************************************************/
/*                  STATE                      */
/**********************************************/
#define ENABLE                 1
#define DISABLE                0

#endif  /* End of the file guard*/