/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    NCIC_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 4/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

//==============================================================================================================
/*EXTI0
Function to Config the 4 bits of Periority @ AIRC reg @ SCB peripheral
*/
void MNVIC_voidInit(void)
{
    /* I put it here to remove it later with the function after making SCB driver   */
	#define SCB_AIRCR  *((u32*)0xE000ED0C) 
	
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

//==============================================================================================================

void MNVIC_voidSetPriority(s8 Copy_s8INTID , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority )
{

	/*  $ HINTS:-
	
		1- MNVIC_GROUP_SUB_DISTRIBUTION from NVIC_config.h 
		2- 0x100 Hex  ---> 256 Decimal
		3- ((MNVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256)) ==> represent No of Bits for sub periority
		    & we shift the group periority to reach the group bits and left the sub bits
		4- Local_u8Priority => it is the value which we will put in the 4 bits of this INT (Group bits & Sub bits )
		   depend on NVIC_config.h
	
	*/
	
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<((MNVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256));
	/* core peripheral 			*/
	if(Copy_s8INTID < 0)
	{
		/*
		if( Copy_s8INTID == MEMORY_MANAGE || Copy_s8INTID == BUS_FAULT || Copy_s8INTID == USAGE_FAULT ){

			Copy_s8INTID += 3;
			SCB_SHPR1 = ( Priority ) << ( (8 * Copy_s8INTID) + 4 );

		}
		else if ( Copy_s8INTID == SV_CALL ){

			Copy_s8INTID += 7;
			SCB_SHPR2 = ( Priority ) << ( (8 * Copy_s8INTID) + 4 );

		}
		else if( Copy_s8INTID == PEND_SV || Copy_s8INTID == SYSTICK ){

			Copy_s8INTID += 8;

			SCB_SHPR3 = ( Priority ) << ( (8 * Copy_s8INTID) + 4 );

		}
		*/

	}
	/* external peripheral		*/ /*EXTI0 = 6*/
	else if(Copy_s8INTID >= 0  && Copy_s8INTID < 60)
	{
		NVIC_IPR[Copy_s8INTID] = Local_u8Priority << 4 ; 
		// We shift left to put the value at MSB
	}
	/*
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;
		// WE already do that in void MNVIC_voidInit()
	*/
}

//==============================================================================================================

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber); // SET_BIT(NVIC_ISER0,Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	
}

//==============================================================================================================

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	
}

//==============================================================================================================

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	
}

//==============================================================================================================

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	
}


//==============================================================================================================

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result=0;
	
	if ( Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	
	return Local_u8Result ;
	
}


//==============================================================================================================

