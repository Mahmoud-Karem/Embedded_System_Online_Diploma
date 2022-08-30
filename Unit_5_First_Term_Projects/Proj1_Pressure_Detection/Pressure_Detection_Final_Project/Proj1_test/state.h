/*
 * state.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Mahmoud Karem Zamel
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

/* Automatic State Function Generated */
#define STATE_define(_StateFunc_) void ST_##_StateFunc_()



/* Func name for using in implementation for calling */
#define STATE(_StateFunc_)  ST_##_StateFunc_


/*** States Connections ***/


/* Pressure_Sensor_Driver --> Main_Algorithm */
void Set_Pressure_Val(int p);

/* Main_Algorithm --> Alarm_Monitor */
void High_Pressure_Detected(void);

/* Alarm_Monitor --> Alarm_Actuator */
void Start_Alarm(void);

/* Alarm_Monitor --> Alarm_Actuator */
void Stop_Alarm(void);




#endif /* STATE_H_ */
