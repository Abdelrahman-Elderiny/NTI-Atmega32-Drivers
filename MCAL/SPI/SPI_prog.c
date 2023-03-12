/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    6 March 2023 			    		*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   prog.c for UART                     */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include <util/delay.h>
#include "spi_init.h"
#include "spi_master_config.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : This function used for SPI INIT MASTER     	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_mstr_init(void)
{
	
	
	SET_BIT(sck_port_num,SCK);
	SET_BIT( mosi_port_num,MOSI);
	SET_BIT(ss_port_num,SS);
	CLEAR_BIT(DIO_DDRB_REG,MISO);
	
	DIO_PORTB_REG|=(1<<SS);
	SET_BIT(SPCR,MSTR);
	
	#if data_order==MSB
	CLEAR_BIT(SPCR,DORD);
	
	
	#elif data_order==LSB
	SET_BIT(SPCR, DORD);
	#endif
	
	

	#if sample==STD_LOW
	CLEAR_BIT(SPCR,CPHA);
	
	#elif sample==STD_HIGH
	SET_BIT(SPCR,CPHA);
	#endif
	
	
	#if clk_polarity==STD_LOW
	CLEAR_BIT(SPCR,CPOL);
	#elif clk_polarity==STD_HIGH
	SET_BIT(SPCR,CPOL);
	#endif
	
	#if clock_rate == Foscprescaler4 
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);
	
	#elif clock_rate ==Foscprescaler16
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);
	
	#elif clock_rate ==Foscprescaler64
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);
		
	#elif clock_rate ==Foscprescaler128
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);

	#elif clock_rate ==Foscprescaler2
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPI2X);	
	
	#elif clock_rate ==Foscprescaler8
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPI2X);	
	
	#elif clock_rate ==Foscprescaler32
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPI2X);
	#endif
	CLEAR_BIT(DIO_PORTB_REG,SS);
	SET_BIT(SPCR,SPE);
}

/****************************************************************/
/* Description    : This function used for SPI INIT Slave     	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_slave_init(void){
	
	CLEAR_BIT(sck_port_num,SCK);
	SET_BIT( miso_port_num,MISO);
	CLEAR_BIT( ss_port_num,SS);	
	CLEAR_BIT( mosi_port_num,MOSI);

	#if sample==STD_LOW
	CLEAR_BIT(SPCR,CPHA);
	
	#elif sample==STD_HIGH
	SET_BIT(SPCR,CPHA);
	#endif
	
	
	#if clk_polarity==STD_LOW
	CLEAR_BIT(SPCR,CPOL);
	#elif clk_polarity==STD_HIGH
	SET_BIT(SPCR,CPOL);
	#endif
	
	SET_BIT(SPCR,SPE);
}

/****************************************************************/
/* Description    : This function used for Byte Transmission   	*/
/*																*/
/*					Inputs : byte					  			*/
/*					Return : void		 					    */
/****************************************************************/

u8 SPI_mstr_transev_byte(u8 byte){
	SPDR=byte;
	while (!(CHECK_BIT(SPSR,SPIF)));
	return SPDR;
}

/****************************************************************/
/* Description    : This function used for Master send byte   	*/
/*																*/
/*					Inputs : Data					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_mstr_send_byte(u8 byte)
{
	SPDR=byte;
	while (!(SPSR & (1<<SPIF)));	
}

/****************************************************************/
/* Description    : This function used for Master send string  	*/
/*																*/
/*					Inputs : string					  			*/
/*					Return : void		 					    */
/****************************************************************/

void  SPI_mstr_send_string (char *str)
{
		u8 i = 0;
		while (*(str+i) != '\0') {
			i++;
		}
	SPI_mstr_send_byte(i);
 	while(*str!='\0'){
 	SPI_mstr_send_byte(*str++);
 	while (!(SPSR & (1<<SPIF)));
 	_delay_ms(20);
 	}
}

/****************************************************************/
/* Description    : This function used for slave send data  	*/
/*																*/
/*					Inputs : data					  			*/
/*					Return : void		 					    */
/****************************************************************/

void SPI_slave_transmit_byte(u8 byte)
{
	SPDR=byte;
	while(!(SPSR & (1<<SPIF)));
}

/****************************************************************/
/* Description    : This function used for slave recieve data  	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : data from SPDR		 			    */
/****************************************************************/

u8 SPI_slave_recieve_byte(void){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

/****************************************************************/
/* Description    : This function used for master recieve data  */
/*																*/
/*					Inputs : void					  			*/
/*					Return : data from SPDR		 			    */
/****************************************************************/

u8 SPI_master_recieve_byte(void){
	SPI_mstr_send_byte(10);
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}