// Hashing_Liner Probing
// 데이터를 저장하고 탐색하는 hashing 프로그램

#define _CRT_SECURE_NO_WARNINGS
#define MAX 13
#include <stdio.h>
#include <string.h>

typedef struct {
	int sum;
	char arr[100];
} Hash;

void init_hash(Hash arr[]);
void hashFunc(char str[][100], Hash arr[]);
int ascii(char str[]);
void print(Hash arr[]);
void search(char str[][100], Hash arr[]);

int main() {
	Hash arr[MAX];
	char str[MAX][100] = { "do", "for", "if", "case", "else", "return", "function" };

	init_hash(arr);
	hashFunc(str, arr);	
	search(str, arr);

	return 0;
}

void init_hash(Hash arr[]) {
	for (int i = 0; i < MAX; i++) {
		arr[i].sum = 0;
	}
}

void hashFunc(char str[][100], Hash arr[]) {
	for (int i = 0; i < MAX; i++) {
		if (strlen(str[i]) == 0) break;

		int sum = ascii(str[i]);
		int idx = sum % 13;

		if (arr[idx].sum == 0) {
			arr[idx].sum = sum;
			strcpy(arr[idx].arr, str[i]);
			print(arr);

			continue;
		}

		if (!strcmp(str[i], arr[idx].arr)) continue;

		while (arr[idx].sum != 0) {
			printf("overflow가 발생했습니다.\n");

			idx++;

			if (idx == MAX)
				idx = 0;
		}

		arr[idx].sum = sum;
		strcpy(arr[idx].arr, str[i]);
		print(arr);
	}
}

int ascii(char str[]) {
	int sum = 0;

	for (int i = 0; i < 100; i++) {
		if (str[i] == NULL) break;

		if (str[i] == '\0') {
			break;
		}

		sum += str[i];
	}

	return sum;
}

void print(Hash arr[]) {
	printf("\n==========================================\n");

	for (int i = 0; i < MAX; i++) {
		printf("[%d]\t", i);

		if (arr[i].sum != 0)
			printf("%s", arr[i].arr);

		printf("\n");
	}

	printf("==========================================\n\n");
}

void search(char str[][100], Hash arr[]) {
	for (int i = 0; i < MAX; i++) {
		if (strlen(str[i]) == 0)
			break;

		printf("탐색 %s: ", str[i]);

		int sum = ascii(str[i]);
		int idx = sum % 13;

		while (arr[idx].sum != sum) {
			idx++;

			if (idx == MAX)
				idx = 0;
		}

		printf("위치 = %d\n", idx);
	}
}