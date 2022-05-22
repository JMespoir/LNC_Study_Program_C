#include <stdio.h>

typedef struct {
	int x, y,rank;

}body;


void ranking(body arry[], int n);	//순위 매기는 함수

int main(void) {
	int N,i;
	body list[100];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d%d", &list[i].x, &list[i].y);//x,y 입력
	}
	
	ranking(list,N);//순위 매기기

	for (i = 0; i < N; i++) {
		printf("%d ", list[i].rank);//순위 출력
	}
}

void ranking(body arry[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int x = 1;
		for (j = 0; j < n; j++) {
			if (arry[i].x < arry[j].x) {
				if (arry[i].y < arry[j].y) {//x와 y가 더 작으면 순위가 한 단계씩 떨어짐
					x++;
				}
			}
			arry[i].rank = x; 
		}

	}
}