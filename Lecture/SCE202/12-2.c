// Sorting

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int array[12] = { 104, 101, 90, 88, 69, 10, 30, 2, 16, 8, 31, 22 };

void insertion(int n);
void print();

int main() {
	printf("정렬할 데이터:");
	print();

	insertion(0);

	printf("insertion sort를 수행한 결과:");
	print();

	return 0;
}

void print() {
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		printf(" %d", array[i]);
	}

	printf("\n\n");
}

void insertion(int n) {
	if (n == sizeof(array) / sizeof(int)) return;

	int temp = array[n];

	for (int i = n; i >= 0; i--) {
		if (array[i] > temp) {
			array[i + 1] = array[i];
			array[i] = temp;
		}
	}

	insertion(n + 1);
}