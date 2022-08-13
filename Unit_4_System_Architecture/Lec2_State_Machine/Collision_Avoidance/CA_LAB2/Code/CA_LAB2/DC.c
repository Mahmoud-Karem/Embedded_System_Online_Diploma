/*
 * DC.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */


#include "DC.h"

//int US_Get_Distance_Random (int l , int r , int count);

/* 1.Variables */
static int DC_speed=0 ;

/* 2.STATE Pointer to func */
void (*pDC_state)();

/* 3.Definition of states/func */
STATE_define(DC_idle)
{
	// State_Name
	DC_State_ID=DC_IDLE;

	//State_Action
	//Call PWM to make speed = DC_speed


	printf ("DC_idle state : speed=%d \n",DC_speed );

}
STATE_define(DC_busy)
{
	// State_Name
	DC_State_ID=DC_BUSY;

	//State_Action
	//Call PWM to make speed = DC_speed

	pDC_state=STATE(DC_idle);

	printf ("DC_busy state : speed=%d \n",DC_speed );

}

void DC_Init()
{
	//Init DC Motor Driver
	printf ("DC_Init\n");
}

void DC_Motor_Set(int s)
{
	DC_speed = s ;
	pDC_state = STATE(DC_busy);
	printf ("CA ---------- speed=%d ----------> DC\n" ,DC_speed);

}

/***************************************************************/

//int US_Get_Distance_Random (int l , int r , int count)
//{
//	int i,rand_num;
//	for (i=0 ; i<count ; i++)
//	{
//		rand_num = (rand() % (r - l + 1 )) + l ;
//	}
//	return rand_num;
//}
