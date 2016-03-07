#include <stdio.h>

int gcd (int a, int b){
	if (a == 0 || b == 0){
		return 0;
	}else{
		while (a%b != 0){
			b = a%b;
			//return gcd (b, a%b);
			return (a%b, b);
		}
	}
	return b;

}

int nongcd(int a, int b){
	if (a == 0 || b == 0)
		return 0;
	else {
		int tmp;
		while (a%b != 0){
			tmp = b;
			b = a%b;		
			a = tmp;
		}
		return b;
	}

	return 0;
}


int main (void){
	int a = 10, b = 4;
	int tmp;
	tmp = gcd(a, b);
	printf ("gcd is %d\n", tmp);
	tmp = nongcd(a, b);
	printf ("nongcd is %d\n", tmp);
	return 0;
}
