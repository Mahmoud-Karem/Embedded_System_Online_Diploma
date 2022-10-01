/*

 * main.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mahmoud Karem Zamel
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define SCK 7


void SPI_MasterInit()
{
	/* Set MOSI, SCK and SS Direction --> O/P */
	SET_BIT(DDRB,MOSI);
	SET_BIT(DDRB,SS);
	SET_BIT(DDRB,SCK);

	/* Enable SPI, Master, set clock rate fck/16 */
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPE);

}

void execute(unsigned char cmd, unsigned char data)
{
	CLR_BIT(PORTB,SS);
	SPDR = cmd;
	while (!(SPSR & (1 << SPIF)));
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
	SET_BIT(PORTB,SS);

}

int main(void)
{
	/* Replace with your application code */
	unsigned char counter = 0;
	unsigned char index_display;
	SPI_MasterInit();
	execute(0x09, 0xFF);
	execute(0x0A, 0xFF);
	execute(0x0B, 0xF7);
	execute(0x0C, 0x01);
	while (1)
	{
		for (index_display = 1; index_display < 9; index_display++)
			execute(index_display, counter++);
		_delay_ms(1000);
	}
	return 0;
}
