/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Student_Database_Using_Queue.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *
 */ 

#include "Students_Database_Using_Queue.h"

/***********************************************************************************************************************************************/
/* Files */
FILE *students_file, *database_students_file;


/***********************************************************************************************************************************************/
/*
================================================================================================================
==================================== Private APIs Declaration  =================================================
================================================================================================================
*/
//Hint : We do not want to export them to user

static void           Print_Students_Info          (FIFO_Node_st *student                 );
static FIFO_Node_st * Search_Student_by_Roll_Number(FIFO_Buf_st  *students_queue, int roll);
/*
	Hint :
		Search_Student_by_Roll_Number --> For not to repeat the roll number
*/


/***********************************************************************************************************************************************/
/*
================================================================================================================
======================================== APIs Definition   =====================================================
================================================================================================================
*/

FIFO_Status_st Students_DB_Init(FIFO_Buf_st *students_queue, FIFO_Node_st *Node, int length)
{
	/* Validation */
	if(!students_queue || !Node || !length)
	{
		printf("Student Initialization >>> Failed\n");
		return FIFO_NULL;
	}

	/* Initialization */
	students_queue->base = Node;
	students_queue->head = students_queue->base;
	students_queue->tail = students_queue->base;
	students_queue->length = length;
	students_queue->counter = 0;

	printf("Student Initialization >>> Passed\n");
	return FIFO_NO_ERROR;
}


/***********************************************************************************************************/

void Add_Student_From_File(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st new_student;
	int i;

	/* Open a file --> read */
	students_file = fopen("students_file.txt", "r");

	/* Check if the file is not empty */
	if(students_file == NULL)
	{
		printf("\n [ERROR] students_file.txt file is empty. \n");
		printf("\n [ERROR] Adding students from file >>> failed. \n");
		return;
	}

	/* Reading from file until eof = End Of File */
	while(!feof(students_file))
	{
		/* Reading roll number */
		fscanf(students_file, "%d", &new_student.roll_number);

		/* Check if the roll number is exist */
		if(Search_Student_by_Roll_Number(students_queue, new_student.roll_number) != NULL)
		{
			/* Error ... reapeated Roll Number */
			printf("\n[ERROR] Roll number %d is already taken\n", new_student.roll_number);

			/* Ignore the rest of the line --> because this roll numberis taken */
			fscanf(students_file, "%*[^\n]");

			continue;
		}

		/* Reading data >>> first name, last name and GPA */
		fscanf(students_file, "%s", new_student.first_name);
		fscanf(students_file, "%s", new_student.last_name);
		fscanf(students_file, "%f", &new_student.GPA);

		/* Reading course IDs */
		for (i = 0; i < COURSES_NUMBER; ++i)
		{
			fscanf(students_file, "%d", &new_student.course_id[i]);
		}

		/* Enqueue a new student */
		if((FIFO_enqueue(students_queue, new_student))== FIFO_NO_ERROR)
		{
			printf("\n[INFO] Roll number %d is saved successfully\n", new_student.roll_number);
		}
		else
		{
			printf("\n[ERROR] Adding students by file failed\n");
			return;
		}
	}

	printf("\n[INFO] Students details are saved successfully\n");

	/* Close the file */
	fclose(students_file);
}


/***********************************************************************************************************/

