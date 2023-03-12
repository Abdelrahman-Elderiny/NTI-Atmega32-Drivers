/*****************************************************************/
/* 	Author 	 	 : Abdelrahman Magdy                            */
/* 	Date   		 : 20 February 2023                            */
/* 	Version 	 : 2.0V								          */
/* 	Description	 : prog.c for Switches                       */
/************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "SWITCHES_INT.h"

/****************************************************************/
/*********************** FUNC IMPLEMENTATION ********************/
/****************************************************************/

/****************************************************************/
/* Description    :  This function used to Init switches        */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void switch_vidInit(void)
{
	/********* Config The channels as INPUT **********/
	
	dio_vidConfigChannel(PB1_PORT,PB1_PIN,INPUT);	
	dio_vidConfigChannel(PB2_PORT,PB2_PIN,INPUT);
	dio_vidConfigChannel(PB3_PORT,PB3_PIN,INPUT);
	dio_vidConfigChannel(PB4_PORT,PB4_PIN,INPUT);
	
	/***** Make a Internaly Pull up Resistor ******/
	
	dio_vidWriteChannel (PB1_PORT,PB1_PIN,STD_HIGH);
	dio_vidWriteChannel (PB2_PORT,PB2_PIN,STD_HIGH);
	dio_vidWriteChannel (PB3_PORT,PB3_PIN,STD_HIGH);
	dio_vidWriteChannel (PB4_PORT,PB4_PIN,STD_HIGH);
}

/***********************************************************************/
/* Description    : This function used to intialization of switches   */ 
/*																     */
/*					Inputs : switch -> from type of enum 		    */
/*					Return : state of button 				       */
/******************************************************************/

u8 switch_GetStatus(switch_id_t button)
{
	state status = RELEASED ;

	switch (button)
	{
		/******** SWITCH 1 *********/
		case PB_1 :
		#if (PB1_CONNECTION == PULL_DOWN)
		if (dio_dioLevelReadChannel(PB1_PORT,PB1_PIN) == STD_HIGH)
		{
			status = PRESSED ;
		} 
		else 
		{
			status = RELEASED ;
		}
		#elif (PB1_CONNECTION == PULL_UP)
		if (dio_dioLevelReadChannel(PB1_PORT,PB1_PIN) == STD_LOW)
		{
			status = PRESSED ;
		}
		else
		{
			status = RELEASED ;
		}
		#endif
		break;
		
		/******** SWITCH 2 *********/
		
		case PB_2 :
		#if (PB2_CONNECTION == PULL_DOWN)
		if (dio_dioLevelReadChannel(PB2_PORT,PB2_PIN) == STD_HIGH)
		{
			status = PRESSED ;
		}
		else
		{
			status = RELEASED ;
		}
		#elif (PB2_CONNECTION == PULL_UP)
		if (dio_dioLevelReadChannel(PB2_PORT,PB2_PIN) == STD_LOW)
		{
			status = PRESSED ;
		}
		else
		{
			status = RELEASED ;
		}
		#endif
		break;
		
		/******** SWITCH 3 *********/
		
		case PB_3 :
		#if (PB3_CONNECTION == PULL_DOWN)
		if (dio_dioLevelReadChannel(PB3_PORT,PB3_PIN) == STD_HIGH)
		{
			status = PRESSED ;
		}
		else
		{
			status =  RELEASED ;
		}
		#elif (PB3_CONNECTION == PULL_UP)
		if (dio_dioLevelReadChannel(PB3_PORT,PB3_PIN) == STD_LOW)
		{
			status=  PRESSED ;
		}
		else
		{
			status = RELEASED ;
		}
		#endif
		break;
		
		/******** SWITCH 4 *********/
		
		case PB_4 :
		#if (PB4_CONNECTION == PULL_DOWN)
		if (dio_dioLevelReadChannel(PB4_PORT,PB4_PIN) == STD_HIGH)
		{
			status = PRESSED ;
		}
		else
		{
			status = RELEASED ;
		}
		#elif (PB4_CONNECTION == PULL_UP)
		if (dio_dioLevelReadChannel(PB4_PORT,PB4_PIN) == STD_LOW)
		{
			status = PRESSED ;
		}
		else
		{
			status = RELEASED ;
		}
		#endif
		break;
	}
	return status ;
}

