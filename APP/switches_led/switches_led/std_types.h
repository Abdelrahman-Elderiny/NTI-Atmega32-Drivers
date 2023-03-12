/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    19 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    standard data types definitions    */
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int  u16;
typedef signed short int s16;

typedef unsigned long int  u32;
typedef signed long int s32;

typedef float f32;
typedef double f64;

typedef unsigned char Std_ReturnType;

typedef enum {
	FALSE,
	TRUE
}boolean;
 
#endif  /* End of the file guard*/
