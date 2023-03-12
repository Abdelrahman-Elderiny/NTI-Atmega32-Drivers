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

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*************************************************/
/*         MACRO TO SELECT MODES OF MASTER      */
/***********************************************/

#define  mosi_port_num DIO_DDRB_REG

#define miso_port_num DIO_DDRB_REG

#define  ss_port_num DIO_DDRB_REG

#define  sck_port_num DIO_DDRB_REG

#define clock_rate Foscprescaler4

#define data_order MSB

#define sample STD_LOW

#define clk_polarity STD_LOW

#define MOSI	5

#define MISO	6

#define SCK		7

#define SS	    4

#define double_speed 0


#endif /* End of the file guard*/