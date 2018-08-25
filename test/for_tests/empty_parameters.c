/*
    This is a test C file to verify is compiler correctly work on FOR loop-type iteration.
    FOR loop will sum the first N numbers, with N asked to the user
    NOTE: this C file doesn't use Gauss formula
*/

#include <stdio.h>

int main (void)
{
    int N, i, sum = 0;
 
    printf("How many numbers you want to sum?\n");
    scanf("%d", &N);
 
    for ( ; i <= N ; i++)
    {
        sum = sum + i;
    }
 
    printf("Sum of numbers is %d\n", sum);
 
    return 0;
}
