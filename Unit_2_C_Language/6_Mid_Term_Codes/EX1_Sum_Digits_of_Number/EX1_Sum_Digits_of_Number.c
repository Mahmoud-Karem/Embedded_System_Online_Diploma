/*********************************************************************************
 Exam        : EX1_Sum_Digits_of_Number.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/

#include <stdio.h>


int Sum_Dig(int NUM);

void main ()
{
	int NUM,Sum;
	printf("Enter a Number :");
	scanf ("%d",&NUM);
	Sum = Sum_Dig(NUM);
	printf("Sum of digits = %d",Sum);
}

int Sum_Dig(int NUM)
{
	int Rem,Sum ;
	while(NUM != 0)
	{
		Rem = NUM%10;
		Sum += Rem ;
		NUM /= 10 ;
	}
	return Sum ;
}
