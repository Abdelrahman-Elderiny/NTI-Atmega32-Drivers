/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    19 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Address of the registers [A,B,C,D]  */ 
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef DIO_REG_H
#define DIO_REG_H
                                    
/************************************/
/*      GLOBAL CONSTANT MACROS      */
/************************************/

/*	PORTA HW Registers Definition	*/

#define DIO_DDRA_REG     	(*(volatile u8*)(0x3A))
#define DIO_PORTA_REG   	(*(volatile u8*)(0x3B))
#define DIO_PINA_REG		(*(volatile u8*)(0x39))

/*	PORTB HW Registers Definition	*/

#define DIO_DDRB_REG     	(*(volatile u8*)(0x60))
#define DIO_PORTB_REG   	(*(volatile u8*)(0x38))
#define DIO_PINB_REG		(*(volatile u8*)(0x36))

/*	PORTC HW Registers Definition	*/

#define DIO_DDRC_REG     	(*(volatile u8*)(0x34))
#define DIO_PORTC_REG   	(*(volatile u8*)(0x35))
#define DIO_PINC_REG		(*(volatile u8*)(0x33))

/*	PORTD HW Registers Definition	*/

#define DIO_DDRD_REG     	(*(volatile u8*)(0x31))
#define DIO_PORTD_REG   	(*(volatile u8*)(0x32))
#define DIO_PIND_REG		(*(volatile u8*)(0x30))


#endif  /* End of the file guard*/