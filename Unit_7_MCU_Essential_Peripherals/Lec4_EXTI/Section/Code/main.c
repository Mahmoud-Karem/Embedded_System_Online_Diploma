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

#include <util/delay.h>

int main(void)
{

	/* Initialization of LCD & KPD  */
	CLCD_voidInit();

	CLCD_voidSendString((u8 *)"Learn in Depth");

	while (1)
	{

	}
}
