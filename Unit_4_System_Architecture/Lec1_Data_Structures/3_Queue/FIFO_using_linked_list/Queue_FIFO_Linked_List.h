/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Queue_Linked_List.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Queue_Linked_List.h
 *
 */ 

#ifndef FIFO_LL_H_
#define FIFO_LL_H_

int  is_queue_empty          (void     );
void enqueue                 (int value);
int  dequeue                 (void     );
void display_Queue_elements  (void     );
int  number_of_Queue_elements(void     );


#endif /* FIFO_LL_H_ */