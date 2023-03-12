/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    15 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Config files Config for KPD    	*/
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/********************************************/
/*         GLOBAL CONSTANT MACROS          */
/******************************************/

/*	Rows Configurations	*/

#define KEYPAD_ROW1_PORT				DIO_PORTC
#define KEYPAD_ROW1_CHANNEL				DIO_PIN5

#define KEYPAD_ROW2_PORT				DIO_PORTC
#define KEYPAD_ROW2_CHANNEL				DIO_PIN4

#define KEYPAD_ROW3_PORT				DIO_PORTC
#define KEYPAD_ROW3_CHANNEL				DIO_PIN3

#define KEYPAD_ROW4_PORT				DIO_PORTC
#define KEYPAD_ROW4_CHANNEL				DIO_PIN2

/*	Columns Configurations	*/

#define KEYPAD_COL1_PORT				DIO_PORTD
#define KEYPAD_COL1_CHANNEL				DIO_PIN7

#define KEYPAD_COL2_PORT				DIO_PORTD
#define KEYPAD_COL2_CHANNEL				DIO_PIN6

#define KEYPAD_COL3_PORT				DIO_PORTD
#define KEYPAD_COL3_CHANNEL				DIO_PIN5

#define KEYPAD_COL4_PORT				DIO_PORTD
#define KEYPAD_COL4_CHANNEL				DIO_PIN3



#endif /* End of the file guard*/