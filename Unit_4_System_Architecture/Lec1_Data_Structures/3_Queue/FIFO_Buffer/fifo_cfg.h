/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Queue_FIFO.cfg    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Queue_FIFO.cfg
 *
 */ 

#ifndef FIFO_CFG_H_
#define FIFO_CFG_H_

#include "stdio.h"
#include "stdint.h"

/*
	# Select the element type
	$ Options :-
	 1 uint8_t
	 2 uint16_t
	 3 uint32_t
	 4 uint64_t
*/
#define element_type uint8_t

/*
	# Select the type of fifo 
	$ Options :-
	 1 fifo_circular
	 2 fifo_no_circular
*/
#define fifo_circular


#endif /* FIFO_CFG_H_ */
