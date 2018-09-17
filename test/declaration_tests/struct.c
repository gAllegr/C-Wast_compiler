/* Example of struct creation */

struct Point
{
   int x;
   int y;
} punto1 = {1,5}, punto2, punto3[2] = {{1,2},{3,4}};

int main ()
{
	struct Line
	{
		int a;
		int b;
	} line1, line2;

	punto2.x = 10;
	punto2.y = 20;
	
	punto1.x = punto1.y * 2;

	return 0;
}
