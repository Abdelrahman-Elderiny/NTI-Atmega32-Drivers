/*
 * EEPROM.c
 *
 * Created: 11/03/2023 10:35:45 AM
 * Author : Abdelrahman
 */ 

#include "EEPROM_INT.h"


int main(void)
{
    EEPROM_vidWrite(0X1010,10);
	u8 x = EEPROM_Read (0X1010);
    while (1) 
    {
		if (x == 10)
		{
			dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,OUTPUT);
			dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_HIGH);
		}
    }
}

