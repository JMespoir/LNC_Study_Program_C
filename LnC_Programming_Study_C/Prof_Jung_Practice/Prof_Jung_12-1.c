#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {//구조체 계좌정보
	int accNum;
	char name[30];
	double balance;
}tAccount;

typedef enum {//열거형
	add=1,search,deposit,withdraw,print,exit
}menu;

void structsize(FILE*, tAccount[]);//
void addinf(FILE*,tAccount[], int);//
void searchinf(FILE*, tAccount[]);//
void depositinf(FILE*, tAccount[],int);
void withdrawinf(FILE*, tAccount[],int);
void printinf(FILE*, tAccount[]);//

int main(void) {
	menu selection;
	FILE* fp;
	int tem_accNum,cnt;
	tAccount list[30];

	while (1) {
		printf("메뉴를 입력하시오: ");
		scanf("%d", selection);

		fp = fopen("account.bin", "rb");
		cnt = structsize(fp, list);
		fclose(fp);

		if (selection == add) {
			fp = fopen("account.bin", "ab+");
			addinf(fp,list);
			fclose(fp);
			printf("\n");
		}
		else if (selection == search) {
			fp = fopen("account.bin", "rb");
			searchinf(fp, list);
			fclose(fp);
		}
		else if (selection == deposit) {
			depositinf(fp, list, cnt);
			fclose(fp);
		}
		else if (selection == withdraw) {
			withdrawinf(fp, list, cnt);
			fclose(fp);
		}
		else if (selection == print) {
			fp = fopen("account.bin", "rb");
			rewind(fp);
			printinf(fp, list);
			fclose(fp);
		}
		else if (selection == exit) {
			break;
		}
	}
}

int structsize(FILE *f, tAccount arry[]) {//계좌정보가 얼마나 있는지 개수세기
	int cnt = 0;
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		cnt++;
	}
	return cnt;
}

void addinf(FILE *f, tAccount arry[], int size) {//정보 입력해주는 함수
	int accnum;
	size += 1;
	while (1) {
		scanf("%d", &accnum);
		if (accnum <= -1) {//-1 입력되면 이 함수가 멈춤
			break;
		}
		else {//정보 입력해주는 기능
			arry[size].accNum = accnum;
			scanf("%s %lf", &arry[size].name, &arry[size].balance);
			fwrite(&arry[size], sizeof(tAccount), 1, f);
			size++;
		}
	}
}

void searchinf(FILE* f, tAccount arry[]) {
	char tem[30];
	int cnt = 0;
	printf("고객이름을 입력하시오: ");
	scanf("%s", tem);
	printf("계좌번호  이름   잔 고\n");

	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		if (strcmp(arry[cnt].name,tem)==0) {
			printf("%d\t%s  %.2lf", arry[cnt].accNum, arry[cnt].name, arry[cnt].size);
			break;
		}
		cnt++;
	}
}

void depositinf(FILE* f, tAccount arry[]) {
	char tem_name[30];
	double tem_balance;
	int cnt = 0;

	printf("고객이름과 입금할 금액을 입력하시오: ");
	scanf("%s %lf", tem_name, &tem_balance);
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		if (strcmp(arry[cnt].name, tem_name) == 0) {
			fseek(f, sizeof(tAccount)*cnt, SEEK_SET);
			arry[cnt].balance += tem_balance;
			fwrite(&arry[cnt], sizeof(tAccount), 1, f);
			break;
		}
		cnt++;
	}
}

void withdrawinf(FILE* f, tAccount arry[]) {
	char tem_name[30];
	double tem_balance;
	int cnt = 0;

	printf("고객이름과 출금할 금액을 입력하시오: ");
	scanf("%s %lf", tem_name, &tem_balance);
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		if (strcmp(arry[cnt].name, tem_name) == 0) {
			fseek(f, sizeof(tAccount) * cnt, SEEK_SET);
			arry[cnt].balance -= tem_balance;
			fwrite(&arry[cnt], sizeof(tAccount), 1, f);
			break;
		}
		cnt++;
	}
}

void printinf(FILE *f, tAccount arry[]) {//현재 입력된 계좌정보들 출력
	double total = 0;
	int cnt = 0,i;
	while (fread(&arry[cnt], sizeof(tAccount), 1, f)) {
		total += arry[cnt].balance;
		cnt++;
	}
	printf("총액: Total=%.2f\n", total);
	for (i = 0; i < cnt; i++) {
		printf("%d %s %.2lf\n", arry[i].accNum, arry[i].name, arry[i].balance);
	}
	
}