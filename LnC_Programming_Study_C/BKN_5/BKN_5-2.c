#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void addSelfNum(int);
int checkSelfNum(int);

int n = 0;
int arry[10000] = { 0 };

int main(void) {
	int i;

	for (i = 1; i <= 10000; i++) {
		addSelfNum(i);
	}




	for (i = 0; i < n; i++) {
		printf("%d", arry[i]);
		if (i == n - 1) {
			break;
		}
		printf("\n");
	}

	return 0;

}

void addSelfNum(int num) {
	if (checkSelfNum(num) == 0) {
		arry[n] = num;
		n++;
	}

}

int checkSelfNum(int num) {
	int i;
	int check;
	int x = 0;
	for (i = 1; i < num; i++) {
		check = i + (i % 100 / 10) + (i % 1000 / 100) + (i / 1000) + (i % 10);
		if (check == num) {
			x = 1;
			break;
		}
	}
	return x;
}