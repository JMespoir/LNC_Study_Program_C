#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void printrecursive(int,int);

int main(void) {
	int N;
	scanf("%d", &N);

	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	printrecursive(N,N);

}

void printrecursive(int x,int N) {
	int i;
	
	if (x < 0) {
		return;
	}
	for (i = x; i < N; i++) {
		printf("____");
	}
	printf("\"����Լ��� ������?\"\n");
	if (x == 0) {
		for (i = x; i < N; i++) {
			printf("____");
		}
			printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
	}
	else if(x>0){
		for (i = x; i < N; i++) {
			printf("____");
		}
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		for (i = x; i < N; i++) {
			printf("____");
		}
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		for (i = x; i < N; i++) {
			printf("____");
		}
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
	}
	printrecursive(x - 1, N);
	for (i = x; i < N; i++) {
		printf("____");
	}
	printf("��� �亯�Ͽ���.\n");

}