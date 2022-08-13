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
/*
 * STATE(CA_waiting) = STATE(CA_waiting)
 */


#endif /* STATE_H_ */
