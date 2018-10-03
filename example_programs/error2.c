#include <stdio.h>

int main()
{
    int n = 5;

    // syntax error, variables cannot be declared within program
    if ( n >= 2 ) char d = 'd';

    return 0;
}