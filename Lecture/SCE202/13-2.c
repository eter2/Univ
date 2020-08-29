// Sorting

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int array[12] = { 104, 101, 90, 88, 69, 10, 30, 2, 16, 8, 31, 22 };
int sorted[12];

void mergeSort(int start, int end);
void merge(int start, int end);
void print();

int main() {
	printf("정렬할 데이터:");
	print();

	mergeSort(0, sizeof(array)/sizeof(int) - 1);

	printf("Merge sort를 수행한 결과:");
	print();

	return 0;
}

void mergeSort(int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	merge(start, end);
}

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int idx1 = start, idx2 = mid + 1;
	int idx = start;

	while (idx1 <= mid && idx2 <= end) {
		if (array[idx1] < array[idx2]) {
			sorted[idx] = array[idx1];
			idx1++;
		}
		else {
			sorted[idx] = array[idx2];
			idx2++;
		}

		idx++;
	}

	if (idx1 > mid) {
		for (int i = idx2; i <= end; i++) {
			sorted[idx] = array[i];
			idx++;
		}
	}
	else {
		for (int i = idx1; i <= mid; i++) {
			sorted[idx] = array[i];
			idx++;
		}
	}

	for (int i = start; i <= end; i++) {
		array[i] = sorted[i];
	}
}

void print() {
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
		printf(" %d", array[i]);	

	printf("\n\n");
}