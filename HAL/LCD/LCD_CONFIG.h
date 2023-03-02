/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    25 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configuration file for LCD         */
/****************************************************************/


/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

/*************************************************/
/*            GLOBAL CONSTANT MACROS            */
/***********************************************/

#define LCD_RS_PORT				DIO_PORTA
#define LCD_RS_CHANNEL			DIO_PIN3

#define LCD_EN_PORT     		DIO_PORTA
#define LCD_EN_CHANNEL			DIO_PIN2

#define LCD_D4_PORT				DIO_PORTB
#define LCD_D4_CHANNEL			DIO_PIN0

#define LCD_D5_PORT				DIO_PORTB
#define LCD_D5_CHANNEL			DIO_PIN1

#define LCD_D6_PORT				DIO_PORTB
#define LCD_D6_CHANNEL			DIO_PIN2

#define LCD_D7_PORT				DIO_PORTB
#define LCD_D7_CHANNEL			DIO_PIN4

#define Fourbit_OLine           0x02      /* send for 4 bit initialization of LCD  */
#define Fourbit_TLine           0x28     /* 2 line, 5*7 matrix in 4-bit mode */
#define Display_on_Cursor_off   0x0c    /* Display on cursor off*/
#define EntryMode               0x06   /* Increment cursor (shift cursor to right)*/
#define ClearDisplay            0x01   /*Clear Display (also clear DDRAM content)*/


#endif  /* End of the file guard*/
