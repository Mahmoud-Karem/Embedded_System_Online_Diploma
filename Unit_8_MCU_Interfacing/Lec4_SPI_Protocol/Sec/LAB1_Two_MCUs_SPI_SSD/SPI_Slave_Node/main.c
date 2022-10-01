/*
 * main.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mahmoud Karem Zamel
 */


#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_SlaveInit(void)
{
	/* Set MISO output */
	SET_BIT(DDRB,MISO);

	/* Set MOSI, SCK and SS input */
	CLR_BIT(DDRB,MOSI);
	CLR_BIT(DDRB,SCK);
	CLR_BIT(DDRB,SS);


	/* Enable SPI */
	SET_BIT(SPCR,SPE);
}

u8 SPI_SlaveRecieve(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));

	/* Return Data Register */
	return SPDR;
}

int main(void)
{
	DDRA = 0xFF;
	SPI_SlaveInit();
	while(1)
	{
		PORTA = SPI_SlaveRecieve();
	}
	return 0;
}
