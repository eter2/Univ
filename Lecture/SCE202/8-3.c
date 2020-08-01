// Graph

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char arr[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
int check[7] = { 0 };
int stack[8];
int top = -1;

typedef struct Node {
	char vertex;
	int num;
	Node* next;
} Node;

typedef struct List {
	Node* head;
} List;

typedef struct Graph {
	int v;
	List* array;
} Graph;

Node* newNode(int num, char vertex);
Graph* createGraph(int v);
void addEdge(Graph* graph, int from, int to);
void print(Graph* graph);

void push(int v);
int pop();
void dfs(Graph* graph, int v);

int main() {
	int v = 7;
	Graph* graph = createGraph(v);
	addEdge(graph, 6, 5);
	addEdge(graph, 4, 6);
	addEdge(graph, 3, 6);
	addEdge(graph, 2, 4);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 1);

	printf("\n Graph의 adjacency list\n");
	print(graph);
	printf("\n");

	printf("\n Depth First Search의 결과: ");
	dfs(graph, 0);
	printf("\n");

	return 0;
}

Node* newNode(int num, char vertex) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->num = num;
	node->vertex = vertex;
	node->next = NULL;
	return node;
}

Graph* createGraph(int v) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->v = v;

	graph->array = (List*)malloc(v * sizeof(List));

	int i = 0;
	for (i = 0; i < v; i++)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(Graph* graph, int from, int to) {
	Node* node = newNode(to, arr[to]);
	node->next = graph->array[from].head;
	graph->array[from].head = node;

	node = newNode(from, arr[from]);
	node->next = graph->array[to].head;
	graph->array[to].head = node;
}

void print(Graph* graph) {
	int v;
	for (v = 0; v < graph->v; ++v) {
		Node* node = graph->array[v].head;
		printf("\n\t vertex %c의 adjacency list", arr[v]);
		while (node)
		{
			printf(" -> %c", node->vertex);
			node = node->next;
		}
	}
}

void push(int v) {
	stack[++top] = v;
}

int pop() {
	return stack[top--];
}

void dfs(Graph* graph, int v) {
	check[v] = 1;
	printf("%c ", arr[v]);
	push(v);

	int numTemp = v;

	List temp = graph->array[v];
	Node* vtxTemp = temp.head;

	while (top != -1) {
		int idx = -1;

		for (int i = 0; i < 7; i++) {
			if (top == -1) {
				return;
			}
			if (vtxTemp == NULL)
			{
				i = 0;
				temp = graph->array[pop()];
				vtxTemp = temp.head;
			}
			if (arr[i] == vtxTemp->vertex) {
				if (check[i] == 1) {
					i = 0;
					vtxTemp = vtxTemp->next;
				}
				else idx = i;
			}
		}

		if (idx == -1) continue;
		else {
			check[idx] = 1;
			printf("%c ", arr[idx]);
			push(idx);
			temp = graph->array[idx];
			vtxTemp = temp.head;
		}
	}
}