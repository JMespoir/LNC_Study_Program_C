#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	unsigned int fix_cost, var_cost, sell_cost;
	scanf("%d%d%d", &fix_cost, &var_cost, &sell_cost);
	if (fix_cost <= 2100000000 && fix_cost >= 1 && var_cost <= 2100000000 && var_cost >= 1 && sell_cost <= 2100000000 && sell_cost >= 1) {
		if (var_cost >= sell_cost) {
			printf("-1");
		}
		else {
			printf("%d", fix_cost / (sell_cost - var_cost) + 1);
		}


	}

	return 0;

}