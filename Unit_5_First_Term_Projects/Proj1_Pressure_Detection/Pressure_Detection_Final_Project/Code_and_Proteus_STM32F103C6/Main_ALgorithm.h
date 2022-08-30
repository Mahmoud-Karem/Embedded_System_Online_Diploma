/*
 * Main_ALgorithm.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#ifndef MAIN_PROGRAM_H_
#define MAIN_PROGRAM_H_

#include "state.h"

/**********************************************************************************/

extern void (*pMA_state)();


/**********************************************************************************/

/* Define States */
enum {
	MA_Waiting,
	MA_Detecting
}MA_State_ID;


/**********************************************************************************/

/* Declare State Functions of CA */
STATE_define(MA_Waiting);
STATE_define(MA_Detecting);


/**********************************************************************************/

#endif /* MAIN_PROGRAM_H_ */
