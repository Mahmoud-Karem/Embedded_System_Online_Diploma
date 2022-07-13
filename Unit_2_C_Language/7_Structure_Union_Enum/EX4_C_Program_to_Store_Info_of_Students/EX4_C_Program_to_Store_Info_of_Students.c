/***************************************************************************
 Assignment  : EX4_C_Program_to_Store_Info_of_Students.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 13 - 2022
****************************************************************************/

#include <stdio.h>

struct S_Info 
{
	char Name[50];
	int Roll;
	float Marks;
};

struct S_Info Get_Student(struct S_Info S_Student );
void Dis_Student(struct S_Info S_Student );


void main ()
{
	struct S_Info Arr_S_Student[10];
	int i;
	
	for (i=0 ; i<10 ;i++)
	{
		Arr_S_Student[i]=Get_Student(Arr_S_Student[i]);
		fflush(stdin); fflush(stdout);

	}
	
	for (i=0 ; i<10 ;i++)
	{
		Dis_Student(Arr_S_Student[i]);
	}
	

}


struct S_Info Get_Student(struct S_Info S_Student )
{
	printf ("\nEnter Information of the student : \n");
	
	printf ("Enter Name: ");
	gets (S_Student.Name);

	printf ("Enter Roll Number: ");
	scanf ("%d",&S_Student.Roll);

	printf ("Enter Marks: ");
	scanf ("%f",&S_Student.Marks);
	
	return S_Student ;
}

void Dis_Student(struct S_Info S_Student )
{
	printf ("\nDisplay Info :- \n");
	printf ("Name: %s\n",S_Student.Name);
	printf ("Roll: %d\n",S_Student.Roll);
	printf ("Marks: %.1f\n",S_Student.Marks);
}