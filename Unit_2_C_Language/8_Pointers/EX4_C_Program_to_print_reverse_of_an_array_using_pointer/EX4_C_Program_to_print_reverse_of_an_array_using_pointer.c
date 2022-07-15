/***************************************************************************
 Assignment  : EX4_C_Program_to_print_reverse_of_an_array_using_pointer.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 15 - 2022
****************************************************************************/

#include <stdio.h>

#define SIZE 15

void main ()
{
	int *ptr = NULL;
	int i,n;
	
	printf ("\n--------------------------------------------");
	printf ("\nEnter the numbers of elements(max 15) : ");
	scanf  ("%i" ,&n);
	
	int Arr[n] ;
	ptr=Arr+n-1;

	for(i=0 ; i<n ; i++)
	{
		printf ("%i. Enter number: ",i+1);
		scanf  ("%i" ,&Arr[i]);
	}
	printf ("--------------------------------------------");
	printf ("\nReverse of the array is : ");
	for (i=n ; i>0 ; i--)
	{
		printf ("%i\t",*ptr);
		ptr--;
	}
	printf ("\n--------------------------------------------");

}

