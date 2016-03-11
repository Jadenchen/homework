#include <stdio.h>

void swap (int *a, int *b){
	*a = *a^*b;
	*b = *a^*b;
	*a = *b^*a;

}


void strreverse(char *s){

 	char *p = s;
	while (p && *p)
		++p;
	for (--p; s < p; ++s, --p){
		*s = *s^*p;
		*p = *s^*p;
		*s = *p^*s;
	}
}

int main (void){
	int a = 4;
	int b = 2;
	printf ("a = %d, b = %d\n", a,b);
	swap(&a, &b);
	printf ("a = %d, b = %d\n", a,b);
	
	char s[] = "ABCDEF";
	printf ("s is %s\n",s);
	strreverse(s);
	printf("reverse s is %s\n", s);

	return 0;
}
