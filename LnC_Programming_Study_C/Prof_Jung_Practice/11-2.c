#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

double calculate(double);

void main() {
	double x;

	printf("x�� ���� �Է��ϼ��� : ");
	scanf("%lf", &x);

	printf("\n");

	printf("output:\nX�� ���� %lf �� ��, ���׽��� ���� %.2lf�Դϴ�.", x, calculate(x));

}

double calculate(double x) {
	return (3 * pow(x, 5)) - (7 * pow(x, 4)) + 9;
}