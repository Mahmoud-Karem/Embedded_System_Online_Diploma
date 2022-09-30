/*
 * 
 * Author : Mahmoud Karem Zammel
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "CLCD_interface.h"

#include <util/delay.h>

u8 g_Rx_Buffer[7];


void Rx_Func ()
{
	CLCD_voidSendString((u8 *)"UART Rx --> Done");
	_delay_ms(2000);
	CLCD_voidClearScreen();
	CLCD_voidSendString((u8 *)"Rx Buffer = ");
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
	CLCD_voidSendString((u8 *)g_Rx_Buffer);

}

int main(void)
{

	/* Initializations  */
	CLCD_voidInit();
	USART_voidInit();
	GIE_VoidEnable();

	CLCD_voidSendString((u8 *)"USART RX");
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
	CLCD_voidSendString((u8 *)"--> with INT");
	_delay_ms(2000);
	CLCD_voidClearScreen();



	USART_u8ReceiveBufferAsynch(g_Rx_Buffer,sizeof(g_Rx_Buffer),Rx_Func);

	while (1)
	{

	}
}
