/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    6 March 2023    					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Private file for UART              */
/****************************************************************/



/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _UART_PRIV
#define _UART_PRIV

/**********************************************/
/*           Address of UDR register         */
/********************************************/

#define UDR      (*(volatile u8* )0x2C)

/**********************************************/
/*           Address of UCSRA register       */
/*               and its bits               */
/*******************************************/

#define UCSRA      (*(volatile u8* )0x2B)
#define RXC    7 
#define TXC    6
#define UDRE   5
#define FE     4
#define DOR    3
#define PE     2
#define U2X    1
#define MPCM   0

/**********************************************/
/*           Address of UCSRB register       */
/*               and its bits               */
/*******************************************/

#define UCSRB      (*(volatile u8* )0x2A)
#define RXCIE    7
#define TXCIE    6
#define UDRIE    5
#define RXEN     4
#define TXEN     3
#define UCSZ2    2
#define RXB8     1
#define TXB8     0

/**********************************************/
/*           Address of UCSRC&UBRRH register */
/*               and its bits               */
/*******************************************/

#define UCSRC      (*(volatile u8* )0x40)
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0 

#define UBRRH      (*(volatile u8* )0x40)
#define URSEL  7 
#define UBRR   0

/**********************************************/
/*           Address of UBRRL register       */
/********************************************/

#define UBRRL	  (*(volatile u8* )0x29)

/*************************************************/
/*           MACROS TO SELECT Baud Rate         */
/***********************************************/

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x1A0)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x8) 

/*************************************************/
/*      MACROS TO SELECT Data Bits size         */
/***********************************************/

#define UART_5_BIT_DATA				5
#define UART_6_BIT_DATA				6
#define UART_7_BIT_DATA				7
#define UART_8_BIT_DATA				8
#define UART_9_BIT_DATA             9

/*************************************************/
/*           MACROS TO SELECT Stop Bits         */
/***********************************************/

#define UART_1_STOP_BIT				1
#define UART_2_STOP_BIT				2

/*************************************************/
/*           MACROS TO SELECT Parity Bits       */
/***********************************************/

#define UART_EVEN_PARITY			2
#define UART_ODD_PARITY				1
#define UART_NO_PARITY              0

/*************************************************/
/*    MACROS TO SELECT Speed Double OR Single   */
/***********************************************/

#define SINGLE			1
#define DOUBLE			2

/*************************************************/
/*       MACROS TO SELECT Synch or Asynch       */
/***********************************************/

#define ASYNCHRONOUS			1
#define SYNCHRONOUS		     	2

/*************************************************/
/*       MACROS TO SELECT Clock Polarity        */
/***********************************************/

#define FALLING_EDGE			1
#define RISING_EDGE		     	2

#endif /* End of the file guard*/

/********************************************
 *  END OF FILE: uart_priv.h
 *******************************************/
