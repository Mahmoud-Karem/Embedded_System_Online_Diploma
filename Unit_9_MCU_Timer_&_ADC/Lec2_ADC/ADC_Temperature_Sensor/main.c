/*
 * main.c
 *
 *  Created on: Oct 7, 2022
 *      Author: repair
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "CLCD_interface.h"
#include "LM35_interface.h"

LM35_CONFIG LM35 = {ADC_CHANNEL0,INTERNAL_2_56,ADC_RESOLUTION_10_BIT};
u8 Temp_Val =0 ;
int main ()
{
	DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	ADC_voidInit();
	CLCD_voidInit();
	CLCD_voidSendString((u8 *)"Temp=");

	while (1)
	{
		LM35_u8GetTemp( &LM35 , &Temp_Val);
		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_7);
		CLCD_voidSendNumber(Temp_Val);
		CLCD_voidSendString((u8 *)"  c");

	}

	return 0;
}
