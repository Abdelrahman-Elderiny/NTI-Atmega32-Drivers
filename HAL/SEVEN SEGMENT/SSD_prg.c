/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    25 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   prog.c for UART                     */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include <util/delay.h>
#include "STD_TYPES.h"		//Library
#include "BIT_MATH.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "DIO_int.h"	
#include "SSD_int.h"

/****************************************************************/
/* Description    : This function used for Display numbers     	*/
/*																*/
/*					Inputs : copy_Number			  			*/
/*					Return : void		 					    */
/****************************************************************/

void H_SSD_void_displayIntNumber(u16 copy_Number)
{
	u8 arr[4]={0};

	u8 i=0,j=0;

	while(copy_Number > 0 && i<4)
	{
		arr[i++]= copy_Number%10;
		copy_Number /= 10;
	}

	for(j=0;j<SSD_DISPLAY_TIME;j++)
	{
		//Prepare Unit to be send to BCD (4 bits)
		i=0;
		M_Dio_void_setPinValue(SSD_A_PIN,GET_BIT(arr[i],0));
		M_Dio_void_setPinValue(SSD_B_PIN,GET_BIT(arr[i],1));
		M_Dio_void_setPinValue(SSD_C_PIN,GET_BIT(arr[i],2));
		M_Dio_void_setPinValue(SSD_D_PIN,GET_BIT(arr[i],3));

		// Enable Digit One (first SSD)(remember it is pnp)(Active LOW)
		M_Dio_void_setPinValue(SSD_DIG1_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG1_EN,DIO_HIGH);

		//Prepare tens to be send to BCD (4 bits)
		i=1;
		M_Dio_void_setPinValue(SSD_A_PIN,GET_BIT(arr[i],0));
		M_Dio_void_setPinValue(SSD_B_PIN,GET_BIT(arr[i],1));
		M_Dio_void_setPinValue(SSD_C_PIN,GET_BIT(arr[i],2));
		M_Dio_void_setPinValue(SSD_D_PIN,GET_BIT(arr[i],3));

		// Enable Digit Two (first SSD)(remember it is pnp)(Active LOW)
		M_Dio_void_setPinValue(SSD_DIG2_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG2_EN,DIO_HIGH);

		//Prepare hund to be send to BCD (4 bits)
		i=2;
		M_Dio_void_setPinValue(SSD_A_PIN,GET_BIT(arr[i],0));
		M_Dio_void_setPinValue(SSD_B_PIN,GET_BIT(arr[i],1));
		M_Dio_void_setPinValue(SSD_C_PIN,GET_BIT(arr[i],2));
		M_Dio_void_setPinValue(SSD_D_PIN,GET_BIT(arr[i],3));

		// Enable Digit Three (first SSD)(remember it is pnp)(Active LOW)
		M_Dio_void_setPinValue(SSD_DIG3_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG3_EN,DIO_HIGH);

		//Prepare Thous to be send to BCD (4 bits)
		i=3;
		M_Dio_void_setPinValue(SSD_A_PIN,GET_BIT(arr[i],0));
		M_Dio_void_setPinValue(SSD_B_PIN,GET_BIT(arr[i],1));
		M_Dio_void_setPinValue(SSD_C_PIN,GET_BIT(arr[i],2));
		M_Dio_void_setPinValue(SSD_D_PIN,GET_BIT(arr[i],3));

		// Enable Digit Two (first SSD)(remember it is pnp)(Active LOW)
		M_Dio_void_setPinValue(SSD_DIG4_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG4_EN,DIO_HIGH);

	}

}
