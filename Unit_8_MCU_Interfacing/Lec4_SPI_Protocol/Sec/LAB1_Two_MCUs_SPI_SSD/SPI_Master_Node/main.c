/*

 * main.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mahmoud Karem Zamel
 */


#include <avr/io.h>
#include "util/delay.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_MasterInit(void)
{
	/* Set MOSI, SCK and SS output, all others input */
	SET_BIT(DDRB,MOSI);
	SET_BIT(DDRB,SCK);
	SET_BIT(DDRB,SS);
	/* Set MISO input */
	CLR_BIT(DDRB,MISO);

	/* Enable SPI, Master, set clock rate fck/16 */
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPE);

}

u8 SPI_MasterTransmit(u8 data)
{
	/* Start transmission, Write data to SPI data register */
	SPDR = data;

	/* Waiting for transmission complete */
	while(!(SPSR & (1<<SPIF)));

	/* Return the transmitted data */
	return data;
}

int main(void)
{
	DDRA = 0xFF;

	u8 ch = 0;

	SPI_MasterInit();

	for (ch = 0; ch <=255; ch++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterTransmit(ch);
	}

	return 0;
}



