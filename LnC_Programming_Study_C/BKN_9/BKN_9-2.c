#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Fibonacci_sequence(int);

int main(void) {
	int n;
	scanf("%d", &n);

	printf("%d", Fibonacci_sequence(n));

}


/*
int Fibonacci_sequence(int n) {
	int i, a=0, b=1,res=0;
	
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	for (i =2; i <= n; i++) {
		res = a + b;
		a = b;
		b = res;
	}
	return res;

}
*/

int Fibonacci_sequence(int n) {
	if (n == 1) {
		return 1;
	}
	if (n <= 0) {
		return 0;
	}
	return Fibonacci_sequence(n - 1)+Fibonacci_sequence(n-2);
}