// Enter student data manually from console
void Add_Student_Manualy(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st new_student;
	int i;

	printf("\n=== Enter student data ===\n");
	printf("\tEnter roll number: ");
	scanf("%d", &new_student.roll_number);

	// Scan if the roll number which entered is exist
	if(Search_Student_by_Roll_Number(students_queue, new_student.roll_number))
	{
		printf("\n[ERROR] Roll number %d is already taken\n", new_student.roll_number);
		printf("\n[ERROR] Adding student manually failed\n");
		return;
	}

	// If not, Continue reading other data
	printf("\tEnter first name: ");
	scanf("%s", new_student.first_name);

	printf("\tEnter second name: ");
	scanf("%s", new_student.last_name);

	printf("\tEnter GPA: ");
	scanf("%f", &new_student.GPA);

	printf("\tEnter Courses IDs\n");
	for (i = 0; i < COURSES_NUMBER; ++i)
	{
		printf("\t\tEnter Courses no.%d: ",i+1);
		scanf("%d", &new_student.course_id[i]);
	}

	// Add new student
	if(FIFO_enqueue(students_queue, new_student) == FIFO_NO_ERROR)
	{
		printf("\n[INFO] Student details us saved successfully\n");
	}
	else
	{
		printf("\n[ERROR] Adding students manually failed\n");
		return;
	}
}


/***********************************************************************************************************/

void Find_Student_by_Roll_Number_Number(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st *student;
	FIFO_Status_st queue_status;
	/* Check >>> the queue is empty */
	queue_status = FIFO_is_empty(students_queue);
	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Find student by roll number failed\n");
		return;
	}
	
	int roll_number;
	printf("\nEnter roll number: ");
	scanf("%d", &roll_number);

	/* Scan the queue to find the roll number */
	student = Search_Student_by_Roll_Number(students_queue, roll_number);

	/* Check >>> roll number is found */
	if (student == NULL)
	{
		printf("\n[ERROR] Roll number %d in not found\n", roll_number);
		return;
	}
	else
	{
		/* If we found the roll number >>> print the data */
		Print_Students_Info(student);
	}
}


/***********************************************************************************************************/

void Find_Student_by_FirstName(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st *student = students_queue->tail;
	char input_name[NAME_LENGTH], i;

	FIFO_Status_st queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Find student by first name failed\n");
		return;
	}

	printf("\nEnter First Name: ");
	scanf("%s",input_name);

	/* Loop on the queue */
	for (i = 0; i < students_queue->counter; ++i)
	{
		/* Compare between each input name and all names in queue */
		if (!(strcmp(input_name, student->first_name)))
		{
			Print_Students_Info(student);
			return;
		}
		else
		{
			printf("\n[ERROR] %s in not found\n",input_name);
			return;
		}

		/* Check if we reach the last Node in the queue */
		if((student +1) == (students_queue->base + students_queue->length))
		{
			/* Set to the start */
			student = students_queue->base;
		}
		else
		{
			/* go to the next tail */
			student++;
		}
	}
}


/***********************************************************************************************************/

void Find_Student_by_Course(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st *student;
	int input_id, i, j, number_enroled_student = 0;

	FIFO_Status_st queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Find student by course failed\n");
		return;
	}

	/* Get the ID that you want to search about */
	printf("\nEnter Course ID: ");
	scanf("%d", &input_id);

	/* Loop on the queue */
	student = students_queue->tail;
	for (i = 0; i < students_queue->counter; ++i)
	{
		/* Scan inside every Node */
		for(j = 0; j < COURSES_NUMBER; ++j)
		{
			/* Search for this ID */
			if(student->course_id[j] == input_id)
			{
				Print_Students_Info(student);
				number_enroled_student++;
				printf("\n");
				break;
			}
		}

		/* Check if we reach the last Node in the queue */
		if((student +1) == (students_queue->base + students_queue->length))
		{
			/* Set to the start */
			student = students_queue->base;
		}
		else
		{
			/* go to the next tail */
			student++;
		}
	}

	/* Check if it is not found in any student */
	if(number_enroled_student == 0)
	{
		printf("\n[ERROR] Course id %d is not found\n", input_id);
	}
	else
	{
		printf("\n[INFO] Total number of students enrolled: %d\n", number_enroled_student);
	}
}


/***********************************************************************************************************/

void Print_Students_Count(FIFO_Buf_st *students_queue)
{
	int counter = students_queue->counter;
	int capacity = students_queue->length;

	printf("[INFO] Total number of students is %d\n", counter);
	printf("[INFO] You can add up to %d students\n", capacity);
	printf("[INFO] You can add %d more students\n", capacity - counter);

}


