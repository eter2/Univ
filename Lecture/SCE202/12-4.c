// Sorting

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int array[12] = { 104, 101, 90, 88, 69, 10, 30, 2, 16, 8, 31, 22 };

void selection(int n);
void print();

int main() {
	printf("정렬할 데이터:");
	print();

	selection(1);

	printf("Selection sort를 수행한 결과:");
	print();

	return 0;
}

void selection(int n) {
	if (n == (sizeof(array) / sizeof(int))) return;

	int idx = n - 1;
	int min = array[n - 1];

	for (int i = n - 1; i < sizeof(array) / sizeof(int); i++) {
		if (min > array[i]) {
			min = array[i];
			idx = i;
		}
	}

	int temp = array[n - 1];
	array[n - 1] = array[idx];
	array[idx] = temp;

	selection(n + 1);
}

void print() {
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		printf(" %d", array[i]);
	}

	printf("\n\n");
}