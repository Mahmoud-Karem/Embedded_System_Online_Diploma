#include "Platform_Types.h"
#include "uart.h"

#define UART0_DR *((vuint32_t* const)((uint32*)0x101f1000))

void UART_Send_String (uint8* P_tx_string)
{
	while (*P_tx_string != '\0')
	{
		UART0_DR = (uint32_t)(*P_tx_string);
		P_tx_string++;
	}
	
	
}