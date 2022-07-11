/*********************************************************************************
 Exam        : EX8_Reverse_an_Array.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/
#include <stdio.h>
void main ()
{
	int  Counter=0 ;	
	int i,n;

	printf ("Enter the numbers of elements: ");
	scanf  ("%i" ,&n);
	
	int Arr[n] ;
	int Arr_Rev[n] ;

	for(i=0 ; i<n ; i++)
	{
		printf ("%i. Enter number: ",i+1);
		scanf  ("%i" ,&Arr[i]);
	}
	

	while (Counter < n)
	{
		Arr_Rev[n-Counter-1] = Arr[Counter];
		Counter++;
	}
	
	Counter=0;
	
	printf ("\nReverse Array is : ");
	while (Counter < n)
	{
		printf ("%i ",Arr_Rev[Counter]);
		Counter++;
	}
	printf ("\n");
}