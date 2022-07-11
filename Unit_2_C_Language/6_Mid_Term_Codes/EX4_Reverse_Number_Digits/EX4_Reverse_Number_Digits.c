/*********************************************************************************
 Exam        : EX4_Reverse_Number_Digits.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/

#include <stdio.h>


int Rev_Dig(int NUM);

void main ()
{
	int NUM,Rev;
	printf("Enter a Number :");
	scanf ("%d",&NUM);
	Rev = Rev_Dig(NUM);
	printf("Reverse of Number = %d",Rev);
}

int Rev_Dig(int NUM)
{
	int Rem,Rev=0 ;
	while(NUM != 0)
	{
		Rev *= 10;
		Rem = NUM%10;
		Rev += Rem ;
		NUM /= 10 ;
	}
	return Rev ;
}
