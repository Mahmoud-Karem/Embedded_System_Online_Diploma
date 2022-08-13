/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Students_DataBase_Using_Linked_List.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Students_DataBase_Using_Linked_List.c
 *
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>

#include "Students_DataBase_Using_Linked_List.h" /* we will use the struct data type */


StudentNode_st *gp_FirstStudent = NULL;

/***************************************************************************************************************/
void LL_AddStudent(void)
{
	StudentNode_st *pNewStudent ;
	StudentNode_st *pLastStudent ;

	/* Check if the list is empty */
	if (gp_FirstStudent == NULL)
	{
		/* Create the first student */
		pNewStudent = (StudentNode_st*) malloc(sizeof(StudentNode_st));

		/* Check for invalid allocation */
		if(pNewStudent == NULL)
		{
			printf("Error: Sorry...Can't create new student\n");
			return;
		}

		/* Assign the gp_FirstStudent value */
		gp_FirstStudent = pNewStudent;
	}
	/* If the list contain records */
	else 
	{
		/* reach the last record */
		pLastStudent = gp_FirstStudent;
		while(pLastStudent->pNext)
		{
			pLastStudent = pLastStudent->pNext;
		}

		/* Create new record */
		pNewStudent = (StudentNode_st*) malloc(sizeof(StudentNode_st));

		/* Assign the next Address */
		pLastStudent->pNext = pNewStudent;
	}

	/* Fill the record */
	Fill_New_Record(pNewStudent);

	/* Assign the next to NULL */
	pNewStudent->pNext = NULL;
}

/***************************************************************************************************************/
int LL_DeleteStudent(void)
{
	char temp_text[NAME_LENGTH];
	uint32_t Selected_ID;

	/* Get the selected ID from the user */
	DPRINTF("\nEnter Student ID to be deleted: ");
	gets(temp_text);
	Selected_ID = atoi(temp_text);

	if(gp_FirstStudent) 
	{
		StudentNode_st *pSelectedStudent = gp_FirstStudent;
		StudentNode_st *pPreviousStudent = NULL ;

		/* Loop on all records starting from the gp_FirstStudent */
		while(pSelectedStudent)
		{
			/* Compare the recorded ID with the selected ID */
			if(pSelectedStudent->Student.ID == Selected_ID)
			{
				if(pPreviousStudent)
				{
					pPreviousStudent->pNext = pSelectedStudent->pNext;
				}
				else
				{
					gp_FirstStudent = pSelectedStudent->pNext;
				}
				free(pSelectedStudent);
				DPRINTF("\nThe ID is been deleted. \n");
				return 1;
			}
			/* Store the previous record pointer */
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNext;

		}
	}
	DPRINTF("\n\tThe  selected ID is not found. \n");
	return 0;
}

/***************************************************************************************************************/
void LL_ViewStudents(void)
{
	StudentNode_st *pCurrentStudent = gp_FirstStudent;
	uint32_t counter = 0;

	if(gp_FirstStudent == NULL)
	{
		DPRINTF("\n The List is empty. ");
	}
	while(pCurrentStudent)
	{
		DPRINTF("\n Record Number %d",counter+1);
		DPRINTF("\n\t ID : %d",pCurrentStudent->Student.ID);
		DPRINTF("\n\t Name : %s",pCurrentStudent->Student.Name);
		DPRINTF("\n\t Height : %0.2f\n",pCurrentStudent->Student.height);
		pCurrentStudent = pCurrentStudent->pNext;
		counter++;
	}
}

/***************************************************************************************************************/
void LL_DeleteAll(void)
{
	StudentNode_st *pCurrentStudent = gp_FirstStudent;

	if(gp_FirstStudent == NULL)
	{
		DPRINTF("\n The List is empty. ");
	}
	while(pCurrentStudent)
	{
		StudentNode_st *pTempStudent = gp_FirstStudent;
		pCurrentStudent = pCurrentStudent->pNext;
		free(pTempStudent);
	}
	gp_FirstStudent = NULL;
}

