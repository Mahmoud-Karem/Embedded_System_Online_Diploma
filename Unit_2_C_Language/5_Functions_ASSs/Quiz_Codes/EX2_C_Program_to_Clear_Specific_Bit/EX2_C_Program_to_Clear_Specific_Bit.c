/*********************************************************************************
 Quiz        : EX2_C_Program_to_Clear_Specific_Bit.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/

#include <stdio.h>

int CLR_Bit (int NUM , int Position);

void main ()
{
	int NUM ,Position;
	printf("Input Number = ");
	scanf ("%i",&NUM);
	printf("Bit Position = ");
	scanf ("%i",&Position);
	NUM=CLR_Bit(NUM,Position);
	printf("result = %i ",NUM);

	
}


int CLR_Bit (int NUM , int Position)
{
	NUM &= ~(1<<Position);
	return NUM;
}