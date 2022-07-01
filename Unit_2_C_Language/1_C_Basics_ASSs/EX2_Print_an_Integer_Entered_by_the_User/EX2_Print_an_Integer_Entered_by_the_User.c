/***************************************************************************
 Assignment  : EX2_Print_an_Integer_Entered_by_the_User.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 1 - 2022
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void main ()
{
	int i ;                                // define an Integer
	printf ("Enter an integer: ");        
	scanf ("%i", &i );                     // Scanning from the user
	printf ("You entered: %i\n", i );      // Printing the value
}