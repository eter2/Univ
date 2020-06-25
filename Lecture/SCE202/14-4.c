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
		printf("삽입(i), 탐색(s), 삭제(d), 종료(q): ");
		scanf("%s", &flag);

		if (!strcmp(flag, "i")) {
			char name[100];

			printf("저장할 동물의 이름을 입력하세요: ");
			scanf("%s", &name);
			hashFunc(randSeq, name, arr);
		}

		if (!strcmp(flag, "s")) {
			char name[100];

			printf("탐색할 동물의 이름을 입력하세요: ");
			scanf("%s", &name);
			search(randSeq, name, arr);
		}

		if (!strcmp(flag, "d")) {
			char name[100];
			
			printf("삭제할 동물의 이름을 입력하세요: ");
			scanf("%s", &name);
			del(randSeq, name, arr);
		}

		if (!strcmp(flag, "q")) {
			printf("종료합니다.\n");
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
		printf("저장 공간이 없습니다.\n\n");
		return;
	}

	int sum = ascii(str);
	int idx = sum % 13;

	if (!strcmp(str, arr[idx].arr)) {
		printf("중복된 단어입니다.\n\n");	
		return;
	}

	if (arr[idx].sum == 0) {
		arr[idx].sum = sum;
		strcpy(arr[idx].arr, str);

		printf("인덱스 %d번에 저장되었습니다.\n\n", idx);
		
		max++;
		return;
	}

	int cnt = 0;

	while (cnt < randIdx) {
		idx += randSeq[cnt++];

		if (idx >= MAX)
			idx -= 13;

		if (!strcmp(str, arr[idx].arr)) {
			printf("중복된 단어입니다.\n\n");
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
			printf("중복된 단어입니다.\n\n");
			return;
		}

		if (randIdx > 5000) {
			printf("Random number sequence의 저장 공간이 부족합니다.\n저장할 수 없습니다.\n\n");
			return;
		}

		randSeq[randIdx++] = random;
	}

	arr[idx].sum = sum;
	strcpy(arr[idx].arr, str);

	printf("overflow가 발생하였습니다.\n");
	printf("인덱스 %d번에 저장되었습니다.\n\n", idx);

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
		printf("탐색한 동물의 이름은 인덱스 %d번에 있습니다.\n\n", idx);
		return;
	}

	int cnt = 0;

	while (cnt < randIdx) {
		idx += randSeq[cnt++];

		if (idx >= MAX)
			idx -= 13;

		if (!strcmp(arr[idx].arr, str)) {
			printf("탐색한 동물의 이름은 인덱스 %d번에 있습니다.\n\n", idx);
			return;
		}
	}

	printf("탐색한 동물의 이름은 존재하지 않습니다.\n\n");
}

void del(int randSeq[], char str[], Hash arr[]) {
	int sum = ascii(str);
	int idx = sum % 13;

	if (!strcmp(arr[idx].arr, str)) {
		printf("삭제되었습니다.\n\n");
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
			printf("삭제되었습니다.\n\n");
			arr[idx].arr[0] = NULL;
			arr[idx].sum = 0;
			max--;

			return;;
		}
	}

	printf("삭제할 데이터가 없습니다.\n\n");
}