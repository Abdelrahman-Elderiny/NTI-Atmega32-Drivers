/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   prog.c for Timer 1                  */
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "TIMER1_int.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : This function used for TIMER1 INIT         	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_Init(void)
{
/********************************/
/*       Mode Selection        */
/******************************/

#if(TIMER1_MODE == NORMAL)

CLEAR_BIT (TCCR1A,WGM10);
CLEAR_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == PWM_PHASE_CORRECT_8)

SET_BIT (TCCR1A,WGM10);
CLEAR_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == PWM_PHASE_CORRECT_9 )

CLEAR_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == PWM_PHASE_CORRECT_10 )

SET_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == CTC_OCRA1A )

CLEAR_BIT (TCCR1A,WGM10);
CLEAR_BIT (TCCR1A,WGM11);

SET_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == FASTPWM_8 )

SET_BIT (TCCR1A,WGM10);
CLEAR_BIT (TCCR1A,WGM11);

SET_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == FASTPWM_9 )

CLEAR_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

SET_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == FASTPWM_10 )

SET_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

SET_BIT (TCCR1B,WGM12);
CLEAR_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == PWM_FRE_ICR )

CLEAR_BIT (TCCR1A,WGM10);
CLEAR_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == PWM_FRE_OCR )

SET_BIT (TCCR1A,WGM10);
CLEAR_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == PWM_PHASE_CORR_ICR )

CLEAR_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == PWM_PHASE_CORR_OCR )

SET_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

CLEAR_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == CTC_ICR )

CLEAR_BIT (TCCR1A,WGM10);
CLEAR_BIT (TCCR1A,WGM11);

SET_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == FAST_PWM_ICR1 )

CLEAR_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

SET_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);

#elif(TIMER1_MODE == FAST_PWM_OCR1A )

SET_BIT (TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);

SET_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);

#endif
/********************************************************/	

#if (TIMER1_A == ENABLE)

/*************************************************/
/*           Select  Compare Match              */
/*                 Output Mode                 */
/**********************************************/

#if (TIMER1_COM_EVENT == TIMER1_NO_ACTION)
CLEAR_BIT(TCCR1A , COM1A0);
CLEAR_BIT(TCCR1A , COM1A1);
#elif(TIMER2_COM_EVENT == TIMER1_TOGGLE)
SET_BIT   (TCCR1A , COM1A0)
CLEAR_BIT (TCCR1A , COM1A1);
#elif(TIMER2_COM_EVENT == TIMER1_CLEAR )
CLEAR_BIT (TCCR1A , COM1A0);
SET_BIT   (TCCR1A , COM1A1);
#elif(TIMER2_COM_EVENT == TIMER1_SET )
SET_BIT(TCCR1A , COM1A0);
SET_BIT(TCCR1A , COM1A1);
#endif

#endif
/********************************************************/

#if (TIMER1_B == ENABLE)

/*************************************************/
/*           Select  Compare Match              */
/*                 Output Mode                 */
/**********************************************/

#if (TIMER1_COM_EVENT == TIMER1_NO_ACTION)
CLEAR_BIT(TCCR1A , COM1B0);
CLEAR_BIT(TCCR1A , COM1B1);
#elif(TIMER2_COM_EVENT == TIMER1_TOGGLE)
SET_BIT   (TCCR1A , COM1B0)
CLEAR_BIT (TCCR1A , COM1B1);
#elif(TIMER2_COM_EVENT == TIMER1_CLEAR )
CLEAR_BIT (TCCR1A , COM1B0);
SET_BIT   (TCCR1A , COM1B1);
#elif(TIMER2_COM_EVENT == TIMER1_SET )
SET_BIT(TCCR1A , COM1B0);
SET_BIT(TCCR1A , COM1B1);
#endif

#endif
/********************************************************/

#if (TIMER1_A == ENABLE && TIMER1_B == ENABLE)

/*************************************************/
/*           Select  Compare Match              */
/*                 Output Mode                 */
/**********************************************/

#if (TIMER1_COM_EVENT == TIMER1_NO_ACTION)
CLEAR_BIT(TCCR1A , COM1A0);
CLEAR_BIT(TCCR1A , COM1A1);
CLEAR_BIT(TCCR1A , COM1B0);
CLEAR_BIT(TCCR1A , COM1B1);
#elif(TIMER2_COM_EVENT == TIMER1_TOGGLE)
SET_BIT   (TCCR1A , COM1A0)
CLEAR_BIT (TCCR1A , COM1A1);
SET_BIT   (TCCR1A , COM1B0)
CLEAR_BIT (TCCR1A , COM1B1);
#elif(TIMER2_COM_EVENT == TIMER1_CLEAR )
CLEAR_BIT (TCCR1A , COM1A0);
SET_BIT   (TCCR1A , COM1A1);
CLEAR_BIT (TCCR1A , COM1B0);
SET_BIT   (TCCR1A , COM1B1);
#elif(TIMER2_COM_EVENT == TIMER1_SET )
SET_BIT(TCCR1A , COM1A0);
SET_BIT(TCCR1A , COM1A1);
SET_BIT(TCCR1A , COM1B0);
SET_BIT(TCCR1A , COM1B1);
#endif

#endif
/********************************************************/

