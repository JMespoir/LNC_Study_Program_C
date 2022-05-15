#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

double length(int, int, int, int);

int main() {
	int a, b, c, d;

	printf("직선의 시작점 좌표를 입력하시오: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("직선의 끝점 좌표를 입력하시오: ");
	scanf("%d %d", &c, &d);

	printf("\n");

	printf("output:\n(%d,%d)~(%d,%d) 직선의 길이: %.2lf입니다.", a, b, c, d, length(a, b, c, d));

	return 0;
}

double length(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

