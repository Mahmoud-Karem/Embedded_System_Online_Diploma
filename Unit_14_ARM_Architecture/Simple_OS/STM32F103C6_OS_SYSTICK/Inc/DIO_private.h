/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 1/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H


#define DIOA_Base_Address        0x40010800            // define the boundary address of GPIO port A
#define DIOB_Base_Address        0x40010C00            // define the boundary address of GPIO port B
#define DIOC_Base_Address        0x40011000            // define the boundary address of GPIO port C

        /*       REGISTERS ADDRESSES FOR Port A        */

#define DIOA_CRL                 *((u32*)(DIOA_Base_Address + 0x00))
#define DIOA_CRH                 *((u32*)(DIOA_Base_Address + 0x04))
#define DIOA_IDR                 *((u32*)(DIOA_Base_Address + 0x08))
#define DIOA_ODR                 *((u32*)(DIOA_Base_Address + 0x0c))
#define DIOA_BSR                 *((u32*)(DIOA_Base_Address + 0x10))
#define DIOA_BRR                 *((u32*)(DIOA_Base_Address + 0x14))
#define DIOA_LCK                 *((u32*)(DIOA_Base_Address + 0x18))

        /*       REGISTERS ADDRESSES FOR Port B        */

#define DIOB_CRL                 *((u32*)(DIOB_Base_Address + 0x00))
#define DIOB_CRH                 *((u32*)(DIOB_Base_Address + 0x04))
#define DIOB_IDR                 *((u32*)(DIOB_Base_Address + 0x08))
#define DIOB_ODR                 *((u32*)(DIOB_Base_Address + 0x0c))
#define DIOB_BSR                 *((u32*)(DIOB_Base_Address + 0x10))
#define DIOB_BRR                 *((u32*)(DIOB_Base_Address + 0x14))
#define DIOB_LCK                 *((u32*)(DIOB_Base_Address + 0x18))

        /*       REGISTERS ADDRESSES FOR Port C        */

#define DIOC_CRL                 *((u32*)(DIOC_Base_Address + 0x00))
#define DIOC_CRH                 *((u32*)(DIOC_Base_Address + 0x04))
#define DIOC_IDR                 *((u32*)(DIOC_Base_Address + 0x08))
#define DIOC_ODR                 *((u32*)(DIOC_Base_Address + 0x0c))
#define DIOC_BSR                 *((u32*)(DIOC_Base_Address + 0x10))
#define DIOC_BRR                 *((u32*)(DIOC_Base_Address + 0x14))
#define DIOC_LCK                 *((u32*)(DIOC_Base_Address + 0x18))

#endif