/***************************************************************************************************************/
void LL_GetSpecificNode(int index)
{
	/* Check if the list is empty */
	if(gp_FirstStudent == NULL || index < 0)
	{
		DPRINTF("\nThe List is Empty.\n");
	}

	StudentNode_st *pTemp = gp_FirstStudent;
	uint32_t counter = 0;

	/* Check if the first recored is null */
	while(pTemp)
	{
		if(counter == index)
		{
			DPRINTF("\n Record Index %d",index);
			DPRINTF("\n\t ID : %d",pTemp->Student.ID);
			DPRINTF("\n\t Name : %s",pTemp->Student.Name);
			DPRINTF("\n\t Height : %0.2f\n",pTemp->Student.height);
		}
		pTemp = pTemp->pNext;
		counter++;
	}
}

/***************************************************************************************************************/
int LL_Count_Students_IterativeMethod(void)
{
	// Check if the list is empty
	if(gp_FirstStudent == NULL )
	{
		DPRINTF("\nThe List is Empty.\n");
		return 0;
	}

	StudentNode_st *pTemp = gp_FirstStudent;
	uint32_t counter = 1;

	/* Looping on the list */
	while(pTemp)
	{
		if(pTemp->pNext == NULL)
		{
			break;
		}
		pTemp = pTemp->pNext;
		counter++;
	}
	return counter;
}

/***************************************************************************************************************/
int LL_Count_Students_RecursiveMethod(StudentNode_st *list)
{
	/* Check if the list is empty */
	if(gp_FirstStudent == NULL )
	{
		DPRINTF("\nThe List is Empty.\n");
		return 0;
	}

	if(list == NULL)
	{
		return 0;
	}
	else
	{
		return 1+LL_Count_Students_RecursiveMethod(list->pNext);
	}
}

/***************************************************************************************************************/
void LL_GetSpecificNode_FromEND(int index)
{
	/* Check if the list is empty */
	if(gp_FirstStudent == NULL || index < 0)
	{
		DPRINTF("\nThe List is Empty.\n");
	}

	/* Initialize main & Ref pointer to the beginning of the list */
	StudentNode_st *pMain = gp_FirstStudent;
	StudentNode_st *pRef = gp_FirstStudent;

	// Move reference pointer by the desired offset from main pointer
	for (; index-- ; pRef = pRef->pNext)
	{
		// if user input index out of scope
		if(pRef == NULL)
		{
			DPRINTF("\n failed to get node from the end\n");
			return ;
		}
	}

	// Move main & ref pointer relatively one by one
	if(pRef->pNext != NULL)
	{
		pMain = pMain->pNext;
		pRef = pRef->pNext;
	}

	DPRINTF("\n Record Index from end zero-based");
	DPRINTF("\n\t ID : %d",pMain->Student.ID);
	DPRINTF("\n\t Name : %s",pMain->Student.Name);
	DPRINTF("\n\t Height : %0.2f\n",pMain->Student.height);
}

/***************************************************************************************************************/
void LL_Get_The_Middle(void)
{
	// Check if the list is empty
	if(gp_FirstStudent == NULL)
	{
		DPRINTF("\nThe List is Empty.\n");
	}

	// Get Student Number
	int studentNumber = 0;

	// Get Number of nodes in the list
	studentNumber = LL_Count_Students_IterativeMethod();

	// Get the index we want
	LL_GetSpecificNode(studentNumber/2);
}

/***************************************************************************************************************/
void LL_Reverse_All(void)
{
	/* Initialize node for previous, current and next */
	StudentNode_st *pPreviousStudent = NULL;
	StudentNode_st *pCurrentStudent = gp_FirstStudent;
	StudentNode_st *pNextStudent = NULL;

	/* Check if the list is empty */
	if(gp_FirstStudent == NULL)
	{
		DPRINTF("\nThe List is Empty.\n");
		return;
	}

	/* if pCurrentStudent get the last node in the list */
	while(pCurrentStudent != NULL)
	{
		pNextStudent = pCurrentStudent->pNext;
		pCurrentStudent->pNext = pPreviousStudent;
		pPreviousStudent = pCurrentStudent;
		pCurrentStudent = pNextStudent;
	}

	gp_FirstStudent = pPreviousStudent;
}

/***************************************************************************************************************/
static void Fill_New_Record(StudentNode_st *NewStudent)
{
	char temp_text[NAME_LENGTH];

	DPRINTF("Enter Student ID: ");
	gets(temp_text);
	NewStudent->Student.ID = atoi(temp_text);

	DPRINTF("Enter Student Name: ");
	gets(NewStudent->Student.Name);

	DPRINTF("Enter Student Height: ");
	gets(temp_text);
	NewStudent->Student.height = atof(temp_text);
}


/***************************************************************************************************************/
