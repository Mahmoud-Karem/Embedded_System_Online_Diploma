/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 29 June 2021
 *  Vertion : V01
 *  Layer   : MCAL
 *
 */ 



/* include Libraries  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* include files of lower layer */
// Nothing Because this driver in MCAL Layer 

/* Own Driver Files */
#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"
   
 
//==============================================================================================================

void RCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000;

	#elif   RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE

		#endif

	#else
		#error("You chosed Wrong Clock type")
	#endif
}



//==============================================================================================================


void RCC_voidEnablePeripheralClock( u8 Copy_u8BusId , u8 Copy_u8PeripheralId ){


		
	if (Copy_u8BusId <= 31)
	{
		switch( Copy_u8BusId ){

			case AHB_BUS  : SET_BIT( RCC_AHBENR  , Copy_u8PeripheralId ); break;
			case APB1_BUS :	SET_BIT( RCC_APB1ENR , Copy_u8PeripheralId ); break;
			case APB2_BUS : SET_BIT( RCC_APB2ENR , Copy_u8PeripheralId ); break;
			//default       : /* Return Error */

		}
	}
	
	else
	{
		/* Return Error*/
	}


}

//==============================================================================================================


void RCC_voidDisablePeripheralClock( u8 Copy_u8BusId , u8 Copy_u8PeripheralId ){

		switch( Copy_u8BusId ){

			case AHB_BUS  : CLR_BIT( RCC_AHBENR  , Copy_u8PeripheralId ); break;
			case APB1_BUS :	CLR_BIT( RCC_APB1ENR , Copy_u8PeripheralId ); break;
			case APB2_BUS : CLR_BIT( RCC_APB2ENR , Copy_u8PeripheralId ); break;

		}
}

//==============================================================================================================
