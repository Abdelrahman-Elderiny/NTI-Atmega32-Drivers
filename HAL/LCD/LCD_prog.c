/*****************************************************************/
/* 	Author 	 	 : Abdelrahman Magdy                            */
/* 	Date   		 : 19 February 2023                            */
/* 	Version 	 : 1V 								          */
/* 	Description	 : prog.c for LCD                            */
/************************************************************/



/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#define F_CPU 16000000
#include <util/delay.h>
#include "dio.h"
#include "LCD_CONFIG.h"
#include "LCD_INT.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/******************************************************************************/
/* Description : send enable pulse to LCD HW                                 */                                
/*                  Inputs : void					  	             		*/
/*					Return : void                                          */
/**************************************************************************/

static void enablePulse(void)
{
	dio_vidWriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_HIGH);
	_delay_ms(1);
	dio_vidWriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_LOW);
	_delay_ms(1);
}

/****************************************************************/
/* Description    : This function used for LCD INIT         	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidInit(void)
{
	        /* config for Control Bits (RS & EN) */
			/* !Note :- RW is connected to GND  */
			
	dio_vidConfigChannel(LCD_RS_PORT, LCD_RS_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_EN_PORT, LCD_EN_CHANNEL, OUTPUT);

	       /* config for Data Bits (D4&D5&D6&D7) */
	
	dio_vidConfigChannel(LCD_D4_PORT, LCD_D4_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_D5_PORT, LCD_D5_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_D6_PORT, LCD_D6_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_D7_PORT, LCD_D7_CHANNEL, OUTPUT);
	
	_delay_ms(20);
	lcd_vidSendCmd(Fourbit_OLine);
	lcd_vidSendCmd(Fourbit_TLine);
	lcd_vidSendCmd(Display_on_Cursor_off);
	lcd_vidSendCmd(EntryMode);
	lcd_vidSendCmd(ClearDisplay);
	_delay_ms(2);
	
	
}

/****************************************************************/
/* Description    : This function used to send CMD              */
/*                     to LCD & print it on LCD             	*/ 
/*																*/
/*					Inputs : cmd  -> from type enum (lcd_cmd_t) */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidSendCmd(u8 cmd)
{
	dio_vidWriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_LOW);

	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(cmd,4));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(cmd,5));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(cmd,6));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(cmd,7));
	
	enablePulse();
	
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(cmd,0));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(cmd,1));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(cmd,2));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(cmd,3));
	
	enablePulse();
}

/****************************************************************/
/* Description    : This function used to send data             */
/*                     to LCD & print it on LCD             	*/ 
/*																*/
/*					Inputs : data -> from type of unit 8		*/
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidSendData(u8 data)
{
	dio_vidWriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_HIGH);

	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(data,4));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(data,5));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(data,6));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(data,7));
	
	enablePulse();
	
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(data,0));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(data,1));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(data,2));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(data,3));
	
	enablePulse();
}

/****************************************************************/
/* Description    : This function used to write on              */
/*                 desired place in rows and coloums          	*/ 
/*																*/
/*					Inputs : ROW & COLUMN from type of unit 8   */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidGotoRowColumn(u8 row, u8 column)
{
	switch (row)
	{
	case 0:
		/*	Row 0	*/
		lcd_vidSendCmd(0x80 + column);
		break;

	case 1:
		/* Row 1 */
		lcd_vidSendCmd(0x80 + 0x40 + column);
		break;
	case 2:
	
		lcd_vidSendCmd(0x80 + 0x14 + column );
		break;
	
	case 3:
	
		lcd_vidSendCmd(0x80 + 0x54 + column );
		break;
	
	
	}
}

/****************************************************************/
/* Description    : This function used to write on              */
/*                         LCD input numbers                	*/ 
/*																*/
/*					Inputs : Integer from type of  unit 8       */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidDisplyInt(u16 num)
{
	if (num != 0)
	{
	lcd_vidDisplyInt (num/10);
	lcd_vidSendData((num%10)+'0');
	}
}

/****************************************************************/
/* Description    : This function used to write on              */
/*                         LCD list of strings                	*/ 
/*																*/
/*					Inputs : String from type of                */
/*                           pointer of unit 8                  */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidDisplyStr(char *str)
{
	for (u8 Counter = 0 ; str [Counter] !='\0';Counter++)
	{
		lcd_vidSendData (str [Counter]);
	}
}