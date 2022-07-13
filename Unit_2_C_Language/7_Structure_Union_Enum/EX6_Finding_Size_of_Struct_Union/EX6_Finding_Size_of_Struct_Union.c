/***************************************************************************
 Assignment  : EX6_Finding_Size_of_Struct_Union.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 13 - 2022
****************************************************************************/
#include <stdio.h>

union job
{
	char name [32] ;
	float salary;
	int worker_no;

}u;

struct job1
{
	char name [32];
	float salary;
	int worker_no;

}s;


int main ()
{
	printf ("Size of the union is: %d", sizeof (u));
	printf ("\nSize of the structure is: %d", sizeof (s));

	return 0;
}

/****************************************************************************
*********           " OUTPUT "                                   ************
*********                                                        ************
*********  Size of the union is: 32                              ************
*********  Size of the structure is: 40                          ************
*********                                                        ************
*********  $ Note:                                               ************
*********       Size of union = size of the largest member       ************
*********                                                        ************
*********                                                        ************
****************************************************************************/
