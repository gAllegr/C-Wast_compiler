#include <stdio.h>

int main (void)
{
    int N=10, i, t, sum = 0, cond = 5;
 
    for (i=0 , t=10 ; i < N ; i++, t--)
        sum = sum + i;

    printf("Sum of first 10 number is");
    printf("%d", sum);


    if ( !cond == 5 ) printf("NOT case\n");
    else
    {
        if ( cond < 7 && cond > 3 ) printf("AND case\n");
        else if ( cond > 2 || cond < 1) printf("OR case\n");
    }   

    return 0;
}