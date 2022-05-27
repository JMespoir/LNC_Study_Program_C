#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int factorial_1(int);
int factorial_2(int);

int main(void) {
	int N;
	scanf("%d", &N);

	printf("%d", factorial_1(N));
	printf("%d", factorial_2(N));

	return 0;
}

/*int factorial_1(int x) {
	int res=1,i;
	for (i = x; i > 0; i--) {
		res *= i;
	}
	return res;

}*/

int factorial_2(int x) {
	if (x == 0) {
		return 1;
	}
	return x * factorial_2(x - 1);
}