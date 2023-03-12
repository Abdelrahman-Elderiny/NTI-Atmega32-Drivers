/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    11 March 2023 	     S				*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Address of the registers of EEPROM  */ 
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/
#ifndef EEPROM_PRIV_H_
#define EEPROM_PRIV_H_

/**********************************************/
/*           Address of EECR register        */
/*               and its bits               */
/*******************************************/

#define EECR	 (*(volatile u8 * )0x3C)
#define EERIE    3 
#define EEMWE    2
#define EEWE     1
#define EERE     0

/**********************************************/
/*           Address of EEDR register        */
/********************************************/

#define EEDR	 (*(volatile u8 * )0x3D)

/**********************************************/
/*           Address of EEARL register       */
/********************************************/

#define EEARL	 (*(volatile u16 * )0x3E)

#endif /* End of the file guard*/