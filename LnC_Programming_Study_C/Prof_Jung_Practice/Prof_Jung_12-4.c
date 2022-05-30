#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char FILENAME[30] = "account.bin";		// ���� ����

typedef struct {		//����ü (��������)
	int accNum;
	char name[30];
	double balance;
}tAccount;

typedef enum {		//������(�޴�����)
	add = 1, search, deposit, withdraw, print, exit
}menu;

int structsize(FILE*, tAccount[]);
void addinf(FILE*, tAccount[], int);
void searchinf(FILE*, tAccount[]);
void depositinf(FILE*, tAccount[]);
void withdrawinf(FILE*, tAccount[]);
void printinf(FILE*, tAccount[]);

int main(void) {
	menu selection;
	FILE* fp;
	int tem_accNum, cnt;
	tAccount list[30] = { 0 };
	

	while (1) {
		printf("�޴��� �Է��Ͻÿ�: ");
		scanf("%d", &selection);
		fp = fopen(FILENAME, "ab+");
		fclose(fp);

		fp = fopen(FILENAME, "rb");
		rewind(fp);
		cnt = structsize(fp, list);
		fclose(fp);

		if (selection == add) {
			fp = fopen(FILENAME, "ab+");
			addinf(fp, list,cnt);
			fclose(fp);
			printf("\n");
		}
		else if (selection == search) {
			fp = fopen(FILENAME, "rb");
			rewind(fp);
			searchinf(fp, list);
			fclose(fp);
		}
		else if (selection == deposit) {
			fp = fopen(FILENAME, "rb+");
			rewind(fp);
			depositinf(fp, list);
			fclose(fp);
		}
		else if (selection == withdraw) {
			fp = fopen(FILENAME, "rb+");
			rewind(fp);
			withdrawinf(fp, list);
			fclose(fp);
		}
		else if (selection == print) {
			fp = fopen(FILENAME, "rb");
			rewind(fp);
			printinf(fp, list);
			fclose(fp);
			printf("\n");
		}
		else if (selection == exit) {
			break;
		}
	}
}

int structsize(FILE* f, tAccount arry[]) {		//���������� �󸶳� �ִ��� ��������
	int cnt = 0;
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		cnt++;
	}
	return cnt;
}

void addinf(FILE* f, tAccount arry[], int size) {		//���� �Է����ִ� �Լ�
	int accnum;
	size += 1;
	while (1) {
		printf("������ �Է����ּ���: ");
		scanf("%d", &accnum);
		if (accnum <= -1) {		//-1 �ԷµǸ� �� �Լ��� ����
			break;
		}
		else {		//���� �Է����ִ� ���
			arry[size].accNum = accnum;
			scanf("%s %lf", &arry[size].name, &arry[size].balance);
			fwrite(&arry[size], sizeof(tAccount), 1, f);
			size++;
		}
	}
}

void searchinf(FILE* f, tAccount arry[]) {		//Ư�� ���� ������ ����Ʈ
	char tem[30];
	int cnt = 0;
	printf("���̸��� �Է��Ͻÿ�: ");
	scanf("%s", tem);
	printf("���¹�ȣ  �̸�   �� ��\n");

	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		if (strcmp(arry[cnt].name, tem) == 0) {
			printf("%d\t%s  %.2lf\n\n", arry[cnt].accNum, arry[cnt].name, arry[cnt].balance);
			break;
		}
		cnt++;
	}
}


void depositinf(FILE* f, tAccount arry[]) {		//�Ա� �Լ�
	char tem_name[30];
	double tem_balance;
	int cnt = 0;

	printf("���̸��� �Ա��� �ݾ��� �Է��Ͻÿ�: ");
	scanf("%s %lf", tem_name, &tem_balance);
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		if (strcmp(arry[cnt].name, tem_name) == 0) {
			arry[cnt].balance += tem_balance;
			printf("������Ʈ �� ������:\n");
			printf("%d %s %.2lf\n", arry[cnt].accNum, arry[cnt].name, arry[cnt].balance);
			fseek(f, sizeof(tAccount) * cnt, SEEK_SET);
			fwrite(&arry[cnt], sizeof(tAccount), 1, f);
			break;
		}
		cnt++;
	}
}


void withdrawinf(FILE* f, tAccount arry[]) {		//��� �Լ�
	char tem_name[30];
	double tem_balance;
	int cnt = 0;

	printf("���̸��� ����� �ݾ��� �Է��Ͻÿ�: ");
	scanf("%s %lf", tem_name, &tem_balance);
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		if (strcmp(arry[cnt].name, tem_name) == 0) {
			arry[cnt].balance -= tem_balance;
			printf("������Ʈ �� ������:\n");
			printf("%d %s %.2lf\n", arry[cnt].accNum, arry[cnt].name, arry[cnt].balance);
			fseek(f, sizeof(tAccount) * cnt, SEEK_SET);
			fwrite(&arry[cnt], sizeof(tAccount), 1, f);
			break;
		}
		cnt++;
	}
}

void printinf(FILE* f, tAccount arry[]) {		//���� �Էµ� ���������� ���
	double total = 0;
	int cnt = 0, i;
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		total += arry[cnt].balance;
		cnt++;
	}
	printf("�Ѿ�: Total=%.2f\n", total);
	for (i = 0; i < cnt; i++) {
		printf("%d %s %.2lf\n", arry[i].accNum, arry[i].name, arry[i].balance);
	}

}

