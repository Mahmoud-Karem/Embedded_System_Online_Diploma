/*
 * Main_ALgorithm.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */
#include "GPIO.h"

/***********************************************************************/
void GPIO_Init (void)
{
	SET_BIT(APB2ENR, 2);

	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}

/***********************************************************************/
void GPIO_delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

/***********************************************************************/
uint32_t GPIO_Get_Pressure_Val(void)
{
	return (GPIOA_IDR & 0xFF);
}

/***********************************************************************/
void GPIO_Start_Alarm_Actuator()
{
	SET_BIT(GPIOA_ODR,13);
	GPIO_delay(1000);
}

void GPIO_Stop_Alarm_Actuator()
{	
	CLR_BIT(GPIOA_ODR,13);
}

/***********************************************************************/
