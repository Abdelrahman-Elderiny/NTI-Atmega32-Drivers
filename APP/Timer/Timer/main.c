/*
 * Timer.c
 *
 * Created: 26/02/2023 11:30:36 AM
 * Author : Abdelrahman
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include "GIE_INT.h"
#include "TIMR0_int.h"
#include "led.h"
#include "dio.h"
u8 x =0 ;
void TASK_1 ()
{
	x++ ;
	if (x == 3 )
	{
		led_toggle (LED_GREEN);
		x =0 ;
	}
	
}


int main(void)
{
	/*TIMER0_void_SetCTCCallBack (TASK_1);
	GIE_vidEnable();*/
    TIMER0_void_Init ();
	//u8 x = 0 ;
	 dio_vidConfigChannel(DIO_PORTB,DIO_PIN3,OUTPUT);
  /*	TIMER0_void_EnableCTCInt ();*/
	
    while (1) 
    {
		for ( u8 i =0 ; i<255 ; i++ )
		{
			TIMER0_void_SetCompareVal (i );
			_delay_ms(20);
		}
		
    }
}

