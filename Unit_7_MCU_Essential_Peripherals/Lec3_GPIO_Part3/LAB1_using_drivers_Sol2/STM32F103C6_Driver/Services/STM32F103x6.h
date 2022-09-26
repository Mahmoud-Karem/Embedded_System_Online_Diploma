/*
 * STM32F103x6.h
 *
 *  Created on: Sep 25, 2022
 *      Author: Mahmoud Karem Zamel
 */

#ifndef STM32F103X6_H_
#define STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include "Platform_Types.h"
#include "Util.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_BASE 			0x08000000UL
#define SRAM_BASE			0x20000000UL
#define PERIPHERALS_BASE	0x40000000UL

#define APB1_BUS_BASE     	(PERIPHERALS_BASE)
#define APB2_BUS_BASE     	(PERIPHERALS_BASE + 0x00010000UL)
#define AHB_BUS_BASE      	(PERIPHERALS_BASE + 0x00020000UL)

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

#define RCC_BASE            (AHB_BUS_BASE + 0x00001000UL)

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

#define AFIO_BASE           (APB2_BUS_BASE + 0x00000000UL)
#define EXTI_BASE           (APB2_BUS_BASE + 0x00000400UL)
#define GPIOA_BASE          (APB2_BUS_BASE + 0x00000800UL)
#define GPIOB_BASE          (APB2_BUS_BASE + 0x00000C00UL)
#define GPIOC_BASE          (APB2_BUS_BASE + 0x00001000UL)
#define GPIOD_BASE          (APB2_BUS_BASE + 0x00001400UL)
#define GPIOE_BASE          (APB2_BUS_BASE + 0x00001800UL)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	 vuint32_t CR;
	 vuint32_t CFGR;
	 vuint32_t CIR;
	 vuint32_t APB2RSTR;
	 vuint32_t APB1RSTR;
	 vuint32_t AHBENR;
	 vuint32_t APB2ENR;
	 vuint32_t APB1ENR;
	 vuint32_t BDCR;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	 vuint32_t CRL;
	 vuint32_t CRH;
	 vuint32_t IDR;
	 vuint32_t ODR;
	 vuint32_t BSRR;
	 vuint32_t BRR;
	 vuint32_t LCKR;
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	 vuint32_t EVCR;
	 vuint32_t MAPR;
	 vuint32_t EXTICR0;
	 vuint32_t EXTICR1;
	 vuint32_t EXTICR2;
	 vuint32_t EXTICR3;
	 uint32_t  RESERVED0;
	 vuint32_t MAPR2;
}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	 vuint32_t IMR;
	 vuint32_t EMR;
	 vuint32_t RTSR;
	 vuint32_t FTSR;
	 vuint32_t SWIER;
	 vuint32_t PR;
}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA			((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB			((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC			((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD			((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE			((GPIO_TypeDef*)GPIOE_BASE)

#define RCC				((RCC_TypeDef*)RCC_BASE)

#define EXTI			((EXTI_TypeDef*)EXTI_BASE)

#define AFIO			((AFIO_TypeDef*)AFIO_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()	(SET_BIT(RCC->APB2ENR,2))
#define RCC_GPIOB_CLK_EN()	(SET_BIT(RCC->APB2ENR,3))
#define RCC_GPIOC_CLK_EN()	(SET_BIT(RCC->APB2ENR,4))
#define RCC_GPIOD_CLK_EN()	(SET_BIT(RCC->APB2ENR,5))
#define RCC_GPIOE_CLK_EN()	(SET_BIT(RCC->APB2ENR,6))

#define AFIO_CLK_EN()		(SET_BIT(RCC->APB2ENR,0))

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* STM32F103X6_H_ */
