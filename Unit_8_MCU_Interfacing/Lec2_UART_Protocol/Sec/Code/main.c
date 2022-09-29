/*
 * 
 * Author : Mahmoud Karem Zammel
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "USART_interface.h"
#include "CLCD_interface.h"

#include <util/delay.h>

u8 g_Data = 0;

int main(void)
{

	/* Initialization of LCD & KPD  */
	CLCD_voidInit();
	USART_voidInit();

	USART_u8SendStringSynch((u8 *)"Mahmoud Karem");
	CLCD_voidSendString((u8 *)"LCD --> Ready");
	_delay_ms(1000);
	CLCD_voidClearScreen();


	while (1)
	{
		USART_u8RecevieData(&g_Data);
		if (g_Data != 0)
		{
			CLCD_voidSendData(g_Data);
			g_Data=0;
		}
	}
}
