// Sorting

#define _CRT_SECURE_NO_WARNINGS
#define MAX 12
#include <stdio.h>

int array[MAX] = {104, 101, 90, 88, 69, 10, 30, 2, 16, 8, 31, 22 };
int num = MAX;

void heapSort();
void maxHeap(int max);
void heap(int n);
void print();
int max(int a, int b);
void swap(int a, int b);

int main() {
	printf("정렬할 데이터:");
	print();

	heapSort();

	printf("Heap sort를 수행한 결과:");
	print();

	return 0;
}

void heapSort() {
	maxHeap(num);

	for (int i = MAX - 1; i >= 0; i--) {
		swap(0, i);
		num--;
		heap(0);
	}
}

void maxHeap(int n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heap(i);
	}
}

void heap(int n) {
	if ((n * 2) + 1 >= num) return;

	int idx;
	if ((n * 2) + 2 >= num)
		idx = (n * 2) + 1;
	else
		idx = max((n * 2) + 1, (n * 2) + 2);

	if (array[idx] > array[n]) {
		swap(idx, n);
		heap(idx);
	}
}

void print() {
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
		printf(" %d", array[i]);	

	printf("\n\n");
}

int max(int a, int b) {
	return array[a] > array[b] ? a : b;
}

void swap(int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
