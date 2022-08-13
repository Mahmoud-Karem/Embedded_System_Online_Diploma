/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Stack_LIFO_Linked_List.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Stack_LIFO_Linked_List.h
 *
 */ 
#ifndef LIFO_LL_H_
#define LIFO_LL_H_


typedef struct node
{
    int data;
    struct node *next;
}node_t;

int  is_stack_empty        (void      );
void push                  (int  value);
int  pop                   (void      );
void display_stack_elements(void      );
int  top_element           (void      );
int  stack_count           (void      );

#endif /* LIFO_LL_H_ */
