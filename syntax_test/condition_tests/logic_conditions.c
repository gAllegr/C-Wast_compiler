/*
  This example shows what kind of logical operators can be used with simple conditions
*/ 

#include <stdio.h>

int main(void) 
{
    int cond = 5;

    if ( !cond == 5 ) printf("NOT case\n");

    if ( cond < 7 && cond > 3 ) printf("AND case\n");

    if ( cond > 2 || cond < 1) printf("OR case\n");

    return 0;	
}
