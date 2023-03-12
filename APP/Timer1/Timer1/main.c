/*
 * Timer1.c
 *
 * Created: 01/03/2023 07:21:57 PM
 * Author : Abdelrahman
 */ 

#include "TIMER1_int.h"
#include "GIE_INT.h"
#include <util/delay.h>
void task ()
{
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN1,OUTPUT);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_HIGH);
	_delay_ms(10000);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_LOW);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN1,STD_HIGH);
	_delay_ms(10000);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN1,STD_LOW);
}

int main(void)
{
	TIMER1_void_SetOVCallBack (task);
    GIE_vidEnable();
	TIMER1_void_Init();
	TIMER1_void_SetTimerReg (65000);
	TIMER1_void_EnableOVInt();
	
    while (1) 
    {
    }
}

