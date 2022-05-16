#include <stdio.h>

int main(void) {
	int N;

	scanf("%d", &N);

	if (3 <= N && N <= 5000) {
		if (N % 5 == 0) {
			printf("%d", N / 5);
		}

		else if (N >= 8 && (N - 3) % 5 == 0) {
			printf("%d", (N - 3) / 5 + 1);
		}
		else if (N >= 11 && (N - 6) % 5 == 0) {
			printf("%d", (N - 6) / 5 + 2);
		}
		else if (N >= 14 && (N - 9) % 5 == 0) {
			printf("%d", (N - 9) / 5 + 3);
		}
		else if (N >= 17 && (N - 12) % 5 == 0) {
			printf("%d", (N - 12) / 5 + 4);
		}
		else if (N % 3 == 0) {
			printf("%d", N / 3);
		}
		else {
			printf("-1");
		}

	}
}