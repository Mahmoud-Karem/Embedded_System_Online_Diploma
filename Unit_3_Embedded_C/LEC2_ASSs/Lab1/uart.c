#include "uart.h"

#define UART0_DR *((volatile unsigned int * const)((unsigned int *)0x101f1000))

void UART_Send_String (unsigned char *P_tx_string)
{
	while (*P_tx_string != '\0')
	{
		UART0_DR = (unsigned int)(*P_tx_string);
		P_tx_string++;
	}
	
	
}