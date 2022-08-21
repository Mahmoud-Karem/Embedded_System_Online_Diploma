/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Mahmoud Karem Zamel
 */

/*******************************************************************************/
/*******************************************************************************/

#include <util/delay.h>
#include "Platform_Types.h"
#include "BIT_MATH.h"


/*******************************************************************************/
/*******************************************************************************/

/* Macros */
#define EXTI_LINE0   6
#define EXTI_LINE1   7
#define EXTI_LINE2   5


/* Registers Definitions */

#define MCUCR_REG   *((vuint8_t *)0x55)
#define MCUCSR_REG  *((vuint8_t *)0x54)
#define GICR_REG    *((vuint8_t *)0x5B)
#define GIFR_REG    *((vuint8_t *)0x5A)

#define SREG			*((volatile uint8*) 0X5F)	/* Status Register */
#define SREG_I			7							/* Global Interrupt Enable Bit */

/* Group D Registers */
#define PORTD_Register  *((volatile uint8*)0x32)
#define DDRD_Register   *((volatile uint8*)0x31)
#define PIND_Register   *((volatile uint8*)0x30)

/*******************************************************************************/
/*******************************************************************************/
void GPIOD_init ()
{
	/* Pins Direction */

	// Input Pins
	CLR_BIT(DDRD_Register,2);
	CLR_BIT(DDRD_Register,3);

	// Output
	SET_BIT(DDRD_Register,5);
	SET_BIT(DDRD_Register,6);
	SET_BIT(DDRD_Register,7);

}

uint8 GPIOD_GetPinVal ( uint8 Copy_uint8PIN)
{
	return GET_BIT(PORTD_Register,Copy_uint8PIN);
}

void GPIOD_SetPinVal ( uint8 Copy_uint8PIN , uint8 Copy_uint8Value)
{
	if (Copy_uint8Value == 1)
	{
		SET_BIT(PORTD_Register,Copy_uint8PIN);
	}

	else if (Copy_uint8Value == 0)
	{
		CLR_BIT(PORTD_Register,Copy_uint8PIN);
	}


}

/*******************************************************************************/
/*******************************************************************************/
void EXTI_EN ()
{
	SET_BIT( GICR_REG , EXTI_LINE0 );
	SET_BIT( GICR_REG , EXTI_LINE1 );
	SET_BIT( GICR_REG , EXTI_LINE2 );
}

void EXTI_init ()
{

	// EXTI0 >>> SENSE MODE >>> ON CHANGE (Rising & Falling )
	SET_BIT( MCUCR_REG , 0 ); CLR_BIT( MCUCR_REG , 1 );

	// EXTI1 >>> SENSE MODE >>> ON CHANGE (Rising & Falling )
	SET_BIT( MCUCR_REG , 2 ); CLR_BIT( MCUCR_REG , 3 );

	// EXTI2 >>> SENSE MODE >>> Rising Edge
	SET_BIT( MCUCSR_REG , 6 );

	EXTI_EN ();

}

/*******************************************************************************/

void EXTI_ClearFlag ( uint8 Copy_uint8Line )
{
	SET_BIT( GIFR_REG , Copy_uint8Line );
}


/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

void main ()
{
	GPIOD_init ();
	EXTI_init ();
	// Global INT EN
	SET_BIT (SREG , SREG_I) ;

	while(1)
	{
		// Turn off all LEDs
		CLR_BIT(PORTD_Register,5);
		CLR_BIT(PORTD_Register,6);
		CLR_BIT(PORTD_Register,7);
	}
}

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/* ISR --> Implementation */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTI_ClearFlag( EXTI_LINE0 );
	// Turn led on
	PORTD_Register |= (1<<5);

	// Wait 1 second
	_delay_ms(1000);

	// Turn led off
	PORTD_Register &= (~1<<5);


}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTI_ClearFlag( EXTI_LINE1 );
	// Turn led on
	PORTD_Register |= (1<<6);

	// Wait 1 second
	_delay_ms(1000);

	// Turn led off
	PORTD_Register &= (~1<<6);


}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXTI_ClearFlag( EXTI_LINE2 );
	// Turn led on
	PORTD_Register |= (1<<7);

	// Wait 1 second
	_delay_ms(1000);

	// Turn led off
	PORTD_Register &= (~1<<7);

}
