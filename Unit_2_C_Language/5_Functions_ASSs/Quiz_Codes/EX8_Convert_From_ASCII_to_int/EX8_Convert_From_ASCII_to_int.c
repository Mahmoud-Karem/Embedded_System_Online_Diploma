/*********************************************************************************
 Quiz        : EX8_Convert_From_ASCII_to_int.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void main ()
{
	char String[SIZE];
	int Num;
	
	printf ("\nEnter an Array of Numbers(0:9): ");
	gets(String);
	
	Num = atoi(String);
	
	
	printf ("\nYour Integer is : %i",Num);
}