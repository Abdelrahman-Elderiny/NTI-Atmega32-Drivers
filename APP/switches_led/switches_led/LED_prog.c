/*****************************************************************/
/* 	Author 	 	 : Abdelrahman Magdy                            */
/* 	Date   		 : 20 February 2023                            */
/* 	Version 	 : 2.0V								          */
/* 	Description	 : prog.c for ;ED                            */
/************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "LED_int.h"

/****************************************************************/
/*********************** FUNC IMPLEMENTATION ********************/
/****************************************************************/

/***********************************************************************/
/* Description    : This function used to intialization of LED        */ 
/*																     */
/*					Inputs : void					  			    */
/*					Return : void		 					       */
/******************************************************************/

void led_init(void)
{
	dio_vidConfigChannel(LED_RED_PORT,LED_RED_CHANNEL,OUTPUT);
	dio_vidConfigChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,OUTPUT);
	dio_vidConfigChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,OUTPUT);
	dio_vidConfigChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,OUTPUT);
}

/***********************************************************************/
/* Description    : This function used to Turn LED ON                 */ 
/*																     */
/*					Inputs : led_id -> ledId		  			    */
/*					Return : void		 					       */
/******************************************************************/

void led_on(led_id ledId)
{
	switch(ledId)
	{
		case LED_RED:
		
		#if (LED_RED_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_LOW);
		#endif	
		
		break;
		
		case LED_GREEN:
		
		#if (LED_GREEN_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_LOW);
		#endif
		
		break;
		
		case LED_BLUE:
		
		#if (LED_BLUE_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_LOW);
		#endif
		
		break;
		
		case LED_YELLOW:
		
		#if (LED_YELLOW_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_LOW);
		#endif
		
		break;
	}
}

/***********************************************************************/
/* Description    : This function used to Turn LED OFF                */ 
/*																     */
/*					Inputs : led_id -> ledId		  			    */
/*					Return : void		 					       */
/******************************************************************/

void led_off(led_id ledId)
{
	switch(ledId)
	{
		case LED_RED:
		
		#if (LED_RED_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_HIGH);
		#endif	
		
		break;
		
		case LED_GREEN:
		
		#if (LED_GREEN_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_HIGH);
		#endif
		
		break;
		
		case LED_BLUE:
		
		#if (LED_BLUE_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_HIGH);
		#endif
		
		break;
		
		case LED_YELLOW:
		
		#if (LED_YELLOW_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_HIGH);
		#endif
		
		break;
	}
}

/***********************************************************************/
/* Description    : This function used to TOGGLE LED ON               */ 
/*																     */
/*					Inputs : led_id -> ledId	     			    */
/*					Return : void		 					       */
/******************************************************************/

void led_toggle(led_id ledId)
{
	switch(ledId)
	{
		case LED_RED:
		
			dio_vidFlipChannel(LED_RED_PORT,LED_RED_CHANNEL);
			
		break;
		
		case LED_GREEN:
		
			dio_vidFlipChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL);
			
		break;
		
		case LED_BLUE:
		
			dio_vidFlipChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL);

		break;
		
		case LED_YELLOW:
		
			dio_vidFlipChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL);
			
		break;
	}
}

/**************************************************************************/
/************************* END OF THE PROGRAM *****************************/
/**************************************************************************/
