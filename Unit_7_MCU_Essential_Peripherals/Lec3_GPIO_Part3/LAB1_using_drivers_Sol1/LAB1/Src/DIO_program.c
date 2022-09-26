/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 1/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

//==============================================================================================================


void MDIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	switch(Copy_u8Port)
	{
	case DIOA:

		if(Copy_u8Pin <= 7 )
		{
			//DIO_LOW

			// Clear the 4 Bits of the wanted Pin [0:15]
			DIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			
			// Set the Value(mode) on the 4 Bits of the wanted Pin [0:15]
			DIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}
		else if(Copy_u8Pin <=15 )
		{
			//DIO_HIGH

			Copy_u8Pin = Copy_u8Pin - 8;
			DIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			DIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case DIOB:

		if(Copy_u8Pin <= 7 )
		{//DIO_LOW

			DIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			DIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//DIO_HIGH
			Copy_u8Pin = Copy_u8Pin - 8;
			DIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			DIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	case DIOC:
		if(Copy_u8Pin <= 7 )
		{//DIO_LOW
			DIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			DIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{//DIO_HIGH
			Copy_u8Pin = Copy_u8Pin - 8;
			DIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			DIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	default :break;
	}


}

//==============================================================================================================


void MDIO_voidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value ){

	switch(Copy_u8Port)
	{
	case DIOA:
		if( u8Copy_u8Value == DIO_HIGH ){

			SET_BIT( DIOA_ODR , Copy_u8Pin );
			// /*or Using BSR for more speed */==> DIOA_BSR=(1<<Copy_u8Pin);

		}else if( u8Copy_u8Value == DIO_LOW ){
			CLR_BIT(  DIOA_ODR , Copy_u8Pin );
			// /*or Using BSR for more speed */==> DIOA_BSR=(1<<Copy_u8Pin+16);
			// /*or Using BRR for more speed than BSR */==> DIOA_BSR=(1<<Copy_u8Pin);
		}
		break;
		
	case DIOB:
		if( u8Copy_u8Value == DIO_HIGH ){

			SET_BIT( DIOB_ODR  , Copy_u8Pin );

		}else if( u8Copy_u8Value == DIO_LOW ){
			CLR_BIT( DIOB_ODR  , Copy_u8Pin );
		}
		break;
		
	case DIOC:
		if( u8Copy_u8Value == DIO_HIGH ){

			SET_BIT( DIOC_ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == DIO_LOW ){
			CLR_BIT( DIOC_ODR , Copy_u8Pin );
		}
		break;
	default : break; 

	}

}

//==============================================================================================================

u8   MDIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case DIOA:
		LOC_u8Result = GET_BIT( DIOA_IDR , Copy_u8Pin );

		break;
	case DIOB:

		LOC_u8Result = GET_BIT( DIOB_IDR , Copy_u8Pin );

		break;
	case DIOC:

		LOC_u8Result = GET_BIT( DIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}

//==============================================================================================================

void MDIO_voidSetPortDirection( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode ){

	switch( Copy_u8Port ){

	case DIOA:

		if      ( Copy_u8Position == DIO_LOW  ) { DIOA_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == DIO_HIGH ) { DIOA_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case DIOB:

		if      ( Copy_u8Position == DIO_LOW  ) { DIOB_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == DIO_HIGH ) { DIOB_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case DIOC:

		if      ( Copy_u8Position == DIO_LOW  ) { DIOC_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == DIO_HIGH ) { DIOC_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	default :break;

	}

}

//==============================================================================================================

void MDIO_voidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value ){

	switch( Copy_u8Port ){

	case DIOA:

		if      ( Copy_u8Position == DIO_LOW  ){ DIOA_ODR = (DIOA_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ DIOA_ODR = (DIOA_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case DIOB:

		if      ( Copy_u8Position == DIO_LOW  ){ DIOB_ODR = (DIOB_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ DIOB_ODR = (DIOB_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case DIOC:

		if      ( Copy_u8Position == DIO_LOW  ){ DIOC_ODR = (DIOC_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ DIOC_ODR = (DIOC_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	default :break;

	}

}

//==============================================================================================================

u16 MDIO_u16GetPortValue( u8 Copy_u8Port , u8 Copy_u8Position ){

	u16 LOC_u16Result = 0;

	switch( Copy_u8Port ){

	case DIOA:

		LOC_u16Result = DIOA_IDR;
		if      ( Copy_u8Position == DIO_LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == DIO_HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	case DIOB:

		LOC_u16Result = DIOB_IDR;
		if      ( Copy_u8Position == DIO_LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == DIO_HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	case DIOC:

		LOC_u16Result = DIOC_IDR;
		if      ( Copy_u8Position == DIO_LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == DIO_HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;

	}

	return LOC_u16Result ;

}


//==============================================================================================================
