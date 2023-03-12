/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    25 February 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							and Sense Mode Definition [int.h] 	*/
/****************************************************************/


/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/
#ifndef _EXTI_INT_H
#define _EXTI_INT_H

/****************************************************************/	
/**              Interrupt Sense Control Definition	     		*/
/****************************************************************/

#define ON_CHANGE    1
#define FALLING      2
#define RISING       3
#define LOW_LEVEL    4

/****************************************************************/	
/**                   Select Which Interrupt    	     		*/
/****************************************************************/

#define EXTI0_ACTIVE   1 

#define EXTI1_ACTIVE   2 

#define EXTI2_ACTIVE   3
/****************************************************************/
/* Description    :  This function used to initialize EXTI0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void EXTI0_voidInit ( void );

/****************************************************************/
/* Description    :  This function used to initialize EXTI1      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void EXTI1_voidInit ( void );

/****************************************************************/
/* Description    :  This function used to initialize EXTI2      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void EXTI2_voidInit ( void );


/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI0_voidEnable( void );

/****************************************************************/
/* Description    : This function used to Enable EXT1			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI1_voidEnable( void );

/****************************************************************/
/* Description    : This function used to Enable EXT2			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI2_voidEnable( void );

/****************************************************************/
/* Description    : This function used to Disable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI0_voidDisable( void );

/****************************************************************/
/* Description    : This function used to Disable EXT1			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI1_voidDisable( void );

/****************************************************************/
/* Description    : This function used to Disable EXT2			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI2_voidDisable( void );

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*						   [For External Interrupt Zero ]									*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI0_VidReciever (void (*recieverfunc) (void));

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*						   [For External Interrupt One ]									*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI1_VidReciever (void (*recieverfunc) (void));

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*						   [For External Interrupt Two ]									*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI2_VidReciever (void (*recieverfunc) (void));

/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*					    [For External Interrupt Zero ]			*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidSetSignalch(u8 SenseCpy);

/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*					    [For External Interrupt One ]			*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidSetSignalch(u8 SenseCpy);

/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*					    [For External Interrupt Two ]			*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidSetSignalch(u8 SenseCpy);




#endif /* End of the file guard*/
