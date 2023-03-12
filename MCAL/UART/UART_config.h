/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    6 March 2023    					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configuration file for UART        */
/****************************************************************/

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/*************************************************/
/*            MACRO TO SELECT Baud Rate         */
/***********************************************/

/*UART_BAUDRATE_1200	
UART_BAUDRATE_2400	
UART_BAUDRATE_4800	
UART_BAUDRATE_9600	
UART_BAUDRATE_19200	
UART_BAUDRATE_115200*/

#define UART_BAUD_RATE    UART_BAUDRATE_9600

/*************************************************/
/*      MACRO TO SELECT Data Bits size          */
/***********************************************/

/*UART_5_BIT_DATA
UART_6_BIT_DATA
UART_7_BIT_DATA
UART_8_BIT_DATA
UART_9_BIT_DATA*/

#define UART_DATA_SIZE   UART_8_BIT_DATA

/*************************************************/
/*           MACRO TO SELECT Stop Bits          */
/***********************************************/

/*UART_1_STOP_BIT
UART_2_STOP_BIT*/

#define UART_STOP_BIT   UART_1_STOP_BIT

/*************************************************/
/*           MACRO TO SELECT Parity Bits        */
/***********************************************/

/*UART_NO_PARITY
UART_EVEN_PARITY
UART_ODD_PARITY*/

#define UART_PARITY_BIT   UART_EVEN_PARITY

/*************************************************/
/*     MACRO TO SELECT Speed Double OR Single   */
/***********************************************/

/*SINGLE
DOUBLE*/

#define UART_SPEED    SINGLE

/*************************************************/
/*       MACRO TO SELECT Synch or Asynch        */
/***********************************************/

/*ASYNCHRONOUS
SYNCHRONOUS	*/

#define UART_MODE   ASYNCHRONOUS  

/*************************************************/
/*        MACRO TO SELECT Clock Polarity        */
/***********************************************/

/*FALLING_EDGE
RISING_EDGE*/

#define UART_CLK_POLARITY     FALLING_EDGE

#endif /* End of the file guard*/

/********************************************
 *  END OF FILE: uart_config.h
 *******************************************/
