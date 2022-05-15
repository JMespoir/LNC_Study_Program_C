#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int calculate(int, int, char);

void main() {
	int a, b;
	char c;

	printf("두 수를 입력하세요: ");
	scanf("%d%d", &a, &b);
	getchar();

	printf("연산자를 입력하시오: ");
	scanf("%c", &c);

	printf("\n");

	if ((c == '%' || c == '/') && b == 0) {
		printf("불가능한 연산입니다.");
	}

	else {
		printf("output:\n%d%c%d = %d", a, c, b, calculate(a, b, c));
	}


}

int calculate(int x, int y, char op) {
	if (op == '+') {
		return x + y;
	}
	else if (op == '-') {
		return x - y;
	}
	else if (op == '*') {
		return x * y;
	}
	else if (op == '/') {
		return x / y;
	}
	else if (op == '%') {
		return x % y;
	}
}