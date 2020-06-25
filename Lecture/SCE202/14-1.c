// Sorting
// 0,1,2로만 이루어진 Array를 record의 key값을 비교하지 않고
// 0은 index 0부터, 2는 가장 큰 index부터 배치하여 정렬

#define _CRT_SECURE_NO_WARNINGS
#define MAX 12
#include <stdio.h>

void sorting(int arr[]);
void print(int arr[]);

int main() {
	int arr[MAX] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	print(arr);
	sorting(arr);
	print(arr);

	return 0;
}

void sorting(int arr[]) {
	int cnt;

	for (int i = 0; i < MAX; i++) {
		if (arr[i] != 0) {
			for (int j = i + 1; j < MAX; j++) {
				if (arr[j] == 0) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;

					cnt = i;
				}
			}
		}
	}

	for (int i = MAX - 1; i > cnt; i--) {
		if (arr[i] != 2) {
			for (int j = i - 1; j > cnt; j--) {
				if (arr[j] == 2) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}

void print(int arr[]) {
	for (int i = 0; i < MAX; i++)
		printf("%d ", arr[i]);

	printf("\n");
}
