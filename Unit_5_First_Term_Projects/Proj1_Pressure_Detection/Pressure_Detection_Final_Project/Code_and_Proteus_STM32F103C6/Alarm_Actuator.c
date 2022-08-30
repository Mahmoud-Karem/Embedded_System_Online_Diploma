/*
 * Alarm_Actuator.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */


#include "Alarm_Actuator.h"
#include "GPIO.h"


/* 1.Variables */
static int Alarm_State=0 ;

/* 2.STATE Pointer to func */
void (*pAlarm_Actuator_state)();

/* 3.Definition of states/func */
STATE_define(Alarm_Actuator_idle)
{
	// State_Name
	Alarm_Actuator_State_ID=Alarm_Actuator_IDLE;

	/* For Testing */
	//printf ("Alarm_Actuator state : State=%d \n",Alarm_State );

}
STATE_define(Alarm_Actuator_busy)
{
	// State_Name
	Alarm_Actuator_State_ID=Alarm_Actuator_BUSY;


	pAlarm_Actuator_state=STATE(Alarm_Actuator_idle);

	/* For Testing */
	//printf ("Alarm_Actuator_busy state : State=%d \n",Alarm_State );

}

void Alarm_Actuator_Init()
{
	//Init Alarm_Actuator Motor Driver
	/* For Testing */
	//printf ("Alarm_Actuator_Init\n");
}

void Alarm_State_Set(int s)
{
	Alarm_State = s ;
	pAlarm_Actuator_state = STATE(Alarm_Actuator_busy);
	
	if (Alarm_State == 1)
	{
		GPIO_Start_Alarm_Actuator();
	}
	else if (Alarm_State == 0)
	{
		GPIO_Stop_Alarm_Actuator();
	}
	
	/* For Testing */
	//printf ("MA ---------- State=%d ----------> Alarm_Actuator\n" ,Alarm_State);

}

/***************************************************************/
