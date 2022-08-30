/*
 * Pressure_Sensor.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */


#include "Pressure_Sensor.h"
#include "GPIO.h"

/* For Testing */
//int PS_Get_Pressure_Random (int l , int r , int count);


/* 1.Variables */
static int P_Val=0 ;

/* 2.STATE Pointer to func */
void (*pPS_state)();

/* 3.Definition of states/func */

STATE_define(PS_BUSY)
{
	// State Name
	PS_State_ID = PS_BUSY;

	//State_Action
	
	/* For Testing */
	//P_Val = PS_Get_Pressure_Random (15,25,1);
	
	P_Val = GPIO_Get_Pressure_Val ();
	
	/* For Testing */
	//printf ("PS_busy state : Pressure=%d \n" ,P_Val);
	
	
	// Check event and update state
	Set_Pressure_Val(P_Val);
	pPS_state = STATE(PS_BUSY);
}


void PS_Init()
{
	//Init PS Driver
	/* For Testing */
	//printf ("PS_Init\n");

}

/***************************************************************/
/* For Testing */
//int PS_Get_Pressure_Random (int l , int r , int count)
//{
//	/* Generate one(count) random number in the range [l:r] */
//	int i,rand_num;
//	for (i=0 ; i<count ; i++)
//	{
//		rand_num = (rand() % (r - l + 1 )) + l ;
//	}
//	return rand_num;
//}



