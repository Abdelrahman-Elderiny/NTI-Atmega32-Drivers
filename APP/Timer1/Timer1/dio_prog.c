/*****************************************************************/
/* 	Author 	 	 : Abdelrahman Magdy                            */
/* 	Date   		 : 19 February 2023                            */
/* 	Version 	 : 2.0 V							          */
/* 	Description	 : prog.c for DIO                            */
/************************************************************/

/***********************/
/*       INCLUDES      */
/***********************/
#include "dio.h"


/*******************************************************************/
/* Description    :  this service for configuring IO channel       */
/*					 Inputs : port 	    -> MC port ID              */
/*					          channel   -> MC channel ID           */
/*					          direction -> MC channel direction    */
/*					 return : void		 						   */
/*******************************************************************/

void dio_vidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction)
{
	switch (port)
	{
	case DIO_PORTA:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRA_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRA_REG,channel);
		}
		break;

	case DIO_PORTB:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRB_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRB_REG,channel);
		}
		break;

	case DIO_PORTC:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRC_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRC_REG,channel);
		}
		break;

	case DIO_PORTD:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRD_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRD_REG,channel);
		}
		break;
	}
}

/*******************************************************************/
/* Description    :  this service for writting on IO channel       */
/*					 Inputs : port 	    -> MC port ID              */
/*					          channel   -> MC channel ID           */
/*					          level     -> MC channel level        */
/*					 return : void		 						   */
/*******************************************************************/

void dio_vidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTA_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTA_REG,channel);
		}
		break;

	case DIO_PORTB:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTB_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTB_REG,channel);
		}
		break;

	case DIO_PORTC:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTC_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTC_REG,channel);
		}
		break;

	case DIO_PORTD:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTD_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTD_REG,channel);
		}
		break;
	}
}

/*************************************************************************/
/* Description    :  this service for writting on group of IO channels   */
/*					 Inputs : port  -> MC port ID                        */
/*					          value -> data value                        */
/*					          mask  -> data mask                         */
/*					 return : void		 						         */
/*************************************************************************/

/*void dio_vidWriteChannelGroup(dio_portId_t port,u8 value,u8 mask )
{
	value = 0 ;
	u8 pos= 0 , tmask = mask;
	while(!(tmask & 1))
	{
		pos++;
		tmask >>= 1;
	}
	switch (port)
	{
		case DIO_PORTA:
		
		DIO_PORTA = (DIO_PINA_REG & mask) >> pos;
		break;

		case DIO_PORTB:
		
		DIO_PORTB = (DIO_PINB_REG & mask) >> pos;
		break;

		case DIO_PORTC:
		
		DIO_PORTC = (DIO_PINC_REG & mask) >> pos;
		break;

		case DIO_PORTD:
		
		DIO_PORTD = (DIO_PIND_REG & mask) >> pos;
		break;
	}
	
	
}*/

/*************************************************************************/
/* Description    :  this service for fliping IO channel                 */
/*					 Inputs : port  -> MC port ID                        */
/*					          channel  -> MC channel ID                  */
/*					 return : void		 						         */
/*************************************************************************/

void dio_vidFlipChannel(dio_portId_t port, dio_channelId_t channel)
{
	switch (port)
	{
	case DIO_PORTA:
		FLIP_BIT(DIO_PORTA_REG,channel);
		break;

	case DIO_PORTB:
		FLIP_BIT(DIO_PORTB_REG,channel);
		break;

	case DIO_PORTC:
		FLIP_BIT(DIO_PORTC_REG,channel);
		break;

	case DIO_PORTD:
		FLIP_BIT(DIO_PORTD_REG,channel);
		break;
	}
}

/*************************************************************************/
/* Description    :  this service for reading IO channel                 */
/*					 Inputs : port     -> MC port ID                     */
/*					          channel  -> MC channel ID                  */
/*					 return : loc_pinRead   -> IO channel level 		 */						         
/*************************************************************************/

dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel)
{
	dio_level_t loc_pinRead = STD_LOW;
	switch (port)
	{
	 case DIO_PORTA:
		loc_pinRead = CHECK_BIT(DIO_PINA_REG, channel);
		break;

	 case DIO_PORTB:
		loc_pinRead = CHECK_BIT(DIO_PINB_REG, channel);
		break;

	 case DIO_PORTC:
		loc_pinRead = CHECK_BIT(DIO_PINC_REG, channel);
		break;

	 case DIO_PORTD:
		loc_pinRead = CHECK_BIT(DIO_PIND_REG, channel);
		break;
    }
	return loc_pinRead;
}

/*********************************************************************************/
/* Description    :  this service for enabling pull up resistor for IO channel   */
/*					 Inputs : port  -> MC port ID                                */
/*					          channel  -> MC channel ID                          */
/*					 return : loc_pinRead   -> IO channel level 	        	 */						         
/*********************************************************************************/

void dio_vidEnablePullUp(dio_portId_t port, dio_channelId_t channel)
{
	switch (port)
	{
		case DIO_PORTA:
		
			SET_BIT(port,channel);
			break;

		case DIO_PORTB:
			
			SET_BIT(DIO_PORTB_REG,channel);
		    break;

		case DIO_PORTC:
	
			SET_BIT(DIO_PORTC_REG,channel);
	    	break;

		case DIO_PORTD:

			SET_BIT(DIO_PORTD_REG,channel);
		    break;	
	}
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/