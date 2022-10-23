/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: repair
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"


#include "LED_interface.h"

LED_Type MY_LED1 = {LED_PORTA,LED_PIN0,ACTIVE_HIGH};
LED_Type MY_LED2 = {LED_PORTA,LED_PIN1,ACTIVE_HIGH};

u8 Copy_u8PL = 192 ;
u8 Copy_u8CM = 125 ;
volatile u32 SW_Counter1 =0;
volatile u32 SW_Counter2 =0;

void B_TOG()
{
	SW_Counter1++ ;
	if (SW_Counter1==4883)
	{
		TIMER0_voidSetPreload(Copy_u8PL);
		LED_voidToggle(MY_LED1);
		SW_Counter1=0;
	}
}

void G_TOG()
{
	SW_Counter2++ ;
	if (SW_Counter2==1000)
	{
		TIMER2_voidSetCTC(Copy_u8CM);
		LED_voidToggle(MY_LED2);
		SW_Counter2=0;
	}
}

int main(void)
{
	LED_voidInit(MY_LED1);
	LED_voidInit(MY_LED2);
	TIMER0_voidInit();
	TIMER2_voidInit();
	TIMER_u8SetCallBack(B_TOG,TIMER0_OVF_VECTOR_ID);
	TIMER_u8SetCallBack(G_TOG,TIMER2_CTC_VECTOR_ID);
	GIE_VoidEnable();


	while (1)
	{

	}
}
