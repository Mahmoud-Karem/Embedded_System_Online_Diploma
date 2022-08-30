/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */  

/*************************************************************/
#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "GPIO.h"
#include "Pressure_Sensor.h"
#include "Alarm_Actuator.h"
#include "Main_ALgorithm.h"

/***********************************/
void setup ()
{
	//init all the drivers ...
	//init IRQ ...
	//init HAL 
	GPIO_Init();
	//init Block
	PS_Init();
	Alarm_Actuator_Init();
	//Set states pointers for each block (init States for each one)
	pMA_state = STATE(MA_Waiting);
	pPS_state = STATE(PS_BUSY);
	pAlarm_Actuator_state = STATE(Alarm_Actuator_idle);

}

int main ()
{
	volatile int Delay ;

	setup();
	while (1)
	{
		//call sate for each block
		pPS_state();
		pMA_state();
		pAlarm_Actuator_state();
		for (Delay=0 ; Delay<=1000 ; Delay++);
	}
	return 0;
}

/***********************************/
