/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */ 
#ifndef   DIO_INTERFACE_H_
#define   DIO_INTERFACE_H_

 
typedef enum                 //it should be before functions prototypes
 {
	DIO_NOK,
	DIO_OK
	
 }DIO_ErrorStatus;
 

// Port Defines
#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3


// PIN Defines
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

// PIN Directions 
#define DIO_INPUT  0
#define DIO_OUTPUT 1

// PIN Value Options 
#define DIO_HIGH   1
#define DIO_LOW    0

//Pull UP
#define PUD   2


// IO Pins 
DIO_ErrorStatus DIO_enumSetPinDirection      (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction );
DIO_ErrorStatus DIO_enumSetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value     );
DIO_ErrorStatus DIO_enumGetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData   );
DIO_ErrorStatus DIO_enumTogglePinValue       (u8 Copy_u8PORT, u8 Copy_u8PIN                      );


// IO Ports 
DIO_ErrorStatus DIO_enumSetPortDirection     (u8 Copy_u8PORT, u8 Copy_u8Direction  );
DIO_ErrorStatus DIO_enumSetPortValue         (u8 Copy_u8PORT, u8 Copy_u8Value      );
DIO_ErrorStatus DIO_enumGetPortValue         (u8 Copy_u8PORT, u8 * Copy_PtrData    );
DIO_ErrorStatus DIO_enumTogglePortValue      (u8 Copy_u8PORT                       );


// IO Nibbles
DIO_ErrorStatus DIO_voidWriteHighNibbles (u8 Copy_u8PORT,u8 value);
DIO_ErrorStatus DIO_voidWriteLowNibbles  (u8 Copy_u8PORT,u8 value);

// Internal Pull Up
DIO_ErrorStatus DIO_enumConnectPullup(u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup);


#endif
