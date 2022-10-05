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
	u8 Data_Tx= 0 ;

	TWI_voidInitSlave(0b10101010);
	while (1)
	{
		TWI_SlaveWriteDataByte(Data_Tx ++);
	}
}
