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
NORMAL               
PWM_PHASE_CORRECT_8  
PWM_PHASE_CORRECT_9  
PWM_PHASE_CORRECT_10 
CTC_OCRA1A           
FASTPWM_8            
FASTPWM_9            
FASTPWM_10           
PWM_FRE_ICR          
PWM_FRE_OCR          
PWM_PHASE_CORR_ICR   
PWM_PHASE_CORR_OCR   
CTC_ICR              
FAST_PWM_ICR1        
FAST_PWM_OCR1A       
*/

#define  TIMER1_MODE      NORMAL

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

/*************************************************/
/*           MACROS TO SELECT  Compare-         */
/*                Match Output Mode            */
/**********************************************/

/*
OCR1A_REG
OCR1B_REG
*/

#define OCR_REG   OCR1A_REG

#endif  /* End of the file guard*/