/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    USART_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 11/7/2021
 *  Version : V01
 *  Layer   : MCAL
 *
 */


#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/* USART word Length */

#define USART_8_BIT_WORD					 	0
#define USART_9_BIT_WORD					 	1

/* USART Parity Control */

#define USART_PARITY_DISABLED			 	0
#define USART_PARITY_ENABLED_EVEN_PARITY		2
#define USART_PARITY_ENABLED_ODD_PARITY		3

/* USART Interrupt */ 

#define USART_INTERRUPT_DISABLE				0
#define USART_INTERRUPT_PE_ENABLE			16
#define USART_INTERRUPT_TXE_ENABLE			8
#define USART_INTERRUPT_TC_ENABLE			4
#define USART_INTERRUPT_RXNE_ENABLE			2
#define USART_INTERRUPT_IDLE_ENABLE			1

/* USART Stop Bits */ 

#define USART_1_STOP_BIT                     0
#define USART_0_5_STOP_BIT                   1
#define USART_2_STOP_BIT                     2
#define USART_1_5_STOP_BIT                   3

/* USART BAUD RATE */

#define USART_BAUD_RATE_9600 				 0x0341

#define USART_BAUD_RATE_115200 				 0x0045

typedef enum 
{
	PE,
	FE,
	NE,
	ORE,
	IDLE,
	RXNE,
	TC,
	TXE,
	LBD,
	CTS
}USART_Flags;

u8 LOC_u8Arr[40];

void USART_voidInit(void);
void USART_voidTransmit(u8 Copy_u8Data);
u8   USART_u8Receive(void);
u8   USART_u8ReceiveTimeout(u32 Copy_32Timeout );
void USART_voidTransmitString(u8* Copy_ptrString);
u8*  USART_ptrReceiveString(void);
void USART_voidSetCallBack(void (*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt);

#endif 
