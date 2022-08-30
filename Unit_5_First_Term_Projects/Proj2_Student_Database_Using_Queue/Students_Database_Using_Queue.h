/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Student_Database_Using_Queue.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *
 */ 

#ifndef STUDENTS_DB_H_
#define STUDENTS_DB_H_

/***********************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
#define COURSES_NUMBER 5

/***********************************************************************************************************************************************/

typedef struct
		{
			char first_name[NAME_LENGTH];
			char last_name[NAME_LENGTH];
			int roll_number;
			float GPA;
			int course_id[COURSES_NUMBER];
		}FIFO_Node_st;

/***********************************************************************************************************************************************/

typedef struct
		{
			FIFO_Node_st *base;
			FIFO_Node_st *head;
			FIFO_Node_st *tail;
			int length;
			int counter;
		}FIFO_Buf_st;

typedef enum 
		{
			FIFO_NO_ERROR,
			FIFO_FULL,
			FIFO_NOT_FULL,
			FIFO_EMPTY,
			FIFO_NOT_EMPTY,
			FIFO_NULL
		}FIFO_Status_st;

/***********************************************************************************************************************************************/



FIFO_Status_st Students_DB_Init                     ( FIFO_Buf_st *students_queue, FIFO_Node_st *FIFO_Node_st, int length  );
void           Add_Student_From_File                ( FIFO_Buf_st *students_queue                                          );
void           Add_Student_From_DataBase_File       ( FIFO_Buf_st *students_queue                                          );
void           Add_Student_Manualy                  ( FIFO_Buf_st *students_queue                                          );
void           Find_Student_by_Roll_Number_Number   ( FIFO_Buf_st *students_queue                                          );
void           Find_Student_by_FirstName            ( FIFO_Buf_st *students_queue                                          );
void           Find_Student_by_Course               ( FIFO_Buf_st *students_queue                                          );
void           Print_Students_Count                 ( FIFO_Buf_st *students_queue                                          );
void           Delete_Student_by_Roll_Number        ( FIFO_Buf_st *students_queue                                          );
void           Update_Student_by_Roll_Number        ( FIFO_Buf_st *students_queue                                          );
void           Update_DataBase_Students             ( FIFO_Buf_st *students_queue                                          );
void           Show_Students_Info                   ( FIFO_Buf_st *students_queue                                          );
FIFO_Status_st FIFO_enqueue                         ( FIFO_Buf_st *fifo_buf, FIFO_Node_st FIFO_Node_st                     );
FIFO_Status_st FIFO_is_full                         ( FIFO_Buf_st *fifo_buf                                                );
FIFO_Status_st FIFO_is_empty                        ( FIFO_Buf_st *fifo_buf                                                );


/***********************************************************************************************************************************************/


#endif /* STUDENTS_DB_H_ */
