/***************************************************************************
 Assignment  : EX5_C_Program_to_search_an_element_in_Array.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 5 - 2022
****************************************************************************/

#include <stdio.h>
#define SIZE 50
void main ()
{
	int arr[SIZE];
	
	int i,Num,Element,Loc=0;
	
	printf ("\nEnter no of elements: ");
	scanf  ("%i" ,&Num);
	
	printf ("\nEnter the elements: \n");
	for(i=0 ; i<Num ; i++)
	{
		scanf  ("%i" ,&arr[i]);
	}
	
	printf ("\nEnter the element to be searched : ");
	scanf  ("%i" ,&Element);
		
	// Search the element
	for(i=0 ; i<Num ; i++)
	{
		if (arr[i]== Element)
		{
			Loc = i+1 ;
			break;
		}	
	}
	
	if (Loc!=0)
	{
		printf ("\nNumber foud at the location = %i\n",Loc);
	}
	else
	{
		printf ("\nThe Element is Not Exist");

	}
	

	
}