/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Stack_LIFO.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Stack_LIFO.h
 *
 */ 

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdint.h"
#include "lifo_cfg.h"

/*********************************************************************************************************************************/

/* Type Definitions */
typedef struct {
	uint32_t  length ;
	uint32_t  count ;
	element_type* base ;
	element_type* head ;
}LIFO_Buf_t;

/* Status */
typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL
}LIFO_Status_t;

/*********************************************************************************************************************************/

/* APIs */

LIFO_Status_t   LIFO_init          (LIFO_Buf_t *lifo_buf , element_type *item_buf , uint32_t buf_len);
LIFO_Status_t   LIFO_push          (LIFO_Buf_t *lifo_buf , element_type item                        );
LIFO_Status_t   LIFO_pop           (LIFO_Buf_t *lifo_buf , element_type *item                       );
LIFO_Status_t   LIFO_top           (LIFO_Buf_t *lifo_buf , element_type *item                       );
LIFO_Status_t   LIFO_print         (LIFO_Buf_t *lifo_buf                                            );
LIFO_Status_t   LIFO_is_full       (LIFO_Buf_t *lifo_buf                                            );
LIFO_Status_t   LIFO_is_empty      (LIFO_Buf_t *lifo_buf                                            );
LIFO_Status_t   LIFO_make_empty    (LIFO_Buf_t *lifo_buf                                            );

#endif /* LIFO_H_ */
