/*
 * US.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#ifndef US_H_
#define US_H_

#include "state.h"

extern void (*pUS_state)();


/* Define States */
enum {
	US_BUSY
}US_State_ID;

/* Declare State Functions of US */
STATE_define(US_busy);  //void ST_US_busy();

/* INIT */
void US_Init();

#endif /* US_H_ */
