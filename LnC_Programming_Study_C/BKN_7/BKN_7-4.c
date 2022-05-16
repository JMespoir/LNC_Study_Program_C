#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS


int main(void) {
	long long a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	if (1 <= b && b < a && a <= c && c <= 1000000000) {
		if ((c - b) % (a - b) == 0) {
			printf("%d", (c - b) / (a - b));
		}
		else {
			printf("%d", (c - b) / (a - b) + 1);
		}
	}

	return 0;
}