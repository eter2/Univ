#pragma warning(disable: 4996)
#include <stdio.h>
#define MAX 60

int getMax(int array[][MAX], int x, int y, int k);

int main() {
	int n, k, s, z;
	int image[MAX][MAX] = {};

	scanf("%d", &n);
	scanf("%d %d %d", &k, &s, &z);
	for (int i = z; i < n + z; i++)
		for (int j = z; j < n + z; j++)
			scanf("%d", &image[i][j]);
	
	int width = (n + z * 2 - k) / s + 1;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++)
			printf("%s%d", j == 0 ? "" : ",", getMax(image, i * s, j * s, k));
		printf("\n");
	}
	
	return 0;
}

int getMax(int array[][MAX], int x, int y, int k) {
	int max = array[x][y];
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			max = max < array[i][j] ? array[i][j] : max;
		}
	}
	return max;
}