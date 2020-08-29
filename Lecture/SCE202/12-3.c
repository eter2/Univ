// Sorting

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int array[12] = { 104, 101, 90, 88, 69, 10, 30, 2, 16, 8, 31, 22 };

void bubble(int n);
void print();

int main() {
	printf("정렬할 데이터:");
	print();

	bubble(sizeof(array) / sizeof(int));

	printf("Bubble sort를 수행한 결과:");
	print();

	return 0;
}

void bubble(int n) {
	if (n == 0) return;

	for (int i = 0; i < n - 1; i++) {
		if (array[i] > array[i + 1]) {
			int temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
		}
	}

	bubble(n - 1);
}

void print() {
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		printf(" %d", array[i]);
	}

	printf("\n\n");
}