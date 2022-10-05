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
	u8 ch=0;

	TWI_voidInitMaster(0b01010101);
	while (1)
	{
		_delay_ms(500);
		TWI_SendStartCondition();                        //Trasmit Start Condition
		TWI_SendSlaveAddressWithWrite(0b10101010);       //Transmit  SLA + W(0)
		TWI_MasterWriteDataByte(ch++);                   // Transmit Data
		TWI_SendStopCondition();                                      //Transmit Stop condition
	}
}
