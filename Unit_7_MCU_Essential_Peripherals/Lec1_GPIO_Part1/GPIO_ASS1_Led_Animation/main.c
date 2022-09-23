/*
 * 3 leds with a specific delay
 *
 * Author : Mahmoud Karem Zammel
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"

#include <util/delay.h>

int main(void)
{
	/* Define All Configurations for  LEDs  */
	LED_Type LED1 = {LED_PORTA,LED_PIN0,ACTIVE_HIGH};
	LED_Type LED2 = {LED_PORTA,LED_PIN1,ACTIVE_HIGH};
	LED_Type LED3 = {LED_PORTA,LED_PIN2,ACTIVE_HIGH};
	LED_Type LED4 = {LED_PORTA,LED_PIN3,ACTIVE_HIGH};
	LED_Type LED5 = {LED_PORTA,LED_PIN4,ACTIVE_HIGH};
	LED_Type LED6 = {LED_PORTA,LED_PIN5,ACTIVE_HIGH};
	LED_Type LED7 = {LED_PORTA,LED_PIN6,ACTIVE_HIGH};
	LED_Type LED8 = {LED_PORTA,LED_PIN7,ACTIVE_HIGH};

	/* Define All Configurations for  Switch  */
	SW_Type SW1 = {DIO_PORTB,DIO_PIN0,SW_Int_PULL_UP};


	/* Initialization of leds  */
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidInit(LED3);
	LED_voidInit(LED4);
	LED_voidInit(LED5);
	LED_voidInit(LED6);
	LED_voidInit(LED7);
	LED_voidInit(LED8);

	/* Initialization of SW  */
	SW_voidInit(SW1);


	s8 Counter = 0 ;
	u8 sw_p = 0;
	while (1)
	{
		sw_p = SW_u8GetPressed(SW1);
		if(SW_PRESSED == sw_p)
		{
			Counter ++ ;
			switch(Counter)
			{
			case 1:
				LED_voidOn(LED1);
				_delay_ms(50);
				break;


			case 2:
				LED_voidOn(LED2);
				_delay_ms(50);
				break;

			case 3:
				LED_voidOn(LED3);
				_delay_ms(50);
				break;

			case 4:
				LED_voidOn(LED4);
				_delay_ms(50);
				break;

			case 5:
				LED_voidOn(LED5);
				_delay_ms(50);
				break;

			case 6:
				LED_voidOn(LED6);
				_delay_ms(50);
				break;

			case 7:
				LED_voidOn(LED7);
				_delay_ms(50);
				break;

			case 8:
				LED_voidOn(LED8);
				_delay_ms(50);
				break;

			case 9:
				LED_voidOff(LED1);
				LED_voidOff(LED2);
				LED_voidOff(LED3);
				LED_voidOff(LED4);
				LED_voidOff(LED5);
				LED_voidOff(LED6);
				LED_voidOff(LED7);
				LED_voidOff(LED8);
				_delay_ms(50);
				Counter = 0 ;
				break;

			}

		}
	}
}
