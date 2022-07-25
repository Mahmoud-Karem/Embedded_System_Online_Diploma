#include "Platform_Types.h"
#include "uart.h"

uint8_t string_buffer[100] = "Learn-In-Depth : <Karem>" ;
//const unsigned char string_buffer_2[100] = "Karem" ;

void main (void)
{
	UART_Send_String (string_buffer);
}