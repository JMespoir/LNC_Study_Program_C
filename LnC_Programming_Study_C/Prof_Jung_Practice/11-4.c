#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void max(int, int, int);
void mid(int, int, int);
void min(int, int, int);

void main() {
	int x, y, z;
	int selection;
	while (1) {
		printf("메뉴를 입력하시오(0 - 종료 / 1 - 최댓값 / 2 - 중간값 / 3 - 최솟값 ) : ");
		scanf("%d", &selection);
		getchar();

		if (selection == 0) {
			break;
		}

		printf("정수 3개를 입력하세요: ");
		scanf("%d %d %d", &x, &y, &z);

		printf("\n");

		if (selection == 1) {
			max(x, y, z);
		}
		else if (selection == 2) {
			mid(x, y, z);
		}
		else if (selection == 3) {
			min(x, y, z);
		}
		else {
			printf("메뉴를 잘못 입력하였습니다.\n");
		}

		printf("\n");
	}


}

void max(int x, int y, int z) {
	int max = x;
	if (max < y) {
		max = y;
	}
	if (max < z) {
		max = z;
	}

	printf("output:\n최댓값은 = %d\n", max);
}

void mid(int x, int y, int z) {
	int max = x;
	if (max < y) {
		max = y;
	}
	if (max < z) {
		max = z;
	}

	int min = x;

	if (min > y) {
		min = y;
	}
	if (min > z) {
		min = z;
	}

	int mid = x;

	if ((y != max) && (y != min)) {
		mid = y;
	}

	if ((z != max) && (z != min)) {
		mid = z;
	}

	printf("output:\n중간값은 = %d\n", mid);
}

void min(int x, int y, int z) {
	int min = x;
	if (min > y) {
		min = y;
	}
	if (min > z) {
		min = z;
	}

	printf("output:\n최솟값은 = %d\n", min);
}


