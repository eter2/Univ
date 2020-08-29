// Sorting

#define _CRT_SECURE_NO_WARNINGS
#define MAX 12
#include <stdio.h>

int array[MAX] = {104, 101, 90, 88, 69, 10, 30, 2, 16, 8, 31, 22 };
int queue[10][MAX];
int front[MAX];
int rear[MAX];

void radixSort();
void pop();
void print();

int main() {
	printf("정렬할 데이터:");
	print();

	radixSort();

	printf("Radix sort를 수행한 결과:");
	print();

	return 0;
}

void radixSort() {
	for (int i = 0; i < MAX; i++) {
		int num = array[i] % 10;
		queue[num][front[num]++] = array[i];
	}
	pop();

	for (int i = 0; i < MAX; i++) {
		int num = array[i] / 10;
		num = num % 10;
		queue[num][front[num]++] = array[i];
	}
	pop();

	for (int i = 0; i < MAX; i++) {
		int num = array[i] / 100;
		queue[num][front[num]++] = array[i];
	}
	pop();
}

void pop() {
	int cnt = 0;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < front[i]; j++) {
			array[cnt] = queue[i][rear[i]++];
			cnt++;
		}
	}

	for (int i = 0; i < MAX; i++) {
		front[i] = 0;
		rear[i] = 0;
	}
}

void print() {
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
		printf(" %d", array[i]);	

	printf("\n\n");
}