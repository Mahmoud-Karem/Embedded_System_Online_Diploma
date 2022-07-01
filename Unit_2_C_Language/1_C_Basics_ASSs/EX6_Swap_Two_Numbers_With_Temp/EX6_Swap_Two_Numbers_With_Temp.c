/***************************************************************************
 Assignment  : EX6_Swap_Two_Numbers_With_Temp.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 1 - 2022
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void main ()
{
	float NUM1 , NUM2 , Temp ;  
	
	printf ("Enter value of a: ");        
	scanf  ("%f", &NUM1 );                     
	printf ("Enter value of b: ");        
	scanf  ("%f", &NUM2 );
	printf ("\n");     
	
	Temp = NUM1 ;
	NUM1 = NUM2 ;
	NUM2 = Temp ;
	
	printf ("After swapping, value of a = %f\n",NUM1);        
	printf ("After swapping, value of b = %f\n",NUM2);        


}
