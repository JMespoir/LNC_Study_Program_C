#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void) {
	int n, i = 1 , res = 1,d=6;

	scanf("%d", &n);
	if (n == 1) {
		printf("1");
	}
	else{
		do {
			res = res + d;
			i++;
			d += 6;
		} while (n > res);

		printf("%d", i);
	}
	
}