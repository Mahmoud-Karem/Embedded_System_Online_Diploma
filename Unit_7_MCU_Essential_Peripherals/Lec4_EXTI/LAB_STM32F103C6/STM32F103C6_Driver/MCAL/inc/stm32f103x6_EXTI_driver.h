/*
 * stm32f103x6_EXTI_driver.h
 *
 *  Created on: Sep 25, 2022
 *      Author: Mahmoud Karem Zamel
 */

#ifndef INC_STM32F103X6_EXTI_DRIVER_H_
#define INC_STM32F103X6_EXTI_DRIVER_H_

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "STM32F103x6.h"
#include "stm32f103x6_GPIO_driver.h"

/* ================================================================ */
/* ========== User type definitions (structures) ================== */
/* ================================================================ */

typedef struct
{
	/* uint16 Due To EXTI Lines Are 0 ---> 15 */
	uint16_t		EXTI_InputLineNumber;	// Choose The Line Number To Use in EXTI

	GPIO_TypeDef* 	GPIOx;					// GPIO Port Used For EXTI Driver

	uint16_t		GPIO_Pin;				// GPIO Pin Used For EXTI Driver

	uint8_t			IVT_IRQ_Number;			// Choose Interrupt Handler From Interrupt Vector Table
}EXTI_GPIO_Mapping_t;

typedef struct
{
	EXTI_GPIO_Mapping_t 	EXTI_Pin;			// Specifics the EXTI GPIO Mapping
												// This parameter must be set based on @ref EXTI_define

	uint8_t					Trigger_Case;		// Specifics RISING or FALLING or Both trigger
												// This parameter must be set based on @ref EXTI_Trigger_define

	uint8_t					IRQ_Enable;			// Enable or Disable the EXTI IRQ (That will enable the IRQ mask in EXTI and also on the NVIC Interrupt contoller)
												// This parameter must be set based on @ref EXTI_IRQ_define

	void(*P_IRQ_CallBack)(void);					// Set the c Function() which will be called once the IRQ happen
}EXTI_PinConfig_t;

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

//@ ref EXTI_define

//EXTI0
#define EXTI0PA0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOA, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PB0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOB, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PC0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOC, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PD0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOD, GPIO_PIN_0, EXTI0_IRQ}


//EXTI1
#define EXTI1PA1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOA, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PB1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOB, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PC1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOC, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PD1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOD, GPIO_PIN_1, EXTI1_IRQ}


//EXTI2
#define EXTI2PA2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOA, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PB2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOB, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PC2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOC, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PD2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOD, GPIO_PIN_2, EXTI2_IRQ}


//EXTI3
#define EXTI3PA3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOA, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PB3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOB, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PC3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOC, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PD3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOD, GPIO_PIN_3, EXTI3_IRQ}


//EXTI4
#define EXTI4PA4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOA, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PB4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOB, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PC4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOC, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PD4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOD, GPIO_PIN_4, EXTI4_IRQ}


//EXTI5
#define EXTI5PA5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOA, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PB5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOB, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PC5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOC, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PD5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOD, GPIO_PIN_5, EXTI5_IRQ}


//EXTI6
#define EXTI6PA6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOA, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PB6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOB, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PC6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOC, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PD6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOD, GPIO_PIN_6, EXTI6_IRQ}


//EXTI7
#define EXTI7PA7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOA, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PB7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOB, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PC7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOC, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PD7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOD, GPIO_PIN_7, EXTI7_IRQ}


//EXTI8
#define EXTI8PA8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOA, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PB8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOB, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PC8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOC, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PD8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOD, GPIO_PIN_8, EXTI8_IRQ}


//EXTI9
#define EXTI9PA9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOA, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PB9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOB, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PC9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOC, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PD9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOD, GPIO_PIN_9, EXTI9_IRQ}


//EXTI10
#define EXTI10PA10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOA, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PB10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOB, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PC10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOC, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PD10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOD, GPIO_PIN_10, EXTI10_IRQ}


//EXTI11
#define EXTI11PA11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOA, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PB11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOB, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PC11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOC, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PD11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOD, GPIO_PIN_11, EXTI11_IRQ}


//EXTI12
#define EXTI12PA12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOA, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PB12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOB, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PC12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOC, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PD12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOD, GPIO_PIN_12, EXTI12_IRQ}


//EXTI13
#define EXTI13PA13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOA, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PB13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOB, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PC13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOC, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PD13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOD, GPIO_PIN_13, EXTI13_IRQ}


//EXTI14
#define EXTI14PA14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOA, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PB14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOB, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PC14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOC, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PD14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOD, GPIO_PIN_14, EXTI14_IRQ}


//EXTI15
#define EXTI15PA15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOA, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15PB15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOB, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15PC15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOC, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15PD15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOD, GPIO_PIN_15, EXTI15_IRQ}


//@ref EXTI_Trigger_define

#define EXTI_RT		0
#define EXTI_FT		1
#define EXTI_RFT	2

/*
 * Configuration reference
 */
#define EXTI0		0
#define EXTI1		1
#define EXTI2		2
#define EXTI3		3
#define EXTI4		4
#define EXTI5		5
#define EXTI6		6
#define EXTI7		7
#define EXTI8		8
#define EXTI9		9
#define EXTI10		10
#define EXTI11		11
#define EXTI12		12
#define EXTI13		13
#define EXTI14		14
#define EXTI15		15

//@ref EXTI_IRQ_define
#define EXTI_IRQ_Enable					1
#define EXTI_IRQ_Disable				0

/* ================================================================ */
/* ============== APIs Supported by "MCAL ..... DRIVER" =========== */
/* ================================================================ */

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t * EXTI_Config);
void MCAL_EXTI_GPIO_DeInit(void);
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t * EXTI_Config);


#endif /* INC_STM32F103X6_EXTI_DRIVER_H_ */
