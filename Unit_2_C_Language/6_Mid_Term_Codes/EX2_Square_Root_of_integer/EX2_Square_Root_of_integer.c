/*********************************************************************************
 Exam        : EX2_Square_Root_of_integer.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/

#include <stdio.h>

#include <math.h>

void main()
{
    double NUM, S_Root;

    printf("Enter a Number: ");
    scanf("%lf",&NUM);
	
    S_Root = sqrt(NUM);
	
    printf("Square root of %.4lf = %.4lf", NUM, S_Root);
}