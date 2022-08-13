/*
 * CA.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

extern void (*pCA_state)();


/* Define States */
enum {
	CA_Waiting,
	CA_Driving
}CA_State_ID;

/* Declare State Functions of CA */
STATE_define(CA_waiting);  //void ST_CA_waiting();
STATE_define(CA_driving);  //void ST_CA_driving();



#endif /* CA_H_ */
