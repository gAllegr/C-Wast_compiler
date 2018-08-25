#include <stdio.h>

int main(void) 
{
    int cond = 5;
    char a;

    if ( cond > 5)
		a = "a";
    else {
        printf ( "Variable has a value lesser then or equal to 5\n" );
    }

    return 0;	
}
