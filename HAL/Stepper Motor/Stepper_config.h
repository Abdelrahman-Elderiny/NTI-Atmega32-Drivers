/******************************************************************/
/*   Author             :    Abdelrahman Magdy				      */
/*	 Date 				:    1 March 2023    					  */
/*	 Version 			:    1.0V 							 	  */
/*	 Description 		:    Configuration file for Stepper Motor */
/******************************************************************/


/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _STEPPER_CONFIG_H
#define _STEPPER_CONFIG_H

/******************************************/
/*     Macro to choose numbers of         */
/*           used motors                  */
/******************************************/

#define NUM_MOTORS  3 

extern st_motor motors [NUM_MOTORS] ;

/*************************************/
/*         Select in which mode      */
/*           ST_MOTOR Rotate         */
/*       [FULL STEP , HALF STEP]     */
/*************************************/ 

#define  FULL_STEP          1
#define  HALF_STEP          2

#define ST_MOTOR_ROTATION  FULL_STEP

/*************************************/
/*         Select in which mode      */
/*           ST_MOTOR Rotate         */
/*             [ CW , CCW ]          */
/*************************************/ 

#define  CW          1
#define  CCW         2
#define  STOP        3

/*************************************/
/*         Select THE SPEED          */
/*************************************/ 

#define  MINSPEED     20
#define  MAXSPEED     300


#endif  /* End of the file guard*/