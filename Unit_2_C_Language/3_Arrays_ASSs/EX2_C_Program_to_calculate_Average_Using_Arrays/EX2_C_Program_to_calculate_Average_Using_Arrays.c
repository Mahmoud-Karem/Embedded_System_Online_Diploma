/***************************************************************************
 Assignment  : EX2_C_Program_to_calculate_Average_Using_Arrays.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 5 - 2022
****************************************************************************/

#include <stdio.h>
void main ()
{
	int i,n;
	float AVG=0,SUM=0 ;

	printf ("Enter the numbers of data: ");
	scanf  ("%i" ,&n);
	
	float Arr[n] ;

	for(i=0 ; i<n ; i++)
	{
		printf ("%i. Enter number: ",i+1);
		scanf  ("%f" ,&Arr[i]);
	}
	for(i=0 ; i<n ; i++)
	{
		SUM += Arr[i];
	}
	
	AVG = SUM/n;
	printf ("Average = %f" , AVG);

}