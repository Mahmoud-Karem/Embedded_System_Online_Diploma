/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 6/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//==============================================================================================================

typedef	struct
{
	//volatile is not naccessary
	volatile	u32		IMR;   // Enable & Disable Interrupt
	volatile	u32		EMR;
	volatile	u32		RTSR;  // Rising
	volatile	u32		FTSR;  // Falling
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define	EXTI		(( EXTI_Type * )0X40010400)   //Casting to pointer to struct

//==============================================================================================================


#endif
