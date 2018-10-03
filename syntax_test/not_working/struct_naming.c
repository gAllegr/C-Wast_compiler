/* Typedef keyword would allow to define a new type of variable
In this case, we could have defined a type variable p
This compiler, however, does not recognize and use typedef keyword */

typedef struct Point
{
   int x, y;
} p;
 
int main () {
	p point1, point2;
}
