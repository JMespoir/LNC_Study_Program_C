#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARINGS

void printAdd(char[], char[]);

int main(void) {

	char tem_A[10005]={0, }, tem_B[10005]={0, };
	char A[10001], B[10001];
	int i=0;


	scanf("%s %s", tem_A, tem_B);
	
	for (i = 0; i < strlen(tem_A); i++) {
		A[i] = tem_A[strlen(tem_A) - 1 - i];
	}
	A[strlen(tem_A)] = '\0';
	
	for (i = 0; i < strlen(tem_B); i++) {
		B[i] = tem_B[strlen(tem_B) - 1 - i];
	}
	B[strlen(tem_B)] = '\0';

	if (strlen(tem_A) > strlen(tem_B)) {
		printAdd(A, B);
	}

	else if(strlen(tem_A)<=strlen(tem_B)) {
		printAdd(B, A);
	}
}

void printAdd(char x[], char y[]) {
	int res[10002] = { 0 };
	int i;
	
	for (i = 0; i < strlen(y); i++) {
		if (x[i] - '0' + y[i] - '0' + res[i] >= 10) {
			res[i + 1] = res[i + 1] + 1;
			res[i] = x[i] - '0' + y[i] - '0'-10+res[i];
		}
		else {
			res[i] = x[i] - '0' + y[i] - '0'+res[i];
		}

	}
	//strlen(x)~strlen(x)-strlen(y)ºÎºÐ

	for (i = strlen(y); i < strlen(x); i++) {
		if (x[i] - '0' + res[i] >= 10) {
			res[i + 1] = res[i + 1] + 1;
			res[i] = x[i] - '0' - 10 + res[i];
		}
		else {
			res[i] = x[i] - '0'+ res[i];
		}
	}



	if (res[strlen(x)] == 1) {
		for (i = strlen(x); i >= 0; i--) {
			printf("%d", res[i]);
		}
	}
	else {
		for (i = strlen(x)-1; i >= 0; i--) {
			printf("%d", res[i]);
		}
	}
}