/***********************************************************************************************************/

void Delete_Student_by_Roll_Number(FIFO_Buf_st *students_queue)
{
	int roll_number, i, flag = 0;
	FIFO_Node_st *student;

	FIFO_Status_st queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Delete student by roll number failed\n");
		return;
	}

	/* Enter roll number you want to delete */
	printf("\nEnter roll number: ");
	scanf("%d", &roll_number);

	student = students_queue->base;
	/* Loop on the queue */
	for (i = 0; i < students_queue->counter; ++i)
	{
		if(student->roll_number == roll_number)
		{
			/* Deleting student */
			*student = *(students_queue->tail);

			/* Update counter of queue */
			students_queue->counter--;

			/* Check if we reach the last Node in the queue */
			if((students_queue->tail + 1) == (students_queue->base + students_queue->length))
			{
				/* Set to the start */
				students_queue->tail = students_queue->base;
			}
			else
			{
				/* go to the next tail */
				students_queue->tail++;
			}

			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
		student++;
	}

	if(flag == 1)
	{
		printf("\n[INFO] The Roll Number is removed successfully\n");
	}
	else
	{
		printf("\n[ERROR] This Roll Number %d not found\n",roll_number);
	}
}


/***********************************************************************************************************/

void Update_Student_by_Roll_Number(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st *update_student, *student;
	int i, input_roll , input_option, input_new_roll, flag = 0;

	FIFO_Status_st queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Delete student by roll number failed\n");
		return;
	}

	/* Enter roll number you want to update */
	printf("\nEnter roll number: ");
	scanf("%d", &input_roll);

	/* Search about the input roll to get its whole Node */
	update_student = Search_Student_by_Roll_Number(students_queue, input_roll);

	/* Check if we find roll number in the queue */
	if (update_student == NULL)
	{
		printf("\n[ERROR] Roll number %d in not found\n", input_roll);
		return;
	}
	else
	{
		/* If we found the roll number lets print all data */
		printf("\n==== Student data ====\n");
		Print_Students_Info(update_student);
	}

	printf("\nWhich date do you want to change ?\n");
	printf("\t 1: The Roll Number\n");
	printf("\t 2: The First Name\n");
	printf("\t 3: The Second Name\n");
	printf("\t 4: The GPA Score\n");
	printf("\t 5: The Courses ID\n");
	printf("Enter your option: ");

	/* Get the option */
	scanf("%d",&input_option);
	switch (input_option)
	{
		case 1:
			printf("Enter the new roll number: ");
			scanf("%d",&input_new_roll);

			student = students_queue->tail;
			/* Loop inside the queue */
			for (i = 0; i < students_queue->counter; ++i)
			{
				/* Check if we find the the roll we search about to break */
				if (student->roll_number == input_new_roll)
				{
					/* Get out form for loop */
					printf("\n[ERROR] This Roll Number %d is exist\n",input_new_roll);

					/* If we find a roll number match set flag */
					flag = 1;
					break;
				}

				/* Check if we reach the last Node in the queue */
				if((student + 1) == (students_queue->base + students_queue->length))
				{
					student = students_queue->base;
				}
				else
				{
					/* go to the next tail */
					student++;
				}
			}

			// If the flag doesn't changed this mean that no roll number match
			if(flag == 0)
			{
				update_student->roll_number = input_new_roll;
				printf("\n[INFO] The Roll Number %d in updated successfully\n", input_new_roll);
			}
			break;

		case 2:
			printf("Enter the new first name: ");
			scanf("%s", update_student->first_name);
			printf("\n[INFO] The First Name %s in updated successfully\n",update_student->first_name);
			break;

		case 3:
			printf("Enter the new last name: ");
			scanf("%s", update_student->last_name);
			printf("\n[INFO] The Last Name %s in updated successfully\n",update_student->last_name);
			break;

		case 4:
			printf("Enter the new GPA: ");
			scanf("%f", &update_student->GPA);
			printf("\n[INFO] The GPA Score %0.1f in updated successfully\n", update_student->GPA);
			break;

		case 5:
			printf("Enter the course number from %d to %d: ", 1, COURSES_NUMBER);
			scanf("%d", &input_option);
			printf("Enter the new course id: ");
			scanf("%d", &update_student->course_id[input_option - 1]);
			printf("\n[INFO] The Course ID %d in updated successfully\n", update_student->course_id[input_option - 1]);
			break;

		default:
			break;
	}
}


