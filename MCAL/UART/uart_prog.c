/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
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

#include "uart_int.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/******************** Global Variables **************************/
/****************************************************************/

static u8 ucsrb ;
static u8 ucsrc ; 

/****************************************************************/
/* Description    : This function used for UART INIT         	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void UART_Init(void)
{
	/* Config. For TX & RX */
	/**************************************************/
	
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN0,INPUT);
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN1,OUTPUT);
	
	SET_BIT (UCSRB,TXB8);
	SET_BIT (UCSRB,RXB8);
	
	/**************************************************/
	
	/* Character Size  */
	/**************************************************/
	
	#if (UART_DATA_SIZE == UART_5_BIT_DATA)
	
	ucsrb |= (0 << UCSZ2) ;
	ucsrc |= (0 << UCSZ1) | (0 << UCSZ0);
	
	#elif (UART_DATA_SIZE == UART_6_BIT_DATA)
	
	ucsrb |= (0 << UCSZ2) ;
	ucsrc |= (0 << UCSZ1) | (1 << UCSZ0);
	
	#elif (UART_DATA_SIZE == UART_7_BIT_DATA)
	
	ucsrb |= (0 << UCSZ2) ;
	ucsrc |= (1 << UCSZ1) | (0 << UCSZ0);
	
	#elif (UART_DATA_SIZE == UART_8_BIT_DATA)
	
	ucsrb |= (0 << UCSZ2) ;
	ucsrc |= (1 << UCSZ1) | (1 << UCSZ0);
	
	#elif (UART_DATA_SIZE == UART_9_BIT_DATA)
	
	ucsrb |= (1 << UCSZ2) ;
	ucsrc |= (1 << UCSZ1) | (1 << UCSZ0);
	
	#endif
	/**************************************************/
	
	/**************************************************/
	
	/* Mode && Clock polarity && Speed */
	/**************************************************/
	
	#if (UART_MODE == ASYNCHRONOUS && UART_SPEED == SINGLE)
	
	ucsrc |= (0 << UMSEL) ;  
	CLEAR_BIT (UCSRA,U2X);
	
	#elif (UART_MODE == ASYNCHRONOUS && UART_SPEED == DOUBLE)
	
	ucsrc |= (0 << UMSEL) ;
	SET_BIT (UCSRA,U2X);
	
	#elif (UART_MODE == SYNCHRONOUS && UART_CLK_POLARITY == FALLING_EDGE )
	
	ucsrc |= (1 << UMSEL) ; 
	ucsrc |= (1 << UCPOL) ;
	
	#elif (UART_MODE == SYNCHRONOUS && UART_CLK_POLARITY == RISING_EDGE )
	
	ucsrc |= (1 << UMSEL) ;
	ucsrc |= (0 << UCPOL) ;
	
	#endif
	/**************************************************/
	
	/**************************************************/
	
	/* Parity Bit */
	/**************************************************/
	
	#if (UART_PARITY_BIT == UART_EVEN_PARITY)
	
	ucsrc |= (0 << UPM0) ;
	ucsrc |= (1 << UPM1) ;
	
	#elif (UART_PARITY_BIT == UART_ODD_PARITY)
	
	ucsrc |= (1 << UPM0) ;
	ucsrc |= (1 << UPM1) ;
	
	#elif (UART_PARITY_BIT == UART_NO_PARITY)
	
	ucsrc |= (0 << UPM0) ;
	ucsrc |= (0 << UPM1) ;
	
	#endif
	/**************************************************/
	
	/* Stop Bit */
	/**************************************************/
	
	#if (UART_STOP_BIT == UART_1_STOP_BIT)
	
	ucsrc |= (0 << USBS) ;
	
	#elif (UART_STOP_BIT == UART_1_STOP_BIT)
	
	ucsrc |= (1 << USBS) ;
		
	#endif
	/**************************************************/
	
	UCSRB = ucsrb ;
	
	SET_BIT (UCSRC , URSEL);
	
	UCSRC = ucsrc ;
}

/****************************************************************/
/* Description    : This function used for UART Sending        	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void UART_TransmitChr(u8 data)
{
	SET_BIT (UCSRB , TXEN );
	while (!CHECK_BIT (UCSRA,UDRE));
	
	UDR = data;
}
/*u8 buffer[200];
u8 current_index=0;*/
void UART_TransmitString (u16 *str)
{
	SET_BIT (UCSRB , TXEN );
	while (!(CHECK_BIT(UCSRA,UDRE)));
	u8 i=0;
	while(*str!='\0')
	{
		UART_TransmitChr(str[i]);
		i++;
	}
	
}
/****************************************************************/
/* Description    : This function used for UART Receive      	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

u8 UART_ReceiveChr(void)
{
	SET_BIT (UCSRB , RXEN );
	while (!CHECK_BIT (UCSRA,RXC));
	
	return UDR ;
}