// Graph

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char v[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
int visited[7] = { 0 };
int cost[7] = { 0 };
int edge[7] = { 0 };
int graph[7][7] = {
	{ 0, 3, 0, 0, 0, 2, 0 },
	{ 3, 0, 17, 16, 0, 0, 0 },
	{ 0, 17, 0, 8, 0, 0, 0 },
	{ 0, 16, 8, 0, 11, 0, 4 },
	{ 0, 0, 0, 11, 0, 2, 10 },
	{ 2, 0, 0, 0, 2, 0, 0 },
	{ 0, 0, 0, 4, 10, 0, 0 }
};

void Dijkstra(int src, int dest);
void print(int src, int dest);

int main() {
	char src[2];
	char dest[2];
	printf("출발 vertex를 입력하세요: ");
	scanf("%s", &src);
	printf("도착 vertex를 입력하세요: ");
	scanf("%s", &dest);

	int srcInt, destInt;
	for (int i = 0; i < 7; i++) {
		char c[2];
		c[0] = v[i];
		c[1] = '\0';

		if (!strcmp(src, c)) {
			srcInt = i;
		}

		if (!strcmp(dest, c)) {
			destInt = i;
		}
	}

	Dijkstra(srcInt, destInt);

	return 0;
}

void Dijkstra(int src, int dest) {
	int idx = src;
	visited[idx] = 1;

	int cnt = 0;
	while (cnt < 6) {
		for (int i = 0; i < 7; i++) {
			if (graph[idx][i] == 0 || visited[i] == 1) continue;

			int num = cost[idx] + graph[idx][i];

			if (cost[i] == 0 && num != 0) {
				cost[i] = num;
				edge[i] = idx;
			}
			if (cost[i] > num) {
				cost[i] = num;
				edge[i] = idx;
			}
		}

		int min = 100;
		for (int i = 0; i < 7; i++) {
			if (cost[i] == 0 || visited[i] == 1) continue;

			if (min > cost[i]) {
				idx = i;
				min = cost[i];
			}
		}

		visited[idx] = 1;
		cnt++;
	}

	print(src, dest);
	printf("이때 최단 거리는 %d입니다.\n", cost[dest]);
}

void print(int src, int dest) {
	printf("Vertex %c에서 Vertex %c로 가는 최단 경로는", v[src], v[dest]);
	int idx = dest;
	int vertex[7];
	int cnt = 0;

	while (1) {
		vertex[cnt] = idx;
		cnt++;
		if (idx == src) break;
		idx = edge[idx];
	}
	for (int i = cnt - 1; i > -1; i--) {
		printf(" %c", v[vertex[i]]);
	}
	printf("이며, ");
}