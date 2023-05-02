/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    AFIO_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 6/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H


//---------------------------------------------------------------------------------------------------------------------

#define AFIO_EXTI0  0
#define AFIO_EXTI1  1
#define AFIO_EXTI2  2
#define AFIO_EXTI3  3

#define AFIO_EXTI4  4
#define AFIO_EXTI5  5
#define AFIO_EXTI6  6
#define AFIO_EXTI7  7

#define AFIO_EXTI8  8
#define AFIO_EXTI9  9
#define AFIO_EXTI10 10
#define AFIO_EXTI11 11

#define AFIO_EXTI12 12
#define AFIO_EXTI13 13
#define AFIO_EXTI14 14
#define AFIO_EXTI15 15

//---------------------------------------------------------------------------------------------------------------------

void	MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap);

#endif