/***********************************************************************************************************/

void Update_DataBase_Students(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st *student;
	int i, j;

	// Opening a DataBase_Students.txt file with w option to write in it
	database_students_file = fopen("DataBase_Students.txt", "w");

	// Check if the file exist and there is data or not
	if(students_file == NULL)
	{
		printf("\n [ERROR] DataBase_Students.txt create failed. \n");
		printf("\n [ERROR] update students file failed. \n");
		return;
	}

	student = students_queue->tail;
	// Loop inside the queue
	for (i = 0; i < students_queue->counter; ++i)
	{
		// Write into file
		fprintf(database_students_file, "%d ", student->roll_number);
		fprintf(database_students_file, "%s ", student->first_name);
		fprintf(database_students_file, "%s ", student->last_name);
		fprintf(database_students_file, "%0.1f ", student->GPA);

		for(j = 0; j < COURSES_NUMBER ; ++j)
		{
			fprintf(database_students_file, "%d ", student->course_id[j]);
		}

		// New line after every FIFO_Node_st
		fprintf(database_students_file, "\n");

		/* Check if we reach the last Node in the queue */
		if((student + 1) == (students_queue->base + students_queue->length))
		{
			student = students_queue->base;
		}
		else
		{
			/* go to the next tail */
			student++;
		}

	}
	printf("\n[INFO] Update Students details are saved in file successfully\n");

	// Closing the file
	fclose(database_students_file);
}


/***********************************************************************************************************/

void Add_Student_From_DataBase_File(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st new_student;
	int i;

	// Opening a DataBase_Students.txt file with option read
	database_students_file = fopen("DataBase_Students.txt", "r");

	// Check if the file exist and there is data or not
	if(database_students_file == NULL)
	{
		printf("\n [ERROR] database_students_file.txt file not found. \n");
		printf("\n [ERROR] adding students from update file failed. \n");
		return;
	}

	// Reading students until end of file this using of feof == Check end of file
	while(!feof(database_students_file))
	{
		// Reading roll number of the student
		fscanf(database_students_file, "%d", &new_student.roll_number);

		// Check if the roll number is exists
		if(Search_Student_by_Roll_Number(students_queue, new_student.roll_number) != NULL)
		{
			/* Error ... reapeated Roll Number */
			printf("\n[ERROR] Roll number %d is already taken\n", new_student.roll_number);

			/* Ignore the rest of the line --> because this roll numberis taken */
			fscanf(database_students_file, "%*[^\n]");

			continue;
		}

		/* Reading data >>> first name, last name and GPA */
		fscanf(database_students_file, "%s", new_student.first_name);
		fscanf(database_students_file, "%s", new_student.last_name);
		fscanf(database_students_file, "%f", &new_student.GPA);

		/* Reading course IDs */
		for (i = 0; i < COURSES_NUMBER; ++i)
		{
			fscanf(database_students_file, "%d", &new_student.course_id[i]);
		}

		/* Enqueue a new student */
		if((FIFO_enqueue(students_queue, new_student))== FIFO_NO_ERROR)
		{
			printf("\n[INFO] Roll number %d is saved successfully\n", new_student.roll_number);
		}
		else
		{
			printf("\n[ERROR] Adding students by update file failed\n");
			return;
		}
	}

	printf("\n[INFO] Students Recover are saved successfully\n");

	/* Close the file */
	fclose(database_students_file);
}


