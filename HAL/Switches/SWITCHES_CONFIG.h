/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    20 February 2023 					*/
/*	 Version 			:    2.0V 							 	*/
/*	 Description 		:    Config files Config for switches  	*/
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef SWITCHES_CONFIG_H
#define SWITCHES_CONFIG_H


/********************************************/
/*    GLOBAL DATA TYPES AND STRUCTURES     */
/******************************************/

/* Push Bottun */

typedef enum 
{
	PB_1=1,
	PB_2,
	PB_3,
	PB_4
}switch_id_t;


/* State of the Bottun */

typedef enum 
{
	RELEASED =0 ,
	PRESSED
}state;

/********************************************/
/*         GLOBAL CONSTANT MACROS          */
/******************************************/

#define PULL_UP   1
#define PULL_DOWN 0



#define PB1_CONNECTION   PULL_UP
#define PB2_CONNECTION   PULL_UP
#define PB3_CONNECTION   PULL_UP
#define PB4_CONNECTION   PULL_UP


#define PB1_PORT    DIO_PORTD
#define PB2_PORT    DIO_PORTD
#define PB3_PORT    DIO_PORTD
#define PB4_PORT    DIO_PORTD



#define PB1_PIN   DIO_PIN7
#define PB2_PIN   DIO_PIN6 
#define PB3_PIN   DIO_PIN5
#define PB4_PIN   DIO_PIN3





#endif /* End of the file guard*/