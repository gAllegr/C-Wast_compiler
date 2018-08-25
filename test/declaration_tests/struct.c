/* Example of struct creation */

struct Point
{
   int x;
   int y;
} punto1, punto2[3];
 
int main ()
{
	struct Point punto = {1,5};

	punto.x = punto.y * 2;

	return 0;
}