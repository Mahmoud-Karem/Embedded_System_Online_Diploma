/*
 * Alarm_Actuator.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#ifndef Alarm_Actuator_H_
#define Alarm_Actuator_H_

#include "state.h"

/**********************************************************************************/

extern void (*pAlarm_Actuator_state)();

/**********************************************************************************/


/* Define States */
enum {
	Alarm_Actuator_IDLE,
	Alarm_Actuator_BUSY
}Alarm_Actuator_State_ID;

/* Declare State Functions of Alarm_Actuator */
STATE_define(Alarm_Actuator_idle);  //void ST_Alarm_Actuator_idle();
STATE_define(Alarm_Actuator_busy);  //void ST_Alarm_Actuator_busy();

/**********************************************************************************/

/* INIT */
void Alarm_Actuator_Init();
/* Set State */
void Alarm_State_Set(int s);

/**********************************************************************************/

#endif /* Alarm_Actuator_H_ */
