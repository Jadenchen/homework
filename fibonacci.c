#include <stdio.h>

int fibonacci(int m){
	if (m == 1 || m ==2)
		return 1;
	else{
		return fibonacci(m-1) + fibonacci(m-2);
	}

}

int nonfibonacci (int m){

	if (m == 1 || m ==2)
		return 1;
	else{
		int tmp = 1, tmp1 = 0;
		int i, sum;
		for (i = 1; i < m ; i++){
			sum = tmp + tmp1;	
			tmp1 = tmp;
			tmp = sum;
		}		
				
		return sum;
	}
}


int main (void){

	int a = 8,  tmp;
	tmp = fibonacci(a);
	printf ("nest fibonacci is %d\n", tmp);
	tmp = nonfibonacci(a);
	printf ("non nest fibonacci is %d\n", tmp);


	return 0;
}
