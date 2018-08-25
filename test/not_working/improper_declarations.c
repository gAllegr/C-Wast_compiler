/* This example declares variables within the execution of the program
But variables can be declared only at the beginning of program/function */

#include <stdio.h>

int a = 0;

int main(void) 
{
    int cond = 5;
    int c = 2;

    if ( cond > 5)
    {
	if ( c >= 2 ) char d = "d";
    } else {
	char b = "b";
    }
    return 0;	
}