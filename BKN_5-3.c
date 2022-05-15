#include <stdio.h>

int check(int);

int main(void) {
	int n;

	scanf("%d", &n);

	if (n >= 1 && n <= 1000) {
		printf("%d", check(n));
	}

	return 0;

}

int check(int number) {
	int i, d, tho, hud, ten, one;
	int res;
	if (number >= 100) {
		res = 99;
		for (i = 100; i <= number; i++) {
			tho = i / 1000;
			hud = i % 1000 / 100;
			ten = i % 100 / 10;
			one = i % 10;

			if (tho == 0) {
				d = hud - ten;
				if ((ten - one) == d) {
					res = res + 1;
					continue;
				}
			}
			else if (tho == 1) {
				d = tho - hud;
				if (((hud - ten) == d) && ((ten - one) == d)) {
					res = res + 1;
					continue;
				}
			}
		}
	}
	else if (number < 100) {
		res = number;
	}

	return res;
}

