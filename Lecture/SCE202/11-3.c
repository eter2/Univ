// Grpah

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int distance[7][7] = {
	{ 0, 7, -1, -1, 3, 10, -1 },
	{ 7, 0, 4, 10, 2, 6, -1 },
	{ -1, 4, 0, 2, -1, -1, -1 },
	{ -1, 10, 2, 0, 11, 9, 4 },
	{ 3, 2, -1, 11, 0, -1, 5 },
	{ 10, 6, -1, 9, -1, 0, -1 },
	{ -1, -1, -1, 4, 5, -1, 0 }
};

void  allcosts();
void print();

int main() {
	allcosts();
	print();

	return 0;
}

void  allcosts() {
	int i, j, k;

	for (k = 0; k < 7; k++) {
		for (i = 0; i < 7; i++) {
			for (j = 0; j < 7; j++) {
				if (distance[i][k] == -1 || distance[k][j] == -1) continue;

				if (distance[i][j] == -1)
					distance[i][j] = distance[i][k] + distance[k][j];
				else if (distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
}

void print() {
	printf("==============================\n");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%4d", distance[i][j]);
		}
		printf("\n");
	}
	printf("==============================\n");
}

