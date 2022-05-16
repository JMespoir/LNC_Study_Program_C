#include <stdio.h>

int main(void) {

	int H, W, N, testcase, i;
	int arry[1000] = { 0 };
	int tem;
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {

		scanf("%d%d%d", &H, &W, &N);

		if (1 <= H && W <= 99 && 1 <= N && N <= H * W) {
			if (H == 1) {
				if (N % H == 0) {
					arry[i] = H * 100 + N;
				}
				else {
					arry[i] = (N % H) * 100 + N + 1;
				}
			}
			else {
				if (N % H == 0) {
					arry[i] = H * 100 + (N / H);
				}
				else {
					arry[i] = (N % H) * 100 + (N / H) + 1;
				}
			}
		}
	}

	for (i = 0; i < testcase; i++) {
		printf("%d\n", arry[i]);
	}

	return 0;
}