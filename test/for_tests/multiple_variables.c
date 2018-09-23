/*
    This is a test C file to verify is compiler correctly work on FOR loop-type iteration.
    FOR loop will sum the first N numbers, with N asked to the user
    NOTE: this C file doesn't use Gauss formula
*/

#include <stdio.h>

int main (void)
{
    int N, i, t, sum = 0;
 
    printf("How many numbers you want to sum?\n");
    scanf("%d", &N);
 
    for (i=0 , t=10 ; i <= N ; i++, t--)
    {
        sum = sum + i;
    }
 
    printf("Sum of first %d numbers is %d\n", N, sum);

    return 0;
}
