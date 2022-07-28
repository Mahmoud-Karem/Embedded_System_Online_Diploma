/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */  

/*************************************************************/
#include "Platform_Types.h"
#include "Util.h"

/* register address */
#define SYSCTL_BASE 		0x400FE000
#define GPIOF_BASE 			0x40025000

#define SYSCTL_RCGC2_R 		*((vuint32_t*) (SYSCTL_BASE + 0x108))
#define GPIO_PORTF_DATA_R 	*((vuint32_t*) (GPIOF_BASE  + 0x3FC))
#define GPIO_PORTF_DIR_R 	*((vuint32_t*) (GPIOF_BASE  + 0x400))
#define GPIO_PORTF_DEN_R	*((vuint32_t*) (GPIOF_BASE  + 0x51C))

/* bit fields*/
/*
typedef union {
	vuint32_t All_Fields;
	struct {
		vuint32_t reserved:13;
		vuint32_t p_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);
*/


void Delay_count(uint32_t count);

int main()
{
	ASSIGN_REG(SYSCTL_RCGC2_R, 0x20); //SYSCTL_RCGC2_R = 0x20 ; // Enable GPIO Port F
	Delay_count(200); // to make sure that GPIOF is up and running after enable the clock

	SET_BIT(GPIO_PORTF_DIR_R, 3); // output Direction for Pin 3 Port F
	SET_BIT(GPIO_PORTF_DEN_R, 3); // Enable the GPIO pin 3
	
	while(1)
	{
		TOG_BIT(GPIO_PORTF_DATA_R, 3);
		Delay_count(200000);
		TOG_BIT(GPIO_PORTF_DATA_R, 3);
		Delay_count(200000);
	}

	return 0;
}

void Delay_count(uint32_t count)
{
	vuint32_t Delay_Counter; // volatile to make sure that this loop will not be optimized
	
	for (Delay_Counter = 0; Delay_Counter < count; ++Delay_Counter);
}