/*********************************************************************************
 Exam        : EX6_Unique_Number_in_Array.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/

#include <stdio.h>



void main ()
{
	int i,n;
	
	printf ("Enter the number of elements: ");
	scanf  ("%i" ,&n);
	
	int Arr[n] , NUM ;

	for(i=0 ; i<n ; i++)
	{
		printf ("%i. Enter number: ",i+1);
		scanf  ("%i" ,&Arr[i]);
	}
	
	NUM = Arr[0];
	
	for(i=1 ; i<n ; i++)
	{
		NUM ^= Arr[i];
	}
	

	printf("The unrepeated element is %i",NUM);
}
