/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    6 March 2023    					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Private file for SPI               */
/****************************************************************/



/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef SPI_PRIVATE_REG_H_
#define SPI_PRIVATE_REG_H_

/**********************************************/
/*           Address of SPCR register        */
/*               and its bits               */
/*******************************************/

#define SPCR  (*(volatile u8*) (0x2D))

#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL    3
#define CPHA	2
#define SPR1    1
#define SPR0    0

/**********************************************/
/*           Address of SPSR register        */
/*               and its bits               */
/*******************************************/

#define SPSR (*(volatile u8*) (0x2E))
#define SPIF 	7
#define WCOL	6
#define SPI2X	0

/**********************************************/
/*           Address of SPDR register        */
/********************************************/

#define SPDR (*(volatile u8*) (0x2F))

#endif /* End of the file guard*/
