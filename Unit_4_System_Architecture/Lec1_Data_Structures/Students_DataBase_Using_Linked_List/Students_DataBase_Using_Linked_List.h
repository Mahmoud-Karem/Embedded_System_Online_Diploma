/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Students_DataBase_Using_Linked_List.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Students_DataBase_Using_Linked_List.h
 *
 */ 

#ifndef STUDENTS_DATABASE_H_
#define STUDENTS_DATABASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>

#define NAME_LENGTH 50

#define DPRINTF(...) 		{fflush(stdout);fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);fflush(stdin);}


/***************************************************************************************************************/

typedef struct S_StudentData
{
	int ID;
	char Name[NAME_LENGTH]; 
	float height;
}StudentData_st;

typedef struct S_StudentNode
{
	StudentData_st       Student;
	struct S_StudentNode *pNext;
}StudentNode_st;


/***************************************************************************************************************/

void          LL_AddStudent                        (void                           );
int           LL_DeleteStudent                     (void                           );
void          LL_ViewStudents                      (void                           );
void          LL_DeleteAll                         (void                           );


void          LL_GetSpecificNode                   (int    index                   );

int           LL_Count_Students_IterativeMethod    (void                           );
int           LL_Count_Students_RecursiveMethod    (StudentNode_st *list           );

void          LL_GetSpecificNode_FromEND           (int    index                   );
void          LL_Get_The_Middle                    (void                           );
void          LL_Reverse_All                       (void                           );

static void   Fill_New_Record                      (StudentNode_st *NewStudent     ); /* Private Function  */ 

/***************************************************************************************************************/

#endif /* STUDENTS_DATABASE_H_ */