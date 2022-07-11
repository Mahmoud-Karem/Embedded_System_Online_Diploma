/*********************************************************************************
 Exam        : EX5_Count_Ones_In_Binary_Number.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/

#include <stdio.h>


int Count_Ones(int NUM);

void main ()
{
	int NUM,C;
	printf("Enter a Number :");
	scanf ("%d",&NUM);
	C = Count_Ones(NUM);
	printf("Number of ones = %d",C);
}

int Count_Ones(int NUM)
{
	int Rem,C ;
	while(NUM != 0)
	{
		Rem = NUM%2;
		if (Rem==1) C++;
		NUM /= 2 ;
	}
	return C ;
}
