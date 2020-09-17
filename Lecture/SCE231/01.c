// merge sort

#define _CRT_SECURE_NO_WARNINGS
#define MAX 8
#include <stdio.h>
int flag = 0;

void merge_sort(int arr[], int temp[], int start, int end);
void merge(int arr[], int temp[], int start, int end);
void print(int arr[]);

int main() {
	int arr[MAX];

	printf("----------------\n");
	scanf("%d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);
	int temp[MAX];
	merge_sort(arr, temp, 0, MAX - 1);
	printf("----------------");

	return 0;
}

void merge_sort(int arr[], int temp[], int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	merge_sort(arr, temp, start, mid);
	merge_sort(arr, temp, mid + 1, end);
	merge(arr, temp, start, end);

	print(arr);
}

void merge(int arr[], int temp[], int start, int end) {
	int mid = (start + end) / 2;
	int idx = start, idx1 = start, idx2 = mid + 1;

	while (idx1 <= mid && idx2 <= end) {
		if (arr[idx1] < arr[idx2]) {
			temp[idx] = arr[idx1];
			idx1++;
		}
		else {
			temp[idx] = arr[idx2];
			idx2++;
		}

		idx++;
	}

	if (idx1 > mid) {
		for (int i = idx2; i <= end; i++) {
			temp[idx] = arr[i];
			idx++;
		}
	}
	else {
		for (int i = idx1; i <= mid; i++) {
			temp[idx] = arr[i];
			idx++;
		}
	}

	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}

void print(int arr[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}