/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    11 March 2023 	     				*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:  public Accessing mechanism prototype */ 
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "dio.h"
#include "EEPROM_priv.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

/****************************************************************/
/* Description    : This function used for Send& Write         	*/
/*					Inputs : u16 Address&u8 data			  	*/
/*					Return : void		 					    */
/****************************************************************/

void EEPROM_vidWrite(u16 address , u8 data );

/****************************************************************/
/* Description    : This function used for recieve & Read      	*/
/*					Inputs : u16 Address        			  	*/
/*					Return : u8 data     					    */
/****************************************************************/

u8 EEPROM_Read(u16 address);

#endif /* EEPROM_INT_H_ */