/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Linked_List.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Linked_List.h
 *
 */ 

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct point {
    int val;
    struct point *next;
}node;

void print_list              (node * head                                        );
void push_head               (node ** head_ptr , int val                         );
void push_end                (node * head      ,node **head_adr, int data        );
int  pop_head                (node ** head_ptr                                   );
int  remove_last             (node * head      ,node **head_ptr                  );
void insert_by_index         (node * head      ,node **head_ptr,int data ,int n  );
int  remove_by_index         (node ** head_ptr , int n                           );

#endif /* LINKED_LIST_H_ */