#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

double length(int, int, int, int);

int main() {
	int a, b, c, d;

	printf("������ ������ ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("������ ���� ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d %d", &c, &d);

	printf("\n");

	printf("output:\n(%d,%d)~(%d,%d) ������ ����: %.2lf�Դϴ�.", a, b, c, d, length(a, b, c, d));

	return 0;
}

double length(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

