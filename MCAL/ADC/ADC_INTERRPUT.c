#define F_CPU 8000000
#include "ADC_INT.h"
#include "GIE_INT.h"
#include "led.h"

#include <util/delay.h>
void task_1 ()
{
	led_toggle(LED_GREEN);
}
int main(void)
{
	ADC_VidSetCallBack(task_1);
    /* General Interrupt Enable */
	GIE_vidEnable();
	/* ADC Enable */
	ADC_voidInit();
	ADC_voidEnable();
	ADC_voidInterrputEnable();
	
	/* switch Enable */
	button_vidInit();
	/* LED Enable */
	led_init();
	
    while (1) 
    {
		ADC_voidStartConversion();
		_delay_ms(10);
		 
    }
}