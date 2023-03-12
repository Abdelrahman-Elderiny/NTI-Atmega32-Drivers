/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LCD_H
#define LCD_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "dio.h"
#include "LcdCfg.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	HomeReturn=0x02,
	ClearLCD=0x01,
	DisplayCursor=0x0E,
	HideCursor=0x0C,
	MatrixFiveByTen=0x28
	}lcd_Cmd_Type;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void lcd_init(void);
void lcd_sendData(u8 data);
void lcd_sendCmd(lcd_Cmd_Type cmd);
void lcd_gotoRowColumn(u8 row, u8 column);
void lcd_displyChar(u8 chr);
void lcd_displyStr(u8* str);
void lcd_customWrite(u8* custCfg);
 
#endif

/**********************************************************************************************************************
 *  END OF FILE: FILE_NAME.h
 *********************************************************************************************************************/


