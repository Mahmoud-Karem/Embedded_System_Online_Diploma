/*
 * 3 leds with a specific delay
 *
 * Author : Mahmoud Karem Zammel
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"

#include <util/delay.h>

int main(void)
{

	/* Initialization of LCD & KPD  */
	CLCD_voidInit();
	KPD_Init();

	u8 pressed_key;

	while (1)
	{
		pressed_key = KPD_u8GetPressed();
		switch(pressed_key)
		{
		case '?':
			CLCD_voidClearScreen();
			break;
		case 255:
			break;
		default:
			CLCD_voidSendData(pressed_key);
			break;
		}
	}
}
