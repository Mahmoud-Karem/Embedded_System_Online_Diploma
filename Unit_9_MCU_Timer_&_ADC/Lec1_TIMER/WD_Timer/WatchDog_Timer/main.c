/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: repair
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"

#include "LED_interface.h"
#include <util/delay.h>

LED_Type MY_LED = {LED_PORTA,LED_PIN0,ACTIVE_HIGH};

int main(void)
{
	LED_voidInit(MY_LED);
	TIMER_voidWDTSleep();
	TIMER_voidWDTEnable();

	while (1)
	{
		LED_voidToggle(MY_LED);
		_delay_ms(1000);
		/** Reset before 1 Second (Led off less than 1 sec) **/
	}
}
