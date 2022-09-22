/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */

/*************************************************************/
#include "Platform_Types.h"

/****************************************************************/
/* register address */
//RCC
#define RCC_BASE 			0x40021000
#define RCC_APB2ENR 		*((vuint32_t*) (RCC_BASE + 0x18))
#define RCC_IOPAEN	        (1<<2)
#define RCC_IOPBEN	        (1<<3)

//GPIO
#define GPIOA_BASE 			0x40010800
#define GPIOA_CRL 			*((vuint32_t*) (GPIOA_BASE + 0x00))
#define GPIOA_CRH 			*((vuint32_t*) (GPIOA_BASE + 0x04))
#define GPIOA_ODR 			*((vuint32_t*) (GPIOA_BASE + 0x0C))
#define GPIOA_IDR 			*((vuint32_t*) (GPIOA_BASE + 0x08))
#define GPIOA_Pin13	        (1UL<<13)

#define GPIOB_BASE 			0x40010C00
#define GPIOB_CRL 			*((vuint32_t*) (GPIOB_BASE + 0x00))
#define GPIOB_CRH 			*((vuint32_t*) (GPIOB_BASE + 0x04))
#define GPIOB_ODR 			*((vuint32_t*) (GPIOB_BASE + 0x0C))
#define GPIOB_IDR 			*((vuint32_t*) (GPIOB_BASE + 0x08))



/****************************************************************/

void Clock_init ()
{
	RCC_APB2ENR |= RCC_IOPAEN; // Enable clock RCC for GPIOA
	RCC_APB2ENR |= RCC_IOPBEN; // Enable clock RCC for GPIOB

}
void GPIO_init ()
{
	GPIOA_CRL = 0x0;
	GPIOB_CRL = 0x0;
	/* PA1 --> I/P (High Impedence / Floating)  */
	GPIOA_CRL |= (1<<6);
	/* PA13 --> I/P (High Impedence)  */
	GPIOA_CRH &= ~(0b11<<20);
	GPIOA_CRH |= (0b01<<22);
	/* PB1 --> O/P (PushPull)  */
	GPIOB_CRL &= ~(0b11<<6);
	GPIOB_CRL |= (0b01<<4);
	/* PB13 --> O/P (PushPull)  */
	GPIOB_CRH |= (0b01<<20);
	GPIOB_CRH &= ~(0b11<<22);

}


void My_Wait(int x)
{
	unsigned int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);

}

int main(void)
{
	Clock_init();
	GPIO_init();


	while(1)
	{
		//PA1 --> Connected external PUR
		if(((GPIOA_IDR & (1<<1))>>1)==0) //press
		{
			GPIOB_ODR ^= 1<<1 ;
			while(((GPIOA_IDR & (1<<1))>>1)==0); //for single press
		}

		//PA13 --> Connected external PDR
		if(((GPIOA_IDR&(1<<13))>>13)==1) //Multi press
		{
			GPIOB_ODR ^= 1<<13 ;
		}

		My_Wait(1);

	}

	return 0;
}
