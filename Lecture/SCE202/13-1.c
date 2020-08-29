// Sorting

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int array[12] = { 104, 101, 90, 88, 69, 10, 30, 2, 16, 8, 31, 22 };

void quick(int left, int right);
void print();
void swap(int a, int b);

int main() {
	printf("정렬할 데이터:");
	print();

	quick(0, sizeof(array) / sizeof(int) - 1);

	printf("Quick sort를 수행한 결과:");
	print();

	return 0;
}

void quick(int left, int right) {
	if (left > right) return;

	int pivot = array[left];
	int leftIdx = left + 1, rightIdx = right;
	if (left + 1 == right) {
		if (array[left] > array[right])
			swap(left, right);

		return;
	}

	while (leftIdx < rightIdx) {
		for (int j = rightIdx; j >= leftIdx; j--) {
			rightIdx = j;
			if (array[j] < pivot) 
				break;
		}

		for (int i = leftIdx; i <= rightIdx; i++) {
			leftIdx = i;
			if (array[i] > pivot)
				break;
		}

		if (leftIdx == right || rightIdx == left + 1) 
			break;

		swap(leftIdx, rightIdx);
	}

	if (rightIdx == left + 1) {
		if (array[left] > array[rightIdx]) {
			swap(left, rightIdx);
			quick(left + 2, right);
		}
		else 
			quick(left + 1, right);
	}
	else {
		swap(left, rightIdx);
		quick(left, rightIdx - 1);
		quick(rightIdx + 1, right);
	}
}

void print() {
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
		printf(" %d", array[i]);	

	printf("\n\n");
}

void swap(int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}