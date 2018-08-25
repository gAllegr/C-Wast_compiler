/*
  This example covers all possible comparison conditions allowed by compiler
*/ 

#include <stdio.h>

int main(void) 
{
    int cond = 5;

    if ( cond == 5 ) printf("Variable is equal to 5\n");
    if ( cond != 5 ) printf("Variable is not equal to 5\n"); 
    if ( cond < 5 ) printf("Variable value is less than 5\n");
    if ( cond <= 5 ) printf("Variable value is less than or equal to 5\n");
    if ( cond > 5 ) printf("Variable value is greater than 5\n");
    if ( cond >= 5 ) printf("Variable value is greater than or equal to 5\n");

    return 0;	
}
