/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    19 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "dio_types.h"
#include "dio_reg.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef DIO_H_H
#define DIO_H_H

/*******************************************************************/
/* Description    :  this service for configuring IO channel       */
/*					 Inputs : port 	    -> MC port ID              */
/*					          channel   -> MC channel ID           */
/*					          direction -> MC channel direction    */
/*					 return : void		 						   */
/*******************************************************************/

void dio_vidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction);

/*******************************************************************/
/* Description    :  this service for writting on IO channel       */
/*					 Inputs : port 	    -> MC port ID              */
/*					          channel   -> MC channel ID           */
/*					          level     -> MC channel level        */
/*					 return : void		 						   */
/*******************************************************************/

void dio_vidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level);

/*************************************************************************/
/* Description    :  this service for writting on group of IO channels   */
/*					 Inputs : port  -> MC port ID                        */
/*					          value -> data value                        */
/*					          mask  -> data mask                         */
/*					 return : void		 						         */
/*************************************************************************/

void dio_vidWriteChannelGroup(dio_portId_t port,u8 value,u8 mask);

/*************************************************************************/
/* Description    :  this service for fliping IO channel                 */
/*					 Inputs : port  -> MC port ID                        */
/*					          channel  -> MC channel ID                  */
/*					 return : void		 						         */
/*************************************************************************/

void dio_vidFlipChannel(dio_portId_t port, dio_channelId_t channel);

/*************************************************************************/
/* Description    :  this service for reading IO channel                 */
/*					 Inputs : port     -> MC port ID                     */
/*					          channel  -> MC channel ID                  */
/*					 return : loc_pinRead   -> IO channel level 		 */						         
/*************************************************************************/

dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel);

/*********************************************************************************/
/* Description    :  this service for enabling pull up resistor for IO channel   */
/*					 Inputs : port  -> MC port ID                                */
/*					          channel  -> MC channel ID                          */
/*					 return : loc_pinRead   -> IO channel level 	        	 */						         
/*********************************************************************************/

void dio_vidEnablePullUp(dio_portId_t port, dio_channelId_t channel);
 
#endif  /* End of the file guard*/
