/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    25 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Configuration for 
                          Interrupt Sense Control  	            */
/****************************************************************/



/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/
#ifndef _EXTI_CONFIG_H
#define _EXTI_CONFIG_H

/****************************************************************/
/**     Please Enter the Sense Mode for [EXTI0,EXTI1,EXTI2]     */
/** 		   SENSE_MODE can be : 	    						*/
/*					    			FALLING 					*/
/*						    		RISING 						*/
/*							    	LOW_LEVEL					*/
/*								    ON_CHANGE                   */
/****************************************************************/

#define EXTI0_SENSE_CONTROL      FALLING

#define EXTI1_SENSE_CONTROL      FALLING

#define EXTI2_SENSE_CONTROL      FALLING

/****************************************************************/
/**     Please Enter the desired Channel to use from 
                   [EXTI0,EXTI1,EXTI2]                          */
/** 		   SENSE_MODE can be : 	    						*/
/*					    			EXTI0 				    	*/
/*						    		EXTI1 				 		*/
/*							    	EXTI2				    	*/
/****************************************************************/

#define EXTI_SELECT              EXTI2_ACTIVE




#endif /* End of the file guard*/