/*
 * Main_ALgorithm.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */
#ifndef GPIO_H_
#define GPIO_H_

#include "Platform_Types.h"
#include "BIT_MATH.h"

/***********************************************************************/


/* RCC Reg Def */
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)

/***********************************************************************/

/* GPIO Reg Def */
#define GPIO_PORTA 0x40010800

#define GPIOA_CRL *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

/***********************************************************************/
/* API  */
void     GPIO_Init                (void       );
void     GPIO_delay               (int  nCount);
uint32_t GPIO_Get_Pressure_Val    (void       );
void     GPIO_Start_Alarm_Actuator(void       );
void     GPIO_Stop_Alarm_Actuator (void       );

/***********************************************************************/


#endif /* GPIO_H_ */
