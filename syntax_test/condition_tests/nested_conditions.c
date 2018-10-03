/*
  This example shows how to write allowed nested conditions
  Nested condition must be writte between round braces
*/

#include <stdio.h>

int main(void) 
{
    int cond = 5;

    if ( ! (cond < 7 && cond > 3) ) printf("NOT of AND conditions\n");
    if ( ! (cond > 2 || cond < 1) ) printf("NOT of OR conditions\n");

    if ((! cond == 5) && (cond < 6)) printf("AND of a NOT cond and a simple cond\n");
    if ((cond < 7 && cond > 3) || (cond < 6)) printf("OR of a AND cond and a simple cond\n");

    if ( ! cond > 2 || cond < 1 ) printf("NOT of OR conditions\n");
    if (cond < 7 && cond > 3 || cond < 6) printf("OR of a AND cond and a simple cond\n");

    return 0;	
}
