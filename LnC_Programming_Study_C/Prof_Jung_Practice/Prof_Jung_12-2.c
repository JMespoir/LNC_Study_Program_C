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

	printf("�������ϸ��� �Է��Ͻÿ�: ");
	gets(input_file);

	printf("\n");

	printf("�������� ���� ���:\n");

	fp = fopen(input_file, "rb+");
	while (fread(&list[n], sizeof(tStudent), 1, fp)) {
		printf("%5d%15s\t%10.1f\t%10.1f\t%10.1f\t%10.1f\n", list[n].std_id, list[n].name, list[n].score[0], list[n].score[1], list[n].score[2], list[n].total);
		n++;
	}
	
	printf("��л��� ������ �����ϰڽ��ϱ�: ");
	scanf("%s", stu_name);
	printf("%s �л��� ������:\n");

	for (i = 0; i < n; i++) {
		if (strcmp(stu_name, list[i].name) == 0) {
			printf("%5d%15s\t%10.1f\t%10.1f\t%10.1f\t%10.1f\n", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);
			break;
		}
	}
	printf("������ ������ �Է��ϼ���: ");
	scanf("%lf %lf %lf", &list[i].score[0], &list[i].score[1], &list[i].score[2]);
	list[i].total = list[i].score[0], list[i].score[1], list[i].score[2];
	fseek(fp, sizeof(tStudent) * i, SEEK_SET);
	fwrite(&list[i], sizeof(tStudent), 1, fp);

	printf("������ �л��� ������ �ٽ� ����ϸ�:\n");
	printf("%5d%15s\t%10.1f\t%10.1f\t%10.1f\t%10.1f", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);
}
