/* A simple example to prove that compiler:
- prints out a simple string message
- accepts a single variable to be printed out or retrieved
- accepts more than one variable to be printed out or retrieved */

#include <stdio.h>

int a,b,c;

int main ()
{
	printf("Insert the value of the a variable: ");
	scanf("%d",&a);

	printf("Insert the value of 'b' and 'c' variables: ");
	scanf("%d %d",&b,&c);

	return 0;
}