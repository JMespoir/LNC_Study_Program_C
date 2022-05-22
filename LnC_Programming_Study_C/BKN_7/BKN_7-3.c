#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void printfraction(int);

int main() {
	int N;

	scanf("%d", &N);
	
	printfraction(N);

}

void printfraction(int n) {
	int res = 0, x = 0, i;

	while (n - res >0) {
		res = res + x;
		x++;
	}
	
	x--;
	if (x % 2 == 0) {
		printf("%d/%d", x - res + n, res - n + 1);
	}
	else {
		printf("%d/%d", res - n + 1, x - res + n);
	}


}