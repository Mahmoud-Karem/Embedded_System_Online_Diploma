/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    USART_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 11/7/2021
 *  Version : V01
 *  Layer   : MCAL
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"


void (* USART_ptrFunc[4])(void) = {0} ;

void USART_voidInit(void)
{
	USART1 -> BRR = USART_BAUD_RATE;
	
	USART1-> CR[0]  = 0;
	USART1-> CR[0] |= (USART_INTERRUPT <<4);
	USART1-> CR[0] |= (USART_PARITY_CONTROL <<9);
	USART1-> CR[0] |= (USART_WORD_LENGTH <<12);
	USART1-> CR[1]  = 0;
	USART1-> CR[1] |= (USART_STOP_BIT <<12);
	
	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */
	
	USART1 -> SR = 0;						/* Clearing status register */
	
}
void USART_voidTransmit(u8 Copy_u8Data)
{
	USART1 -> DR = Copy_u8Data;
	while((GET_BIT((USART1 -> SR), TC)) == 0);
}
u8   USART_u8Receive(void)
{
	while((GET_BIT((USART1 -> SR), RXNE)) == 0);
	return USART1 -> DR;
}
u8   USART_u8ReceiveTimeout(u32 Copy_u32Timeout)
{
	u16 timeout = 0;
	u8 Loc_u8ReceiveData = 0;
	while((GET_BIT((USART1 -> SR), RXNE)) == 0)
	{
		timeout++;
		if(timeout == Copy_u32Timeout)
		{
			Loc_u8ReceiveData = 255;
			break;
		}
	}
	if(Loc_u8ReceiveData != 255)
	{
		Loc_u8ReceiveData = USART1 -> DR;
	}
	return Loc_u8ReceiveData;
}
void USART_voidTransmitString(u8* Copy_ptrString)
{
	u8 LOC_u8Iterator = 0;
	while(Copy_ptrString[LOC_u8Iterator] != '\0')
	{
		USART_voidTransmit(Copy_ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}
u8*  USART_ptrReceiveString(void)
{
	u8 LOC_u8ReceiveChar = 0;
	u8 LOC_u8Iterator = 0;

	LOC_u8ReceiveChar = USART_u8Receive();
	while(LOC_u8ReceiveChar != 13) /* Enter */
	{
		LOC_u8Arr[LOC_u8Iterator] = LOC_u8ReceiveChar;
		LOC_u8ReceiveChar = USART_u8Receive();
		LOC_u8Iterator++;
	}
	LOC_u8Arr[LOC_u8Iterator]='\0';
	return LOC_u8Arr ;
	
}
void USART_voidSetCallBack(void (*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt)
{
	
	if(Copy_u8Interrupt == USART_INTERRUPT_TC_ENABLE)
	{
		USART_ptrFunc[0] = Copy_pvoidCallBack ; 	
	}
	else if (Copy_u8Interrupt == USART_INTERRUPT_RXNE_ENABLE)
	{
		USART_ptrFunc[1] = Copy_pvoidCallBack ;
	}

}

void USART1_IRQHandler(void)
{
	if((GET_BIT((USART1 -> SR), TC)) == 1)
	{
		if(USART_ptrFunc[0] != 0)
		{
			USART_ptrFunc[0]();
		}
	}
	if((GET_BIT((USART1 -> SR), RXNE)) == 1)
	{
		if(USART_ptrFunc[1] != 0)
		{
			USART_ptrFunc[1]();
		}
	}
}
