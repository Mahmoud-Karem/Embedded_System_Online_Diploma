/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    NCIC_interface.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 4/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
 
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define NO_SUB_PRIORITY 0

/////////////////////////
#define PEND_SV        -6
#define SYSTICK        -5
////////////////////////////
#define SV_CALL        -4
/////////////////////////
#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1
/////////////////////////

//#define For Interrupt ID =  POsition In Vector Table
#define WWDG   0
#define EXTI0   6
#define EXTI1   7
#define DMA_ID 11
#define USART1 37
/////////////////////////



void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber                                                  );
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber                                                  );
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber                                                  );
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber                                                  );
u8	 MNVIC_u8GetActiveFlag      (u8 Copy_u8IntNumber                                                  );
void MNVIC_voidSetPriority      (s8 Copy_s8INTID     , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority );
void MNVIC_voidInit             (void                                                                 );

#endif
