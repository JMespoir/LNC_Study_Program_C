#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int recursive(int, int);

int main(void) {
	int T, k, n, i;
	int arry[10000] = { 0 };
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d%d", &k, &n);
		if (k >= 1 && n <= 14) {
			arry[i] = recursive(k, n);
		}
			
	}
	for (i = 0; i < T; i++) {
		printf("%d\n", arry[i]);
		 
	}
}

int recursive(int k, int n) {
    if (k == 0 || n == 1)
        return n;
    else
        return recursive(k, n - 1) + recursive(k - 1, n);
}