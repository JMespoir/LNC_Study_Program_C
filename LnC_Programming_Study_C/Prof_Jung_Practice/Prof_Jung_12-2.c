#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int std_id;
	char name[30];
	double score[3];
	double total;

}tStudent;

int main(void) {
	tStudent list[30] = { 0 };
	FILE* fp;

	char input_file[30],stu_name[30];
	int n = 0,i;

	printf("이진파일명을 입력하시오: ");
	gets(input_file);

	printf("\n");

	printf("이진파일 내용 출력:\n");

	fp = fopen(input_file, "rb+");
	while (fread(&list[n], sizeof(tStudent), 1, fp)) {
		printf("%5d%15s\t%10.1f\t%10.1f\t%10.1f\t%10.1f\n", list[n].std_id, list[n].name, list[n].score[0], list[n].score[1], list[n].score[2], list[n].total);
		n++;
	}
	
	printf("어떤학생의 내용을 수정하겠습니까: ");
	scanf("%s", stu_name);
	printf("%s 학생의 정보는:\n");

	for (i = 0; i < n; i++) {
		if (strcmp(stu_name, list[i].name) == 0) {
			printf("%5d%15s\t%10.1f\t%10.1f\t%10.1f\t%10.1f\n", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);
			break;
		}
	}
	printf("수정할 점수를 입력하세요: ");
	scanf("%lf %lf %lf", &list[i].score[0], &list[i].score[1], &list[i].score[2]);
	list[i].total = list[i].score[0], list[i].score[1], list[i].score[2];
	fseek(fp, sizeof(tStudent) * i, SEEK_SET);
	fwrite(&list[i], sizeof(tStudent), 1, fp);

	printf("수정된 학생의 정보를 다시 출력하면:\n");
	printf("%5d%15s\t%10.1f\t%10.1f\t%10.1f\t%10.1f", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);
}
