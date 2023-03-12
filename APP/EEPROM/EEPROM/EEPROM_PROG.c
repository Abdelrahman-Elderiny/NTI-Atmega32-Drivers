/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    11 March 2023 	     				*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   prog.c for EEPROM                   */
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EEPROM_INT.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : This function used for Send& Write         	*/
/*					Inputs : u16 Address&u8 data			  	*/
/*					Return : void		 					    */
/****************************************************************/

void EEPROM_vidWrite(u16 address , u8 data )
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEARL = address;
	EEDR = data;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

/****************************************************************/
/* Description    : This function used for recieve & Read      	*/
/*					Inputs : u16 Address        			  	*/
/*					Return : u8 data     					    */
/****************************************************************/

u8 EEPROM_Read(u16 address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEARL = address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}