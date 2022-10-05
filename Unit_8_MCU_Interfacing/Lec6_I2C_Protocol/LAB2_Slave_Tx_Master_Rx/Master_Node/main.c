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
	u8 ch;
	DIO_enumSetPortDirection(DIO_PORTA,DIO_PORT_OUTPUT);
	TWI_voidInitMaster(0b01010101);
	while (1)
	{
		TWI_SendStartCondition();                        //Trasmit Start Condition
		TWI_SendSlaveAddressWithRead(0b10101010);        //Transmit  SLA + R(1)
		TWI_MasterReadDataByte((u8 *) &ch);                     // Recieve Data
		TWI_SendStopCondition();                         //Transmit Stop condition
		DIO_enumSetPortValue(DIO_PORTA,ch);
		_delay_ms(500);

	}
}
