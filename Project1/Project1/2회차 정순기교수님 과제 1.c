#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int calculate(int, int, char);

void main() {
	int a, b;
	char c;

	printf("�� ���� �Է��ϼ���: ");
	scanf("%d%d", &a, &b);
	getchar();

	printf("�����ڸ� �Է��Ͻÿ�: ");
	scanf("%c", &c);

	printf("\n");

	if ((c == '%' || c == '/') && b == 0) {
		printf("�Ұ����� �����Դϴ�.");
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