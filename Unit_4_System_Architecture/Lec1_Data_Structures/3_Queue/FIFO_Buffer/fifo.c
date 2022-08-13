/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Queue_FIFO.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Queue_FIFO.c
 *
 */ 

#include "stdio.h"
#include "stdint.h"
#include "fifo.h"


FIFO_Status_t FIFO_init(FIFO_Buf_t *fifo_buf, element_type *item, uint32_t length)
{
	// Check if parameters are already valid
	if(!fifo_buf || !item || !length)
	{
		//printf("FIFO Initialization failed: Null pointer or zero length is passed\n");

		return FIFO_NULL;
	}

	// Check underflow (LIFO IS EMPTY)
	fifo_buf->base    = item;
	fifo_buf->head    = item;
	fifo_buf->tail    = item;
	fifo_buf->length  = length;
	fifo_buf->counter = 0;

	return FIFO_NO_ERROR;
}


FIFO_Status_t FIFO_enqueue(FIFO_Buf_t *fifo_buf, element_type item)
{
	//Check if parameters are already valid
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		//printf("FIFO Enqueue failed: Null is passed\n");

		return FIFO_NULL;
	}

	// Check if FIFO is Full ?!
	if((FIFO_is_full(fifo_buf)) == FIFO_FULL)
	{
		//printf("FIFO Enqueue failed: FIFO is full\n");

		return FIFO_FULL;
	}

	// Enqueue new item
	*(fifo_buf->head) = item;

#if defined fifo_circular
	//if((fifo_buf->head + 1) == (fifo_buf->base + fifo_buf->length)) // Check if the head in the end of fifo to start over
	if((fifo_buf->head + 1 ) == (fifo_buf->base + (fifo_buf->length * sizeof(element_type)))) // Check if the head in the end of fifo to start over
	{
		fifo_buf->head = fifo_buf->base;
	}
	else
	{
		fifo_buf->head++;
	}
#elif defined fifo_no_circular
	fifo_buf->head++;
#endif

	fifo_buf->counter++;

	return FIFO_NO_ERROR;
}

FIFO_Status_t FIFO_dequeue(FIFO_Buf_t *fifo_buf, element_type *item)
{
	//Check if parameters are already valid
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail || !item )
	{
		//printf("FIFO Dequeue failed: Null is passed\n");

		return FIFO_NULL;
	}

	// Check if FIFO is Empty ?!
	if((FIFO_is_empty(fifo_buf)) == FIFO_EMPTY)
	{
		//printf("FIFO Dequeue failed: FIFO is empty\n");

		return FIFO_EMPTY;
	}

	// Dequeue the top item
	*item = *(fifo_buf->tail);

#if defined fifo_circular

	//if((fifo_buf->tail + 1) == (fifo_buf->base + fifo_buf->length))
	if((fifo_buf->tail + 1 ) == (fifo_buf->base + (fifo_buf->length * sizeof(element_type)))) // Check if the head in the end of fifo to start over
	{
		fifo_buf->tail = fifo_buf->base;
	}
	else
	{
		fifo_buf->tail++;
	}
#elif defined fifo_no_circular
	fifo_buf->tail++;
#endif

	fifo_buf->counter--;

	return FIFO_NO_ERROR;
}

FIFO_Status_t FIFO_print(FIFO_Buf_t *fifo_buf)
{
	element_type *temp;
	uint32_t i;

	//Check if parameters are already valid
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		printf("FIFO Print failed: Null is passed\n");

		return FIFO_NULL;
	}

	// Check if FIFO is Empty ?!
	if((FIFO_is_empty(fifo_buf)) == FIFO_EMPTY)
	{
		printf("FIFO Print failed: FIFO is empty\n");

		return FIFO_EMPTY;
	}

	// Perform the printing
	printf("=======FIFO print=======\n");
	for(temp = fifo_buf->tail, i = 0; i < fifo_buf->counter; i++)
	{
		printf("\t%d\n", *temp);

#if defined fifo_circular
		//if((temp + 1) == (fifo_buf->base + fifo_buf->length))
		if((temp + 1 ) == (fifo_buf->base + (fifo_buf->length * sizeof(element_type)))) // Check if the head in the end of fifo to start over
		{
			temp = fifo_buf->base;
		}
		else
		{
			temp++;
		}
#elif defined fifo_no_circular
	temp++;
#endif

	}
	printf("========================\n");

	return FIFO_NO_ERROR;
}

FIFO_Status_t FIFO_is_full(FIFO_Buf_t *fifo_buf)
{
	//Check if parameters are already valid
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		printf("FIFO is full failed: Null is passed\n");

		return FIFO_NULL;
	}

	// Check if the number of items matches the total buffer length
	if(fifo_buf->counter == fifo_buf->length)
	{
		return FIFO_FULL;
	}

	return FIFO_NOT_FULL;
}

FIFO_Status_t FIFO_is_empty(FIFO_Buf_t *fifo_buf)
{
	//Check if parameters are already valid
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		printf("FIFO is empty failed: Null is passed\n");

		return FIFO_NULL;
	}

	// Check if the number of items is zero
	if(fifo_buf->counter == 0)
	{
		return FIFO_EMPTY;
	}

	return FIFO_NOT_EMPTY;
}

FIFO_Status_t FIFO_make_empty(FIFO_Buf_t *fifo_buf)
{
	//Check if parameters are already valid
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		printf("FIFO is empty failed: Null is passed\n");

		return FIFO_NULL;
	}

	// Reset the head, the tail, and the number of items
	fifo_buf->head = fifo_buf->base;
	fifo_buf->tail = fifo_buf->base;
	fifo_buf->counter = 0;

	return FIFO_NO_ERROR;
}