/***********************************************************************************************************/

void Show_Students_Info(FIFO_Buf_st *students_queue)
{
	FIFO_Node_st *student;
	char i;
	FIFO_Status_st queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_empty(students_queue);
	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Show students info failed\n");
		return;
	}

	printf("\nAll Students\n\n");

	student = students_queue->tail;
	for (i = 0; i < students_queue->counter; ++i)
	{
		Print_Students_Info(student);
		printf("\n");

		/* Check if we reach the last Node in the queue */
		if((student + 1) == (students_queue->base + students_queue->length))
		{
			student = students_queue->base;
		}
		else
		{
			/* go to the next tail */
			student++;
		}
	}
}


/***********************************************************************************************************/

FIFO_Status_st FIFO_enqueue(FIFO_Buf_st *fifo_buf, FIFO_Node_st Node)
{
	/* Check parameters validity */
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		printf("FIFO Enqueue failed: Null is passed\n");

		return FIFO_NULL;
	}

	/* Check if FIFO is Full */
	if((FIFO_is_full(fifo_buf)) == FIFO_FULL)
	{
		printf("FIFO Enqueue failed: FIFO is full\n");

		return FIFO_FULL;
	}

	/* Enqueue new Node */
	*(fifo_buf->head) = Node;

	if((fifo_buf->head + 1) == (fifo_buf->base + fifo_buf->length)) // Check if the head in the end of fifo to start over
	{
		fifo_buf->head = fifo_buf->base;
	}
	else
	{
		fifo_buf->head++;
	}

	fifo_buf->counter++;

	return FIFO_NO_ERROR;
}


/***********************************************************************************************************/

FIFO_Status_st FIFO_is_full(FIFO_Buf_st *fifo_buf)
{
	/* validation */
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		printf("FIFO is full failed: Null is passed\n");

		return FIFO_NULL;
	}

	/* Check if the number of Nodes matches the total buffer length */
	if(fifo_buf->counter == fifo_buf->length)
	{
		return FIFO_FULL;
	}

	return FIFO_NOT_FULL;
}


/***********************************************************************************************************/

FIFO_Status_st FIFO_is_empty(FIFO_Buf_st *fifo_buf)
{
	/* validation */
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		printf("FIFO is empty failed: Null is passed\n");

		return FIFO_NULL;
	}

	/* Check if the number of Nodes is zero */
	if(fifo_buf->counter == 0)
	{
		return FIFO_EMPTY;
	}

	return FIFO_NOT_EMPTY;
}


/***********************************************************************************************************************************************/
/*
================================================================================================================
==================================== Private APIs Definition ===================================================
================================================================================================================
*/

static void Print_Students_Info(FIFO_Node_st *student)
{
	int i;

	printf("The student details are\n");
	printf("\tFirst Name: %s\n", student->first_name);
	printf("\tLast Name: %s\n", student->last_name);
	printf("\tRoll Number: %d\n", student->roll_number);
	printf("\tGPA: %0.1f\n", student->GPA);
	printf("\tCourses IDs are\n");

	for(i = 0; i < COURSES_NUMBER; i++)
	{
		printf("\t\tCourse %d id: %d\n", i + 1, student->course_id[i]);
	}
}


/***********************************************************************************************************/

static FIFO_Node_st *Search_Student_by_Roll_Number(FIFO_Buf_st *students_queue, int roll)
{
	int i ;
	FIFO_Node_st *student = students_queue->tail;

	/* Loop inside the queue */
	for (i = 0; i < students_queue->counter; ++i)
	{
		if (student->roll_number == roll)
		{
			break;
		}

		if((student + 1) == (students_queue->base + students_queue->length))
		{
			student = students_queue->base;
		}
		else
		{
			student++;
		}
	}

	if(i == students_queue->counter)
	{
		student = NULL;
	}

	return student;
}


/***********************************************************************************************************************************************/

