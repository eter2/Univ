// Graph

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int visited[8] = { 0 };
int minNode[8];
int edge[7][2];
int cost[8];
int graph[8][8] = {
	{ 0, 10, 0, 6, 0, 0, 0, 1 },
	{ 10, 0, 4, 0, 0, 2, 0, 0 },
	{ 0, 4, 0, 11, 0, 7, 0, 0 },
	{ 6, 0, 11, 0, 0, 0, 0, 3 },
	{ 0, 0, 0, 0, 0, 5, 0, 8 },
	{ 0, 2, 7, 0, 5, 0, 9, 0 },
	{ 0, 0, 0, 0, 0, 9, 0, 12 },
	{ 1, 0, 0, 3, 8, 0, 12, 0 }
};

void Prim();

int main() {

	printf("Prim's algorithm을 이용한 minimum cost spanning tree 생성:\n\nTV={");
	Prim();

	return 0;
}

void Prim() {
	printf("0");
	visited[0] = 1;

	int idx = 0;
	int min = 0;

	while (idx < 7) {
		for (int i = 0; i < 8; i++) {
			if (graph[min][i] == 0) continue;

			if (cost[i] == 0 && graph[min][i] != -1) {
				cost[i] = graph[min][i];
				minNode[i] = min;
			}

			if (cost[i] > graph[min][i]) {
				cost[i] = graph[min][i];
				minNode[i] = min;
			}
		}

		int minCost = 100;

		for (int i = 0; i < 8; i++) {
			if (cost[i] == 0) continue;

			if (minCost > cost[i] && visited[i] == 0) {
				min = i;
				minCost = cost[i];
			}
		}

		edge[idx][0] = minNode[min];
		edge[idx][1] = min;
		visited[min] = 1;
		printf(", %d", min);

		idx++;
	}

	printf("}, T={");
	for (int i = 0; i < 7; i++) {
		printf(" (%d,%d)", edge[i][0], edge[i][1]);
	}
	printf(" }\n");
}