#include <stdio.h>

typedef struct {
	int x, y,rank;

}body;


void ranking(body arry[], int n);	//���� �ű�� �Լ�

int main(void) {
	int N,i;
	body list[100];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d%d", &list[i].x, &list[i].y);//x,y �Է�
	}
	
	ranking(list,N);//���� �ű��

	for (i = 0; i < N; i++) {
		printf("%d ", list[i].rank);//���� ���
	}
}

void ranking(body arry[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int x = 1;
		for (j = 0; j < n; j++) {
			if (arry[i].x < arry[j].x) {
				if (arry[i].y < arry[j].y) {//x�� y�� �� ������ ������ �� �ܰ辿 ������
					x++;
				}
			}
			arry[i].rank = x; 
		}

	}
}