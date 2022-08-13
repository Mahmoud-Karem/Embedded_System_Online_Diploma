/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Stack_LIFO_Linked_List.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Stack_LIFO_Linked_List.c
 *
 */ 


#include <stdio.h>
#include <stdlib.h>
#include "stack functions.h"

node_t *top='\0';
int count = 0;


/***************************************************************************************************************/

int is_stack_empty(void)
{
    int x;
    if (top == '\0')
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}


/***************************************************************************************************************/

void push(int value)
{
    node_t* temp;
    if (top == '\0')
    {
        top =(node_t*)malloc(sizeof(node_t));
        top->next = '\0';
        top->data = value;
    }
    else
    {
        temp =(node_t*)malloc(sizeof(node_t));
        temp->next = top;
        temp->data = value;
        top = temp;
    }
    count++;
}


/***************************************************************************************************************/

int pop(void)
{
    int x;
    node_t *top1=top;
    top1=top1->next;
    x=top->data;
    free(top);
    top = top1;
    count--;
    return x;
}


/***************************************************************************************************************/

void display_stack_elements(void)
{
    node_t *top1 = top;
    while (top1 != '\0')
    {
        printf("%i\n",top1->data);
        top1 = top1->next;
    }
}


/***************************************************************************************************************/

int top_element(void)
{
    return top->data;
}


/***************************************************************************************************************/

int stack_count(void)
{
    return count ;
}


/***************************************************************************************************************/
