/***************************************************************************
 Assignment  : EX1_C_Program_to_Store_Info_of_Student_Using_Struct.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 13 - 2022
****************************************************************************/

#include <stdio.h>

struct S_Info 
{
	char Name[50];
	int Roll;
	float Marks;
}S_Student;

void main ()
{
	printf ("\nEnter Information of the student : \n");
	
	printf ("Enter Name: ");
	gets (S_Student.Name);

	printf ("Enter Roll Number: ");
	scanf ("%d",&S_Student.Roll);

	printf ("Enter Marks: ");
	scanf ("%f",&S_Student.Marks);
	
	printf ("\nDisplay Info :- \n");
	printf ("Name: %s\n",S_Student.Name);
	printf ("Roll: %d\n",S_Student.Roll);
	printf ("Marks: %.1f\n",S_Student.Marks);

}

