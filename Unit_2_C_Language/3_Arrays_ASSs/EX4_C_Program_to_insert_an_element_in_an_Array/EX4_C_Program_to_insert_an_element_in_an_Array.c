/***************************************************************************
 Assignment  : EX4_C_Program_to_insert_an_element_in_an_Array.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 5 - 2022
****************************************************************************/

#include <stdio.h>
#define SIZE 50
void main ()
{
	int arr[SIZE];
	
	int i,Num,Element,Loc;
	
	printf ("\nEnter no of elements: ");
	scanf  ("%i" ,&Num);
	
	printf ("\nEnter the elements: \n");
	for(i=0 ; i<Num ; i++)
	{
		scanf  ("%i" ,&arr[i]);
	}
	
	printf ("\nEnter the element to be inserted : ");
	scanf  ("%i" ,&Element);
	
	printf ("\nEnter the location : ");
	scanf  ("%i" ,&Loc);
	
	// Insert the element
	for(i=Num-1 ; i>=(Loc-1) ; i--)
	{
		arr[i+1]=arr[i];
	}
	arr[Loc-1]=Element;
	
	for(i=0 ; i<Num+1 ; i++)
	{
		printf ("%i ",arr[i]);
	}
	
	
}