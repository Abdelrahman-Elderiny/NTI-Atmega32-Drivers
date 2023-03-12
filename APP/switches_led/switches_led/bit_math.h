/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    19 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    bitwise operations macros          */
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

 #define SET_BIT(REG,BIT_NO) 			REG|=(1<<BIT_NO)

#define CLEAR_BIT(REG,BIT_NO) 			REG&=~(1<<BIT_NO)

#define CHECK_BIT(REG,BIT_NO) 			((REG>>BIT_NO)&0x01)

#define FLIP_BIT(REG,BIT_NO)    		REG^=(1<<BIT_NO)

#endif  /* End of the file guard*/

