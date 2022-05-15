#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

double calculate(double);

void main() {
	double x;

	printf("x의 값을 입력하세요 : ");
	scanf("%lf", &x);

	printf("\n");

	printf("output:\nX의 값이 %lf 일 때, 다항식의 값은 %.2lf입니다.", x, calculate(x));

}

double calculate(double x) {
	return (3 * pow(x, 5)) - (7 * pow(x, 4)) + 9;
}