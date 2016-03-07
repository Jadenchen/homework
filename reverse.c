#include <stdio.h>
#include <string.h>

void reverse (char s[]){
	int i, j;
	char c;
	for (i = 0,j = strlen(s)-1; i<j;i++, j-- ){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


int main (void){
	char s[] = "hello world";	
	reverse(s);
	printf("reverse s is %s\n", s);
	return 0;
}
