/*********************************************************************************
 Quiz        : EX6_return_index_of_last_element_of_Number.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/

#include <stdio.h>
#define SIZE 50
int Search_Last_Element (int arr[] , int Num , int Element );
void main ()
{
	int arr[SIZE];
	
	int i,Num,Element,Index;
	
	printf ("\nEnter no of elements: ");
	scanf  ("%i" ,&Num);
	
	printf ("\nEnter the elements: ");
	for(i=0 ; i<Num ; i++)
	{
		scanf  ("%i" ,&arr[i]);
	}
	
	printf ("\nEnter the element to be searched : ");
	scanf  ("%i" ,&Element);
		
	Index = Search_Last_Element(arr,Num,Element);
	if (Index!=0)
	{
		printf ("\nNumber found at the location = %i\n",Index);
	}
	else
	{
		printf ("\nThe Element is Not Exist");

	}

	
}

int Search_Last_Element (int arr[] , int Num , int Element )
{
	// Search the element
	int i , Loc=0 ;
	for(i=0 ; i<Num ; i++)
	{
		if (arr[i]== Element)
		{
			Loc = i+1 ;
		
		}	
	}
	return (Loc-1);
	
}