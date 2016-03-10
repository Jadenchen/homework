#include <stdio.h>

void swap (int *a, int *b){
	*a = *a^*b;
	*b = *a^*b;
	*a = *b^*a;

}


int main (void){
	int a = 4;
	int b = 2;
	printf ("a = %d, b = %d\n", a,b);
	swap(&a, &b);
	printf ("a = %d, b = %d\n", a,b);
	return 0;
}
