#include <stdio.h>

// arrays can't be directly converted in WebAssembly
int numbers[5] = {1,2,3,4,5};

int main()
{
    printf("Hi!!!");
    return 0;
}