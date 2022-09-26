/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */

/*************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

/****************************************************************/

void My_Wait(int x)
{
	unsigned int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);

}

int main(void)
{
	/* RCC Init  */
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOA_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOB_RCC);

	/* GPIO Init  */
	MDIO_voidSetPinDirection(DIOA, PIN1, INPUT_FLOATING);
	MDIO_voidSetPinDirection(DIOA, PIN13, INPUT_FLOATING);
	MDIO_voidSetPinDirection(DIOB, PIN1, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, PIN13, OUTPUT_SPEED_2MHZ_PP);

	while(1)
	{
		//PA1 --> Connected external PUR
		if(MDIO_u8GetPinValue(DIOA, PIN1)==0) //press
		{
			MDIO_voidSetPinValue(DIOB, PIN1, !(MDIO_u8GetPinValue(DIOB, PIN1)));
			while(MDIO_u8GetPinValue(DIOA, PIN1)==0); //for single press

		}

		//PA13 --> Connected external PDR
		if(MDIO_u8GetPinValue(DIOA, PIN13)==1) //Multi press
		{
			MDIO_voidSetPinValue(DIOB, PIN13, !(MDIO_u8GetPinValue(DIOB, PIN13)));
		}

		My_Wait(1);

	}

	return 0;
}
