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

//GPIO
#define GPIOA_BASE 			0x40010800
#define GPIOA_CRL 			*((vuint32_t*) (GPIOA_BASE + 0x00))
#define GPIOA_CRH 			*((vuint32_t*) (GPIOA_BASE + 0x04))
#define GPIOA_ODR 			*((vuint32_t*) (GPIOA_BASE + 0x0C))
#define GPIOA_Pin13	        (1UL<<13)


//EXTI
#define EXTI_BASE 			0x40010400
#define EXTI_IMR	    	*((vuint32_t*) (EXTI_BASE + 0x00))
#define EXTI_RTSR	    	*((vuint32_t*) (EXTI_BASE + 0x08))
#define EXTI_PR		        *((vuint32_t*) (EXTI_BASE + 0x14))

//AFIO
#define AFIO_BASE 			0x40010000
#define AFIO_EXTICR1		*((vuint32_t*) (AFIO_BASE + 0x08))
#define RCC_AF_PAEN	        (1<<0)


//NVIC
#define NVIC_BASE 			0xE000E100
#define NVIC_EXTI0_EN		*((vuint32_t*) (NVIC_BASE + 0x00))



/****************************************************************/

void Clock_init ()
{
	RCC_APB2ENR |= RCC_IOPAEN; // Enable clock RCC for GPIOA
	RCC_APB2ENR |= RCC_AF_PAEN; // Enable clock RCC for AFIO

}
void GPIO_init ()
{
	/* Pin 13 port A output  */
	GPIOA_CRH &= 0xff0fffff; // get them 0 first before change it
	GPIOA_CRH |= 0x00200000; // now we can set 2 safely

	/* Pin0  port A (Input Floating ) */
	GPIOA_CRL |= (1<<2);

}

int main(void)
{
	Clock_init();
	GPIO_init();

	//EXTI Configuration for Port A (It is already by default = 0000 for EXTI0)
	AFIO_EXTICR1 = 0 ;

	// Enable EXTI Line0
	EXTI_IMR |= (1<<0);

	// Enable Rising Trigger
	EXTI_RTSR |= (1<<0);

	// Enable NVIC IRQ >>> EXTI0
	NVIC_EXTI0_EN |= (1<<6);
	while(1)
	{

	}

	return 0;
}

void EXTI0_IRQHandler ()
{
	// Clear Pending Reg (RC_W1 >>> Read & Clear by writing 1)
	EXTI_PR |= (1<<0);

	// ISR (IRQ is happeded EXTI0 >>> GPIOA pin 0 >>> Rising edge >>> TOGGLE Led)
	GPIOA_ODR ^= (1<<13);

}
