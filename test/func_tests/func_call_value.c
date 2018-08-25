/* This is a simple example of function definition and call
Arguments can be passed only by value */

int sum(int a, int b) {
	int s = a + b;
	return s;
}

int main ()
{
	int c = 1, d = 2, somma;
	somma = sum(c,d);
}