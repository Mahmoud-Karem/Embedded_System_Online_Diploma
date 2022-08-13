/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Queue_FIFO.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Queue_FIFO.h
 *
 */ 

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
#include "fifo_cfg.h"

/*********************************************************************************************************************************/

/* Type Definitions */
typedef struct {
	element_type *base;
	element_type *head; /* front */
	element_type *tail; /* rear */
	uint32_t length;
	uint32_t counter;
}FIFO_Buf_t;

/* Status */
typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}FIFO_Status_t;


/*********************************************************************************************************************************/

/* APIs */

FIFO_Status_t   FIFO_init                (FIFO_Buf_t *fifo_buf, element_type *item, uint32_t length);
FIFO_Status_t   FIFO_enqueue             (FIFO_Buf_t *fifo_buf, element_type item                  );
FIFO_Status_t   FIFO_dequeue             (FIFO_Buf_t *fifo_buf, element_type *item                 );
FIFO_Status_t   FIFO_print               (FIFO_Buf_t *fifo_buf                                     );
FIFO_Status_t   FIFO_is_full             (FIFO_Buf_t *fifo_buf                                     );
FIFO_Status_t   FIFO_is_empty            (FIFO_Buf_t *fifo_buf                                     );
FIFO_Status_t   FIFO_make_empty          (FIFO_Buf_t *fifo_buf                                     );

#endif /* FIFO_H_ */
