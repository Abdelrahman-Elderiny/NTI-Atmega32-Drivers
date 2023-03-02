/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    19 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/****************************************************************/

/**********************************************************************************************************************
                                                   INCLUDES
 *********************************************************************************************************************/

#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "LCD_CONFIG.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _LCD_INT_H
#define _LCD_INT_H

/****************************************************************/
/* Description    : This function used for LCD INIT         	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidInit(void);

/****************************************************************/
/* Description    : This function used to send data             */
/*                     to LCD & print it on LCD             	*/ 
/*																*/
/*					Inputs : data -> from type of unit 8		*/
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidSendData(u8 data);

/****************************************************************/
/* Description    : This function used to send CMD              */
/*                     to LCD & print it on LCD             	*/ 
/*																*/
/*					Inputs : cmd  -> from type enum (lcd_cmd_t) */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidSendCmd(u8 cmd);

/****************************************************************/
/* Description    : This function used to write on              */
/*                 desired place in rows and coloums          	*/ 
/*																*/
/*					Inputs : ROW & COLUMN from type of unit 8   */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidGotoRowColumn(u8 row, u8 column);

/****************************************************************/
/* Description    : This function used to write on              */
/*                         LCD input numbers                	*/ 
/*																*/
/*					Inputs : Integer from type of  unit 8       */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidDisplyInt(u16 num);

/****************************************************************/
/* Description    : This function used to write on              */
/*                         LCD list of strings                	*/ 
/*																*/
/*					Inputs : String from type of                */
/*                           pointer of unit 8                  */
/*					Return : void		 					    */
/****************************************************************/

void lcd_vidDisplyStr (char *str);



#endif /* End of the file guard*/
