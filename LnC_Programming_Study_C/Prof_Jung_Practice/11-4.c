#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void max(int, int, int);
void mid(int, int, int);
void min(int, int, int);

void main() {
	int x, y, z;
	int selection;
	while (1) {
		printf("�޴��� �Է��Ͻÿ�(0 - ���� / 1 - �ִ� / 2 - �߰��� / 3 - �ּڰ� ) : ");
		scanf("%d", &selection);
		getchar();

		if (selection == 0) {
			break;
		}

		printf("���� 3���� �Է��ϼ���: ");
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
			printf("�޴��� �߸� �Է��Ͽ����ϴ�.\n");
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

	printf("output:\n�ִ��� = %d\n", max);
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

	printf("output:\n�߰����� = %d\n", mid);
}

void min(int x, int y, int z) {
	int min = x;
	if (min > y) {
		min = y;
	}
	if (min > z) {
		min = z;
	}

	printf("output:\n�ּڰ��� = %d\n", min);
}


