/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    6 March 2023     					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "spi_private_reg.h"
#include "spi_master_config.h"
#include "dio_reg.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/
#ifndef SPI_INIT_H_
#define SPI_INIT_H_

/*************************************************/
/*                 Global MACRO                 */
/***********************************************/

#define Foscprescaler4     0
#define Foscprescaler16    1
#define Foscprescaler64    2
#define Foscprescaler128   3
#define Foscprescaler2     4
#define Foscprescaler8     5
#define Foscprescaler32    6

/****************************************************************/
/* Description    : This function used for SPI INIT MASTER     	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_mstr_init(void);

/****************************************************************/
/* Description    : This function used for SPI INIT Slave     	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_slave_init(void);

/****************************************************************/
/* Description    : This function used for Byte Transmission   	*/
/*																*/
/*					Inputs : byte					  			*/
/*					Return : byte		 					    */
/****************************************************************/

u8 SPI_mstr_transev_byte(u8 byte);

/****************************************************************/
/* Description    : This function used for Master send byte   	*/
/*																*/
/*					Inputs : Data					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_mstr_send_byte(u8 byte);

/****************************************************************/
/* Description    : This function used for Master send string  	*/
/*																*/
/*					Inputs : string					  			*/
/*					Return : void		 					    */
/****************************************************************/

void  SPI_mstr_send_string (char *str);

/****************************************************************/
/* Description    : This function used for slave send data  	*/
/*																*/
/*					Inputs : data					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_slave_transmit_byte(u8 byte);

/****************************************************************/
/* Description    : This function used for slave recieve data  	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : data from SPDR		 			    */
/****************************************************************/

u8 SPI_slave_recieve_byte(void);

/****************************************************************/
/* Description    : This function used for master recieve data  */
/*																*/
/*					Inputs : void					  			*/
/*					Return : data from SPDR		 			    */
/****************************************************************/

u8 SPI_master_recieve_byte(void);

#endif /* SPI_INIT_H_ */