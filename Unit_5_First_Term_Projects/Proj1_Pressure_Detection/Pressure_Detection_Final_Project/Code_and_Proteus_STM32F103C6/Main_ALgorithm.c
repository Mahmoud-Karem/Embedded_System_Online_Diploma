/*
 * Main_ALgorithm.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#include "Main_ALgorithm.h"
#include "Alarm_Actuator.h"
#include "Platform_Types.h"

/**********************************************************************************/

/* 1.Variables */
static int      P_Val=0;
static boolean  Alarm_State=0;
static int      P_threshold = 20;

/**********************************************************************************/

/* 2.STATE Pointer to func */
void (*pMA_state)();

/**********************************************************************************/

/* 3.Definition of states/func */
STATE_define(MA_Waiting)
{
	// State_Name
	MA_State_ID=MA_Waiting;
	/* For Testing */
	//printf ("MA_Waiting state : Pressure=%d\n" ,P_Val);

	//State_Action
	Alarm_State=0;

	Alarm_State_Set(Alarm_State);


}
STATE_define(MA_Detecting)
{
	// State_Name
	MA_State_ID=MA_Detecting;
	/* For Testing */
	//printf ("MA_Waiting state : Pressure=%d\n" ,P_Val);

	//State_Action
	Alarm_State=1;
	
	Alarm_State_Set(Alarm_State);

}
/**********************************************************************************/

void Set_Pressure_Val(int p)
{
	P_Val = p;

	/* you must determine the destination state here */
	( P_Val <= P_threshold ) ? (pMA_state = STATE(MA_Waiting)) : (pMA_state = STATE(MA_Detecting));

	/* For Testing */
	//printf ("PS ---------- Pressure=%p ----------> MA\n" ,P_Val);

}


/**********************************************************************************/
