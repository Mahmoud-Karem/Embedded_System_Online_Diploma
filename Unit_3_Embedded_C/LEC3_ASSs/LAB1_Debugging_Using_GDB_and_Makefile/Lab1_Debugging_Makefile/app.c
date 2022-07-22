#include "uart.h"

unsigned char string_buffer[100] = "Learn-In-Depth : <Karem>" ;
const unsigned char string_buffer_2[100] = "Learn-In-Depth : <Karem>" ;

void main (void)
{
	UART_Send_String (string_buffer);
}