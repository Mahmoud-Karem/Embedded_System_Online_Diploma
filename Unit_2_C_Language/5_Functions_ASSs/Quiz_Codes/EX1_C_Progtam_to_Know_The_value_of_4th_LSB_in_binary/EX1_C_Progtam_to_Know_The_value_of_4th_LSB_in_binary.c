/*********************************************************************************
 Assignment  : EX1_C_Progtam_to_Know_The_value_of_4th_LSB_in_binary.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/

#include <stdio.h>

int Get_4th_LSB (int NUM);

void main ()
{
	int NUM ;
	int Bit ;
	printf("Enter a number: ");
	scanf ("%i",&NUM);
	Bit = Get_4th_LSB(NUM);
	printf("The 4th LSB is : %i ",Bit);

	
}


int Get_4th_LSB (int NUM)
{
	return ((NUM>>3)&1);
}