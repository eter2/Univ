// Hashing_Random probing

#define _CRT_SECURE_NO_WARNINGS
#define MAX 13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
	int sum;
	char arr[100];
} Hash;

int randIdx = 0;
int max = 0;

void init_hash(Hash arr[]);
void hashFunc(int randSeq[], char str[], Hash arr[]);
int ascii(char str[]);
void search(int randSeq[], char str[], Hash arr[]);
void del(int randSeq[], char str[], Hash arr[]);

int main() {
	Hash arr[MAX];
	int randSeq[2000];
	
	init_hash(arr);
	
	while (1) {
		char flag[2];
		printf("����(i), Ž��(s), ����(d), ����(q): ");
		scanf("%s", &flag);

		if (!strcmp(flag, "i")) {
			char name[100];

			printf("������ ������ �̸��� �Է��ϼ���: ");
			scanf("%s", &name);
			hashFunc(randSeq, name, arr);
		}

		if (!strcmp(flag, "s")) {
			char name[100];

			printf("Ž���� ������ �̸��� �Է��ϼ���: ");
			scanf("%s", &name);
			search(randSeq, name, arr);
		}

		if (!strcmp(flag, "d")) {
			char name[100];
			
			printf("������ ������ �̸��� �Է��ϼ���: ");
			scanf("%s", &name);
			del(randSeq, name, arr);
		}

		if (!strcmp(flag, "q")) {
			printf("�����մϴ�.\n");
			break;
		}
	}

	return 0;
}

void init_hash(Hash arr[]) {
	for (int i = 0; i < MAX; i++) {
		arr[i].sum = 0;
	}
}

void hashFunc(int randSeq[], char str[], Hash arr[]) {
	if (max >= MAX) {
		printf("���� ������ �����ϴ�.\n\n");
		return;
	}

	int sum = ascii(str);
	int idx = sum % 13;

	if (!strcmp(str, arr[idx].arr)) {
		printf("�ߺ��� �ܾ��Դϴ�.\n\n");	
		return;
	}

	if (arr[idx].sum == 0) {
		arr[idx].sum = sum;
		strcpy(arr[idx].arr, str);

		printf("�ε��� %d���� ����Ǿ����ϴ�.\n\n", idx);
		
		max++;
		return;
	}

	int cnt = 0;

	while (cnt < randIdx) {
		idx += randSeq[cnt++];

		if (idx >= MAX)
			idx -= 13;

		if (!strcmp(str, arr[idx].arr)) {
			printf("�ߺ��� �ܾ��Դϴ�.\n\n");
			return;
		}

		if (arr[idx].sum == 0)
			break;
	}

	while (arr[idx].sum != 0) {
		srand(time(NULL));
		int random = rand() % 13;
		idx += random;

		if (idx >= MAX)
			idx -= 13;

		if (!strcmp(str, arr[idx].arr)) {
			printf("�ߺ��� �ܾ��Դϴ�.\n\n");
			return;
		}

		if (randIdx > 5000) {
			printf("Random number sequence�� ���� ������ �����մϴ�.\n������ �� �����ϴ�.\n\n");
			return;
		}

		randSeq[randIdx++] = random;
	}

	arr[idx].sum = sum;
	strcpy(arr[idx].arr, str);

	printf("overflow�� �߻��Ͽ����ϴ�.\n");
	printf("�ε��� %d���� ����Ǿ����ϴ�.\n\n", idx);

	max++;
}

int ascii(char str[]) {
	int sum = 0;

	for (int i = 0; i < 100; i++) {
		if (str[i] == '\0')
			break;

		sum += str[i];
	}

	return sum;
}

void search(int randSeq[], char str[], Hash arr[]) {
	int sum = ascii(str);
	int idx = sum % 13;

	if (!strcmp(arr[idx].arr, str)) {
		printf("Ž���� ������ �̸��� �ε��� %d���� �ֽ��ϴ�.\n\n", idx);
		return;
	}

	int cnt = 0;

	while (cnt < randIdx) {
		idx += randSeq[cnt++];

		if (idx >= MAX)
			idx -= 13;

		if (!strcmp(arr[idx].arr, str)) {
			printf("Ž���� ������ �̸��� �ε��� %d���� �ֽ��ϴ�.\n\n", idx);
			return;
		}
	}

	printf("Ž���� ������ �̸��� �������� �ʽ��ϴ�.\n\n");
}

void del(int randSeq[], char str[], Hash arr[]) {
	int sum = ascii(str);
	int idx = sum % 13;

	if (!strcmp(arr[idx].arr, str)) {
		printf("�����Ǿ����ϴ�.\n\n");
		arr[idx].arr[0] = NULL;
		arr[idx].sum = 0;
		max--;

		return;
	}

	int cnt = 0;

	while (cnt < randIdx) {
		idx += randSeq[cnt++];

		if (idx >= MAX)
			idx -= 13;

		if (!strcmp(arr[idx].arr, str)) {
			printf("�����Ǿ����ϴ�.\n\n");
			arr[idx].arr[0] = NULL;
			arr[idx].sum = 0;
			max--;

			return;;
		}
	}

	printf("������ �����Ͱ� �����ϴ�.\n\n");
}