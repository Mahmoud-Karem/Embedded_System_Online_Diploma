/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Linked_List.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Linked_List.c
 *
 */ 


#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h" /* we will use the struct data type */


/***************************************************************************************************************/

void print_list(node * head)
{
    if(head=='\0')
    {
        printf("the linked list is empty\n");
    }
    else
    {
        while (head != '\0')
        {
            printf("%d\n", head->val);
            head = head->next;   // head = *(head).next;
        }
    }
}


/***************************************************************************************************************/

void push_head(node **head_ptr, int data)
{
    node *new_node;
    new_node =(node*)malloc(sizeof(node)); //create struct ( new node )

    new_node->val = data;
    new_node->next = *head_ptr;
	
    *head_ptr = new_node;
}


/***************************************************************************************************************/

void push_end(node * head,node **head_adr, int data)
{  
	//add node to the end of the linked list
    if(head=='\0')
    {
        push_head(head_adr,data);
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        /* now we can add a new variable */
        head->next = (node*) malloc(sizeof(node));
        head->next->val = data;
        head->next->next = '\0';
    }
}


/***************************************************************************************************************/

int pop_head(node **head_ptr)
 {
     if (*head_ptr != '\0')
    {
        int retval;
        node * next_node = '\0';
        next_node = (*head_ptr)->next;
        retval = (*head_ptr)->val;
        free(*head_ptr);
        *head_ptr = next_node;
        return retval;
    }
}


/***************************************************************************************************************/

int remove_last(node * head,node **head_ptr)
{
    if (*head_ptr != '\0')
    {
        int retval = 0;
		/* if there is only one item in the list, remove it */
        if (head->next == '\0')
        {
           retval=pop_head(head_ptr);
        }
        else
        {
			while (head->next->next != '\0')
			{
				head = head->next;
			}
			retval = head->next->val;
			free(head->next);
			head->next = '\0';
		}
		return retval;
    }
}


/***************************************************************************************************************/

void insert_by_index(node* head,node **head_ptr,int data ,int n)
{
node* temp;
node* current;
current=head;
int counter;
    if(n<0)
    {
        printf("the index must be positive number which greater than or equal zero\n");

    }
    else
    {
        if(head=='\0')
        {
            push_head(head_ptr,data);
        }
        for(counter=0;counter<n-1;counter++)
        {
            current=current->next;
        }
        temp=(node*)malloc(sizeof(node));
        temp->val=data;
        temp->next=current->next;
        current->next=temp;
    }
}


/***************************************************************************************************************/

int remove_by_index(node ** head_ptr, int n)
 {
    int i = 0;
    int retval;
    node * current = *head_ptr;
    node * temp_node = '\0';
    if(n<0)
    {
        printf("the index must be positive number which greater than or equal zero\n");
    }

    else if (n == 0)
    { //if the user inputs 0 so he want to remove the head
        retval=pop_head(head_ptr);
    }
    else if(*head_ptr=='\0')
    {
        printf("the linked list is empty \n");
    }
    else
    {
        for (i = 0; i < n-1; i++)
        {
            if (current->next == '\0')
            {
                return remove_last(*head_ptr,head_ptr);
            }
            current = current->next;
        }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    }
    return retval;
}

/***************************************************************************************************************/
