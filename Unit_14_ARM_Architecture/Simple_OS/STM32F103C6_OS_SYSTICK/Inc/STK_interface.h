/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STK_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 6/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* 
   Apply Clock choice from configuration file 
   Disable SysTick interrupt 
   Disable Systick  
*/
   
void MSTK_voidInit               (void                                        );
void MSTK_voidSetBusyWait        ( u32 Copy_u32Ticks                          );
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks , void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void (*Copy_ptr)(void) );
void MSTK_voidStopInterval       (void                                        );
u32  MSTK_u32GetElapsedTime      (void                                        );
u32  MSTK_u32GetRemainingTime    (void                                        );

#endif