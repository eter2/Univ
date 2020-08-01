// Graph

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
	int v1;
	int v2;
	int weight;
} Edge;

Edge* edge[12] = { 0 };
int parent[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

Edge* newEdge(int v1, int v2, int weight);
void SimpleUnion(int i, int j);
int SimpleFind(int i);
void Kruskal();

int main() {
	edge[0] = newEdge(0, 7, 1);
	edge[1] = newEdge(1, 5, 2);
	edge[2] = newEdge(3, 7, 3);
	edge[3] = newEdge(1, 2, 4);
	edge[4] = newEdge(4, 5, 5);
	edge[5] = newEdge(0, 3, 6);
	edge[6] = newEdge(2, 5, 7);
	edge[7] = newEdge(4, 7, 8);
	edge[8] = newEdge(5, 6, 9);
	edge[9] = newEdge(0, 1, 10);
	edge[10] = newEdge(2, 3, 11);
	edge[11] = newEdge(6, 7, 12);

	printf("Kruskal's algorithm을 이용한 minimum cost spanning tree 생성: T={");
	Kruskal();
	printf(" }\n");

	return 0;
}

Edge* newEdge(int v1, int v2, int weight) {
	Edge* edge = (Edge*)malloc(sizeof(Edge));
	edge->v1 = v1;
	edge->v2 = v2;
	edge->weight = weight;

	return edge;
}

void SimpleUnion(int i, int j) {
	while (1) {
		if (parent[i] == i) break;
		i = parent[i];
	}

	parent[i] = j;
}

int SimpleFind(int i) {
	while (1) {
		if (parent[i] == i) break;
		i = parent[i];
	}

	return parent[i];
}

void Kruskal() {
	for (int i = 0; i < 12; i++) {
		int root1 = SimpleFind(edge[i]->v1);
		int root2 = SimpleFind(edge[i]->v2);

		if (root1 != root2) {
			printf(" (%d,%d)", edge[i]->v1, edge[i]->v2);
			SimpleUnion(edge[i]->v1, edge[i]->v2);
		}
	}
}