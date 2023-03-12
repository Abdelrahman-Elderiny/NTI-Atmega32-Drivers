/*
 * switches_led.c
 *
 * Created: 12/03/2023 11:31:11 AM
 * Author : Abdelrahman
 */ 

#include "LED_int.h"
#include "SWITCHES_INT.h"


int main(void)
{
    led_init();
	switch_vidInit();
	u8 x = 0 ;
	
	
    while (1) 
    {
		x = switch_GetStatus(PB_1);
		if (x == PRESSED)
		{
			led_toggle(LED_RED);
		}
    }
}

