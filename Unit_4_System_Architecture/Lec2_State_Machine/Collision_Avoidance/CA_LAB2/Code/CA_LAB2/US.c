/*
 * US.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */


#include "US.h"

int US_Get_Distance_Random (int l , int r , int count);

/* 1.Variables */
static int US_distance=0 ;

/* 2.STATE Pointer to func */
void (*pUS_state)();

/* 3.Definition of states/func */
STATE_define(US_busy)
{
	// State_Name
	US_State_ID=US_BUSY;

	//State_Action
	US_distance = US_Get_Distance_Random (45,55,1);

	printf ("US_busy state : distance=%d \n" ,US_distance);


	US_Set_Speed(US_distance);
	pUS_state = STATE(US_busy);


}

void US_Init()
{
	//Init US Driver
	printf ("US_Init\n");

}

/***************************************************************/

int US_Get_Distance_Random (int l , int r , int count)
{
	/* Generate one(count) random number in the range [l:r] */
	int i,rand_num;
	for (i=0 ; i<count ; i++)
	{
		rand_num = (rand() % (r - l + 1 )) + l ;
	}
	return rand_num;
}
