/*
 * main.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#include "CA.h"
#include "DC.h"
#include "US.h"

void setup ()
{
	//init all the drivers ...
	//init IRQ ...
	//init HAL (US_Driver , DC_Motor_Driver)
	//init Block
	US_Init();
	DC_Init();
	//Set states pointers for each block (init States for each one)
	pCA_state = STATE(CA_waiting);
	pUS_state = STATE(US_busy);
	pDC_state = STATE(DC_idle);

}

void main ()
{
	volatile int Delay ;

	setup();
	while (1)
	{
		//call sate for each block
		pUS_state();
		pCA_state();
		pDC_state();
		for (Delay=0 ; Delay<=1000 ; Delay++);

	}
}
