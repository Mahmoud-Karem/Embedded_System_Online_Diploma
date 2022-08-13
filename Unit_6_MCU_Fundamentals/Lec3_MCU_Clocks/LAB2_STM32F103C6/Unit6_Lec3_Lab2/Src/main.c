/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */

/*************************************************************/
#include "Platform_Types.h"

#define GPIOA_BASE  0x40010800
#define GPIOA_CRH   *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE    0x40021000
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR    *(vuint32_t *)(RCC_BASE + 0x04)


int main(void)
{
    RCC_APB2ENR |= (1<<2);      // Enable Clock for GPIOA
    RCC_CFGR    |= (0b100<<8);  // Set APB1 Prescale to \2
    RCC_CFGR    |= (0b101<<11); // Set APB2 Prescale to \4

    //Init GPIOA
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
    while(1)
    {
        GPIOA_ODR |= 1<<13 ;
        for (int i = 0; i < 5000; i++); // arbitrary delay
        GPIOA_ODR &= ~(1<<13) ;
        for (int i = 0; i < 5000; i++); // arbitrary delay
    }
}
