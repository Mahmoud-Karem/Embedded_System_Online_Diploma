/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 29 June 2021
 *  Vertion : V01
 *  Layer   : MCAL
 *
 */ 

#ifndef RCC_PRIVATE_H_ 
#define RCC_PRIVATE_H_

//==============================================================================================================

/* Register Definitions  */

#define RCC_CR            *((volatile u32*)0x40021000)
#define RCC_CFGR          *((volatile u32*)0x40021004)
#define RCC_CIR           *((volatile u32*)0x40021008)
#define RCC_APB2RSTR      *((volatile u32*)0x4002100C)
#define RCC_APB1RSTS      *((volatile u32*)0x40021010)
#define RCC_AHBENR        *((volatile u32*)0x40021014)
#define RCC_APB2ENR       *((volatile u32*)0x40021018)
#define RCC_APB1ENR       *((volatile u32*)0x4002101C)
#define RCC_BDCR          *((volatile u32*)0x40021020)
#define RCC_CSR           *((volatile u32*)0x40021024)

//==============================================================================================================

/* Anothor Method For Register Definitions   */
/*
typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC;

// M is Refer To MCAL

#define MRCC ((volatile RCC *)0x40021000)
*/

//==============================================================================================================



#endif /* RCC_PRIVATE_H_ */
