/*********************************************************************************
 Quiz        : EX7_Swapping_two_arrays_with_Different_length.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/
#include <stdio.h>
#define SIZE 50

void	Swap (int Arr1[],int Arr2[]);


void main ()
{
	int Arr1[SIZE] ,Arr2[SIZE];
	
	int i,Num1,Num2,Min,MAX;
	
	printf ("\nEnter no of elements for 1st array: ");
	scanf  ("%i" ,&Num1);
	
	printf ("\nEnter the elements: \n");
	for(i=0 ; i<Num1 ; i++)
	{
		scanf  ("%i" ,&Arr1[i]);
	}
	
	printf ("\nEnter no of elements for 2nd array: ");
	scanf  ("%i" ,&Num2);
	
	printf ("\nEnter the elements: \n");
	for(i=0 ; i<Num2 ; i++)
	{
		scanf  ("%i" ,&Arr2[i]);
	}
	
	MAX = (Num1>Num2)?Num1:Num2;
	Min = (Num1<Num2)?Num1:Num2;

	
	//Swaping
	for(i=0 ; i<MAX ; i++)
	{
		if (i<Min)
		{
			Arr1[i] = Arr1[i] ^ Arr2[i] ;
			Arr2[i] = Arr1[i] ^ Arr2[i] ;
			Arr1[i] = Arr1[i] ^ Arr2[i] ;
		}
		else if (i>=Num1)
		{
			Arr1[i]=Arr2[i];
		}
		else if (i>=Num2)
		{
			Arr2[i]=Arr1[i];
		}

		
		
	}
	
	printf ("\nAfter Swapping: \n");

	printf ("\n1st Array is : ");
	for(i=0 ; i<Num2 ; i++)
	{
		printf  ("%i\t" ,Arr1[i]);
	}
	
	printf ("\n2nd Array is : ");
	for(i=0 ; i<Num1 ; i++)
	{
		printf  ("%i\t" ,Arr2[i]);
	}
	printf ("\n");
}
