/*
 * main.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#include "CA.h"

void setup ()
{
	//init all the drivers ...
	//init IRQ ...
	//init HAL (US_Driver , DC_Motor_Driver)
	//init Block

	//Set states pointers for each block
	pCA_state = STATE(CA_waiting);

}

void main ()
{
	volatile int Delay ;

	setup();
	while (1)
	{
		//call sate for each block
		pCA_state();
		for (Delay=0 ; Delay<=1000 ; Delay++);

	}
}
