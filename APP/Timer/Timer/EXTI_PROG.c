/*****************************************************************/
/* 	Author 	 	 : Abdelrahman Magdy                            */
/* 	Date   		 : 25 February 2023                            */
/* 	Version 	 : 1V 								          */
/* 	Description	 : prog.c for [ EXTI0 , EXTI1 , EXTI2 ]       */
/************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI_INT.h"
#include "EXTI_CONFIG.h"
#include "EXTI_PRIVATE.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/



/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

#if (EXTI_SELECT == EXTI0_ACTIVE)
void EXTI0_voidInit ( void )
{
	/*  ( if / else if ) condition for Macros */
	#if EXTI0_SENSE_CONTROL == ON_CHANGE
	
	SET_BIT(MCUCR , ISC00);
	
	CLEAR_BIT(MCUCR , ISC01);
	
	#elif EXTI0_SENSE_CONTROL == FALLING
	
	SET_BIT(MCUCR , ISC00);
	
	SET_BIT(MCUCR , ISC01);
	
	#elif EXTI0_SENSE_CONTROL == RISING
	
	CLEAR_BIT(MCUCR , ISC00);
	
	SET_BIT  (MCUCR , ISC01 );
	
	#elif EXTI0_SENSE_CONTROL == LOW_LEVEL
	
	CLEAR_BIT(MCUCR , ISC00);
	
	CLEAR_BIT(MCUCR , ISC01);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , INT0 )  ;
	SET_BIT(GIFR    , INTF0 ) ;
}
#endif 


/****************************************************************/
/* Description    :  This function used to initialize EXT1      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

#if (EXTI_SELECT == EXTI1_ACTIVE)
void EXTI1_voidInit ( void )
{
	/*  ( if / else if ) condition for Macros */
	#if EXTI0_SENSE_CONTROL == ON_CHANGE
	
	SET_BIT(MCUCR , ISC10);
	
	CLEAR_BIT(MCUCR , ISC11);
	
	#elif EXTI0_SENSE_CONTROL == FALLING
	
	SET_BIT(MCUCR , ISC10);
	
	SET_BIT(MCUCR , ISC11);
	
	#elif EXTI0_SENSE_CONTROL == RISING
	
	CLEAR_BIT(MCUCR , ISC10);
	
	SET_BIT  (MCUCR , ISC11 );
	
	#elif EXTI0_SENSE_CONTROL == LOW_LEVEL
	
	CLEAR_BIT(MCUCR , ISC10);
	
	CLEAR_BIT(MCUCR , ISC11);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , INT1 )  ;
	SET_BIT(GIFR    , INTF1 ) ;
}
#endif 



/****************************************************************/
/* Description    :  This function used to initialize EXT2      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

#if (EXTI_SELECT == EXTI2_ACTIVE)
void EXTI2_voidInit ( void )
{
	/*  ( if / else if ) condition for Macros */
	#if EXTI2_SENSE_CONTROL == FALLING
	
	CLEAR_BIT(MCUCSR , ISC2);
	
	#elif EXTI2_SENSE_CONTROL == RISING
	
	SET_BIT  (MCUCSR , ISC2 );
	
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , INT2 )  ;
	SET_BIT(GIFR    , INTF2 ) ;
}
#endif 



/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI0_voidEnable( void )
{
	
	SET_BIT( GICR , INT0 );
	
}

/****************************************************************/
/* Description    : This function used to Enable EXT1			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI1_voidEnable( void )
{
	
	SET_BIT( GICR , INT1 );
	
}

/****************************************************************/
/* Description    : This function used to Enable EXT2			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI2_voidEnable( void )
{
	
	SET_BIT( GICR , INT2 );
	
}

/****************************************************************/
/* Description    : This function used to Disable EXT0			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI0_voidDisable( void )
{
	
	CLEAR_BIT( GICR , INT0 );
	
}

/****************************************************************/
/* Description    : This function used to Disable EXT1			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI1_voidDisable( void )
{
	
	CLEAR_BIT( GICR , INT1 );
	
}

/****************************************************************/
/* Description    : This function used to Disable EXT2			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI2_voidDisable( void )
{
	
	CLEAR_BIT( GICR , INT2 );
	
}

/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT0_voidSetSignalch(u8 SenseCpy)
{
		
	if (SenseCpy == ON_CHANGE)
	{
		
	SET_BIT(MCUCR , ISC00);
	
	CLEAR_BIT(MCUCR , ISC01);
	
	}
	
	else if (SenseCpy == FALLING)
	{
		
	SET_BIT(MCUCR , ISC00);
	
	SET_BIT(MCUCR , ISC01);
	
	}
	
	else if ( EXTI0_SENSE_CONTROL == RISING )
	{
		
	CLEAR_BIT(MCUCR , ISC00);
	
	SET_BIT  (MCUCR , ISC01 );
	
	}
	
	else if ( EXTI0_SENSE_CONTROL == LOW_LEVEL )
	{
		
	
	CLEAR_BIT(MCUCR , ISC00);
	
	CLEAR_BIT(MCUCR , ISC01);
	}
	else
	{
	    /*DO NOTHING */
	}
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidSetSignalch(u8 SenseCpy)
{
		
	if (SenseCpy == ON_CHANGE)
	{
		
	SET_BIT(MCUCR , ISC10);
	
	CLEAR_BIT(MCUCR , ISC11);
	
	}
	
	else if (SenseCpy == FALLING)
	{
		
	SET_BIT(MCUCR , ISC10);
	
	SET_BIT(MCUCR , ISC11);
	
	}
	
	else if ( EXTI0_SENSE_CONTROL == RISING )
	{
		
	CLEAR_BIT(MCUCR , ISC10);
	
	SET_BIT  (MCUCR , ISC11 );
	
	}
	
	else if ( EXTI0_SENSE_CONTROL == LOW_LEVEL )
	{
		
	
	CLEAR_BIT(MCUCR , ISC10);
	
	CLEAR_BIT(MCUCR , ISC11);
   }
	else
	{
	    /*DO NOTHING */
	}
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT2_voidSetSignalch(u8 SenseCpy)
{
		
	if (SenseCpy == FALLING)
	{
		
	CLEAR_BIT(MCUCSR , ISC2);
	
	}
	
	else if ( EXTI0_SENSE_CONTROL == RISING )
	{
		
	SET_BIT(MCUCSR , ISC2);
	
	}
	
	else
	{
	    /*DO NOTHING */
	}
}
/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*						    [For External Interrupt Zero ]								*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void (*CallBackFunc) (void) = (void*)0;
void EXTI0_VidReciever (void (*recieverfunc) (void))
{
	CallBackFunc = recieverfunc ;
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*						    [For External Interrupt One ]								*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void (*Call_BackFunc) (void) = (void*)0;
void EXTI1_VidReciever (void (*reciever_func) (void))
{
	Call_BackFunc = reciever_func ;
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*						    [For External Interrupt One ]								*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void (*Call_Back_Func) (void) = (void*)0;
void EXTI2_VidReciever (void (*recieve_func) (void))
{
	Call_Back_Func = recieve_func ;
}
/***************************************************************/
/*                 Interrupt Vector Table                     */
/*************************************************************/
void __vector_1(void) __attribute__(( signal , used ));
void __vector_1(void)
{
	CallBackFunc();
	
}


void __vector_2(void) __attribute__(( signal , used ));
void __vector_2(void)
{
	Call_BackFunc();
	
}


void __vector_3(void) __attribute__(( signal , used ));
void __vector_3(void)
{
	Call_Back_Func();
	
}



/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/