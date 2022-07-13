/***************************************************************************
 Assignment  : EX5_C_Program_to_find_area_of_Circle_Using_macros.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 13 - 2022
****************************************************************************/

#include <stdio.h>

#define Pi 3.14

#define Area(...) 	printf ("\nArea= %.3f\n",((Pi)*__VA_ARGS__*__VA_ARGS__));

void main ()
{
	float R ;
	printf ("\nEnter the radius : ");
	scanf ("%f",&R);
	Area(R)

}