/*************************************/
/*       Prescaler Selection        */
/***********************************/
#if(TIMER1_PRESCALER == TIMER1_DIV_BY_1)

SET_BIT   (TCCR1B , CS10);
CLEAR_BIT (TCCR1B , CS11);
CLEAR_BIT (TCCR1B , CS12);

#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_8)

CLEAR_BIT (TCCR1B , CS10);
SET_BIT   (TCCR1B , CS11);
CLEAR_BIT (TCCR1B , CS12);

#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_64 )

SET_BIT   (TCCR1B , CS10);
SET_BIT   (TCCR1B , CS11);
CLEAR_BIT (TCCR1B , CS12);

#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_256 )

CLEAR_BIT (TCCR1B , CS10);
CLEAR_BIT (TCCR1B , CS11);
SET_BIT   (TCCR1B , CS12);

#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_1024 )

SET_BIT   (TCCR1B , CS10);
CLEAR_BIT (TCCR1B , CS11);
SET_BIT   (TCCR1B , CS12);

#endif
	
/*************************************/
/*       Disable Interrupt          */
/***********************************/

CLEAR_BIT(TIMSK , TICIE1);
CLEAR_BIT(TIMSK , OCIE1A);
CLEAR_BIT(TIMSK , OCIE1B);
CLEAR_BIT(TIMSK , TOIE1);

/*************************************/
/*          Clear Flags             */
/***********************************/

SET_BIT(TIFR , ICF1);
SET_BIT(TIFR , OCF1A);
SET_BIT(TIFR , OCF1B);
SET_BIT(TIFR , TOV1);

/*******************************************/
/*       Clear TCNT1 & OCR1 & ICR1 REG     */
/*******************************************/

TCNT1 = 0 ;
OCR1A = 0 ;
OCR1B = 0 ;
ICR1  = 0 ;
}


/****************************************************************/
/* Description    : This function used for Pre-loading         	*/
/*                        in TCNT1                              */
/*																*/
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT1 = Copy_uint8Val ;
}

/****************************************************************/
/* Description    : This function used for entering         	*/
/*                  the value in OCR1A & OCR1B REG.             */
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetCompareVal(u8 Copy_uint8Val)
{
	#if (OCR_REG == OCR1A_REG)
	OCR1A = Copy_uint8Val ;
	#elif (OCR_REG == OCR1B_REG)
	OCR1B = Copy_uint8Val ;
	#endif
}

/****************************************************************/
/* Description    : This function used for entering         	*/
/*                  the value in ICR REG.                       */
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_SetInput_Capture_Register_Val(u8 Copy_uint8Val)
{
	ICR1 = Copy_uint8Val ;
}

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_EnableOVInt(void)
{
	SET_BIT (TIMSK , TOIE1 );
}

/****************************************************************/
/* Description    : This function used for disable interrupt   	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_DisableOVInt(void)
{
	CLEAR_BIT (TIMSK , TOIE1 );
}

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_EnableCTCInt(void)
{
   #if (OCR_REG == OCR1A_REG)
   SET_BIT (TIMSK,OCR1A);
   #elif (OCR_REG == OCR1B_REG)
   SET_BIT (TIMSK,OCR1B);
   #endif
}

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_DisableCTCInt(void)
{
	#if (OCR_REG == OCR1A_REG)
	CLEAR_BIT (TIMSK,OCR1A);
	#elif (OCR_REG == OCR1B_REG)
	CLEAR_BIT (TIMSK,OCR1B);
	#endif
}

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the ICU mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_EnableICUInt(void)
{
	SET_BIT (TIMSK , TICIE1 );
}

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the ICU mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER1_void_DisableICUInt(void)
{
	CLEAR_BIT ( TIMSK , TICIE1 );
}

/********************************************************************/
/*               CALL BACK FUNC & VECTOR TABLE ID                  */
/******************************************************************/


/******************* OVERFLOW MODE ************************/

void (*TIMER1_OV_CallBack) (void) ;

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER1_OV_CallBack = Copy_ptr ;
}

void __vector_9(void) __attribute__((signal , used));
void __vector_9(void)
{
	
	TIMER1_OV_CallBack();
}


/*********************** CTCA MODE ************************/

void (*TIMER1_CTCA_CallBack) (void) ;

void TIMER1_void_SetCTCACallBack(void (*Copy_ptr) (void) )
{
	TIMER1_CTCA_CallBack = Copy_ptr ;
	
}
void __vector_7(void) __attribute__((signal , used));
void __vector_7(void)
{
	
	TIMER1_CTCA_CallBack();
}

/*********************** CTCB MODE ************************/

void (*TIMER1_CTCB_CallBack) (void) ;

void TIMER1_void_SetCTCBCallBack(void (*Copy_ptr) (void) )
{
	TIMER1_CTCB_CallBack = Copy_ptr ;
	
}
void __vector_8(void) __attribute__((signal , used));
void __vector_8(void)
{
	
	TIMER1_CTCB_CallBack();
}

/******************* ICU MODE ************************/

void (*TIMER1_ICU_CallBack) (void) ;

void TIMER1_void_SetICUCallBack(void (*Copy_ptr) (void) )
{
	TIMER1_ICU_CallBack = Copy_ptr ;
}

void __vector_6(void) __attribute__((signal , used));
void __vector_6(void)
{
	
	TIMER1_ICU_CallBack();
}
