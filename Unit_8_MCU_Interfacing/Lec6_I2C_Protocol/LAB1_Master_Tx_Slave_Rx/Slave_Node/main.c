/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Mahmoud Karem Zamel
 */
#include <avr/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "TWI_interface.h"


int main(void)
{
	u8 Data_Rx;
	DIO_enumSetPortDirection(DIO_PORTA,DIO_PORT_OUTPUT);

	TWI_voidInitSlave(0b10101010);
	while (1)
	{
		TWI_SlaveReadDataByte(& Data_Rx);
		DIO_enumSetPortValue(DIO_PORTA,Data_Rx);
	}
}
