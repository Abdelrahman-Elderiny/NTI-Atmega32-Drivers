/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   prog.c for Timer 2                  */ 
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "TIMER2_int.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : This function used for TIMER2 INIT         	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_Init(void)
{
	/********************************/
	/*       Mode Selection        */
	/******************************/
	
	#if(TIMER2_MODE == TIMER2_NORMAL)
	
		CLEAR_BIT(TCCR2 , WGM20);
		CLEAR_BIT(TCCR2 , WGM21);
			
	#elif(TIMER2_MODE == TIMER2_CTC)
	
		CLEAR_BIT (TCCR2 , WGM20);
		SET_BIT   (TCCR2 , WGM21);
		
	#elif(TIMER2_MODE == TIMER2_FAST_PWM )
	
		SET_BIT(TCCR2 , WGM20);
		SET_BIT(TCCR2 , WGM21);
		
	#elif(TIMER2_MODE == TIMER2_PHASE_PWM )
	
		SET_BIT  (TCCR2 , WGM20);
		CLEAR_BIT(TCCR2 , WGM21);
		
	#endif
	
	/*************************************/
	/*       Prescaler Selection        */
	/***********************************/
	
	#if(TIMER2_PRESCALER == TIMER2_DIV_BY_1)
	
		SET_BIT   (TCCR2 , CS20);
		CLEAR_BIT (TCCR2 , CS21);
		CLEAR_BIT (TCCR2 , CS22);
	
	#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_8)
	
		CLEAR_BIT (TCCR2 , CS20);
		SET_BIT   (TCCR2 , CS21);
		CLEAR_BIT (TCCR2 , CS22);
		
	#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_64 )
	
		SET_BIT   (TCCR2 , CS20);
		SET_BIT   (TCCR2 , CS21);
		CLEAR_BIT (TCCR2 , CS22);
		
	#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_256 )
	
		CLEAR_BIT (TCCR2 , CS20);
		CLEAR_BIT (TCCR2 , CS21);
		SET_BIT   (TCCR2 , CS22);
		
	#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_1024 )
	
		SET_BIT   (TCCR2 , CS20);
		CLEAR_BIT (TCCR2 , CS21);
		SET_BIT   (TCCR2 , CS22);	
		
	#endif
	
/*************************************************/
/*           Select  Compare Match              */
/*                 Output Mode                 */
/**********************************************/
	
	#if(TIMER2_COM_EVENT == TIMER2_NO_ACTION)
		CLEAR_BIT(TCCR2 , COM20);
		CLEAR_BIT(TCCR2 , COM21);	
	#elif(TIMER2_COM_EVENT == TIMER2_TOGGLE)
		SET_BIT   (TCCR2 , COM20)
		CLEAR_BIT (TCCR2 , COM21);
	#elif(TIMER2_COM_EVENT == TIMER2_CLEAR )
		CLEAR_BIT (TCCR2 , COM20);
		SET_BIT   (TCCR2 , COM21);
	#elif(TIMER2_COM_EVENT == TIMER2_SET )
		SET_BIT(TCCR2 , COM20);
		SET_BIT(TCCR2 , COM21);
	#endif
	
	/*************************************/
	/*       Disable Interrupt          */
	/***********************************/	
	
	CLEAR_BIT(TIMSK , TOIE2);	
	CLEAR_BIT(TIMSK , OCIE2);
	
	/*************************************/
	/*          Clear Flags             */
	/***********************************/
	
	SET_BIT(TIFR , TOV2);	
	SET_BIT(TIFR , OCF2);
	
	/*************************************/
	/*       Clear TCNT2 & OCR2 REG     */
	/***********************************/
	
	TCNT2 = 0 ;
	OCR2 = 0 ;
}

/****************************************************************/
/* Description    : This function used for Pre-loading         	*/
/*                        in TCNT2                              */
/*																*/
/*					Inputs : Copy_uint8Val						*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT2 = Copy_uint8Val ;
}

/****************************************************************/
/* Description    : This function used for entering         	*/
/*                     the value in OCR2 REG.                   */
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR2 = Copy_uint8Val ;
}

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , TOIE2);
}

/****************************************************************/
/* Description    : This function used for disable the        	*/
/*                        the overflow mode                     */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , TOIE2);
}

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , OCIE2);
}

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER2_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , OCIE2);
}

/********************************************************************/
/*               CALL BACK FUNC & VECTOR TABLE ID                  */
/******************************************************************/


/******************* OVERFLOW MODE ************************/

void (*TIMER2_OV_CB) (void)= (void*)0; 

void TIMER2_vidSetOVCallBack ( void (*Copy_ptr) (void) ) 
{
	TIMER2_OV_CB = Copy_ptr ;
}

void __vector_5(void) __attribute__((signal , used));
void __vector_5(void)
{
	
	TIMER2_OV_CB();
}


/*********************** CTC MODE ************************/

void (*TIMER2_CTC_CallBack) (void)= (void*)0; ;

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER2_CTC_CallBack = Copy_ptr ;
	
}
void __vector_4(void) __attribute__((signal , used));
void __vector_4(void)
{
	
	TIMER2_CTC_CallBack();
}
