/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    NCIC_private.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 4/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

//==============================================================================================================
/* Enable External interrupts from 0  to 31 */
#define NVIC_ISER0       *((u32*)0xE000E100) 
/* Enable External interrupts from 32 to 63 (59) */
#define NVIC_ISER1       *((u32*)0xE000E104) 
//----------------------------------------------------
#define NVIC_ICER0       *((u32*)0xE000E180)
#define NVIC_ICER1       *((u32*)0xE000E184)
//----------------------------------------------------
#define NVIC_ISPR0       *((u32*)0xE000E200)
#define NVIC_ISPR1       *((u32*)0xE000E204)
//----------------------------------------------------
#define NVIC_ICPR0       *((u32*)0xE000E280)
#define NVIC_ICPR1       *((u32*)0xE000E284)
//----------------------------------------------------
#define NVIC_IABR0       *((volatile u32*)0xE000E300)
#define NVIC_IABR1       *((volatile u32*)0xE000E304)
//----------------------------------------------------
/*  without Dereference	(u8 pointer)  */
#define NVIC_IPR          ((u8*)0xE000E400)
//----------------------------------------------------
#define MNVIC_GROUP_4_SUB_0      0x05FA0300
#define MNVIC_GROUP_3_SUB_1      0x05FA0400
#define MNVIC_GROUP_2_SUB_2      0x05FA0500
#define MNVIC_GROUP_1_SUB_3      0x05FA0600
#define MNVIC_GROUP_0_SUB_4      0x05FA0700
//==============================================================================================================


#endif
