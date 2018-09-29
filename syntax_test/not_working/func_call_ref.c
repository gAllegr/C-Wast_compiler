/* Arguments cannot be passed by reference */

void swap(int *x, int *y) {

   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
  
   return;
}

int main ()
{
	int c = 1, d = 2;
	swap(&c,&d);
}