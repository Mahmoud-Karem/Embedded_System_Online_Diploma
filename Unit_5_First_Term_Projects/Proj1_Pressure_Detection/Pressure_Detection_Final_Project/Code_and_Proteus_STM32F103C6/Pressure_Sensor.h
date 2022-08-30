/*
 * Pressure_Sensor.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */
 
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

extern void (*pPS_state)();

/* Define States */
enum {
	PS_BUSY,
}PS_State_ID;

/* Declare State Functions of PS */
STATE_define(PS_BUSY);  

/* INIT */
void PS_Init();

#endif /* PRESSURE_SENSOR_H_ */
