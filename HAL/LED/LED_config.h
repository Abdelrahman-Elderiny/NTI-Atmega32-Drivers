/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    20 February 2023 					*/
/*	 Version 			:    2.0V 							 	*/
/*	 Description 		:    Config files Config for LEDS   	*/
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef LED_CONFIG_H
#define LED_CONFIG_H

/********************************************/
/*         GLOBAL CONSTANT MACROS          */
/******************************************/

#define LED_RED_PORT		DIO_PORTB
#define LED_RED_CHANNEL		DIO_PIN7

#define LED_GREEN_PORT		DIO_PORTA
#define LED_GREEN_CHANNEL	DIO_PIN4

#define LED_BLUE_PORT		DIO_PORTA
#define LED_BLUE_CHANNEL	DIO_PIN5

#define LED_YELLOW_PORT		DIO_PORTA
#define LED_YELLOW_CHANNEL	DIO_PIN6

/*	LEDs HW Connection	*/
/*	SOURCE				*/
/*	SINK				*/

#define SOURCE 1
#define SINK   0

#define LED_RED_CONNECTION		SOURCE
#define LED_GREEN_CONNECTION	SOURCE
#define LED_BLUE_CONNECTION		SOURCE
#define LED_YELLOW_CONNECTION	SOURCE


#endif /* End of the file guard*/