/*
 * Timer2.c
 *
 * Created: 28/02/2023 10:19:55 PM
 * Author : Abdelrahman
 */ 

#include "TIMER2_int.h"
#include "GIE_INT.h"
#include <util/delay.h>

void TASK ()
{
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,OUTPUT);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_HIGH);
	_delay_ms(500);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_LOW);
}

int main(void)
{
	TIMER2_void_SetOVCallBack (TASK);
	TIMER2_void_Init();
	TIMER2_void_EnableOVInt ();
	
	GIE_vidEnable();
    
    while (1) 
    {
    }
}

