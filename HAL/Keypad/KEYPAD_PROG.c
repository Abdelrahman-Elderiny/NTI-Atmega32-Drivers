/*****************************************************************/
/* 	Author 	 	 : Abdelrahman Magdy                            */
/* 	Date   		 : 15 February 2023                            */
/* 	Version 	 : 1.0V								          */
/* 	Description	 : prog.c for KPD                            */
/************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "KEYPAD_INT.h"

/****************************************************************/
/*********************** FUNC IMPLEMENTATION ********************/
/****************************************************************/

/*************************************/
/*          GLOBAL DATA              */
/*************************************/
static u8 keys_value[4][4]=
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'F','0','E','D'}
};

/***********************************************************************/
/* Description    : This function used to intialization of KPD        */ 
/*																     */
/*					Inputs : void					  			    */
/*					Return : void		 					       */
/******************************************************************/

void keypad_vidInit(void)
{
		/*	ROW channel direction -> output	*/
	dio_vidConfigChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,OUTPUT);
	
	/*	COLUMN channel direction -> input	*/
	dio_vidConfigChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL,INPUT);
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_LOW);
}

/***********************************************************************/
/* Description    : This function used to know the if                 */ 
/*				        button is pressed or not  				     */
/*					Inputs : void					  			    */
/*					Return : TRUE / FALSE 					       */
/******************************************************************/

boolean keypad_bolIsPressed(void)
{
	if (
		!dio_dioLevelReadChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL)||
		!dio_dioLevelReadChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL)||
		!dio_dioLevelReadChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL)||
		!dio_dioLevelReadChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL)
		)
		{
		  return TRUE;
		}
		else
		{
		  return FALSE;
		}
}

/***********************************************************************/
/* Description    : This function used to know the coloum             */ 
/*				                                         		     */
/*					Inputs : void					  			    */
/*					Return : COLUMN Location				       */
/******************************************************************/

u8 keypad_GetCol(void)
{
	u8 loc_row = 0;
	if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL))
	{
		loc_row = 1;	
	}
	else if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL))
	{
	 loc_row = 2;	
	}
	else if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL))
	{
	 loc_row = 3;	
	}
	else if (STD_LOW == dio_dioLevelReadChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL))
	{
	 loc_row = 4;	
	}
	else
	{
		/*	do nothing	*/
	}
	return loc_row;
}

/***********************************************************************/
/* Description    : This function used to know the Row                */ 
/*				                                         		     */
/*					Inputs : void					  			    */
/*					Return : ROW Location			     	       */
/******************************************************************/

u8 keypad_GetRow(u8 col)
{
	u8 loc_row =0;
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
	
	if (keypad_GetCol() == col)
	{
		loc_row = 1;	
	}
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
	if (keypad_GetCol() == col)
	{
		loc_row = 2;	
	}
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
	if (keypad_GetCol() == col)
	{
		loc_row = 3;	
	}
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_LOW);
	if (keypad_GetCol() == col)
	{
		loc_row = 4;	
	}
	
	return loc_row;
}

/***********************************************************************/
/* Description    : This function used to get the pressed key         */ 
/*																     */
/*					Inputs : void					  			    */
/*					Return : u8 pressed switch   			       */
/******************************************************************/

u8 keypad_u8GetKey(void)
{
	u8 loc_row = 0;
	u8 loc_col = 0;
	
	if (TRUE == keypad_bolIsPressed())
	{
		loc_col = keypad_GetCol();
		loc_row = keypad_GetRow(loc_col);
		_delay_ms(250);	
		keypad_vidInit();	
		return 	keys_value[loc_row-1][loc_col-1];
	}
	else
	{
		return 100;
	}
}
/************************************************************************************************/
/*********************************** END OF THE PROGRAM *****************************************/
/************************************************************************************************/
