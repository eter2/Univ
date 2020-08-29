// Grpah

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int vertex;
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

Node* newNode(int vertex);
Graph* createGraph(int v);
void addEdge(int from, int to);
void push(int num);
int pop();
void topSort();
void print();

Node* v0 = newNode(0);
Node* v1 = newNode(1);
Node* v2 = newNode(2);
Node* v3 = newNode(3);
Node* v4 = newNode(4);
Node* v5 = newNode(5);
Node* list[6] = { v0, v1, v2, v3, v4, v5 };
Graph* graph = createGraph(6);

int answer[6];
int count = 0;
int queue[100];
int top = -1;
int rear = -1;
int visited[6];

int main() {
	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(2, 3);
	addEdge(2, 5);
	addEdge(3, 5);
	addEdge(4, 5);

	push(0);
	push(1);
	topSort();
	print();

	return 0;
}

Node* newNode(int vertex) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->num = 0;
	node->vertex = vertex;
	node->next = NULL;
	return node;
}

Graph* createGraph(int v) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->v = v;

	graph->array = (List*)malloc(v * sizeof(List));

	graph->array[0].head = v0;
	graph->array[1].head = v1;
	graph->array[2].head = v2;
	graph->array[3].head = v3;
	graph->array[4].head = v4;
	graph->array[5].head = v5;

	return graph;
}

void addEdge(int from, int to) {
	Node* node = newNode(to);
	if (graph->array[from].head->next == NULL)
		graph->array[from].head->next = node;
	else {
		Node* temp = graph->array[from].head->next;

		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = node;
	}

	++(list[to]->num);
}

void push(int num) {
	queue[++top] = num;
}

int pop() {
	return queue[++rear];
}

void topSort() {
	if (top != -1 && top == rear) return;

	int temp = pop();
	Node* node = graph->array[temp].head;

	if (list[temp]->num == 0) {
		answer[count] = temp;
		count++;
		visited[temp] = 1;

		while (node != NULL) {
			--(list[node->vertex]->num);

			node = node->next;
		}
	}

	node = graph->array[temp].head;
	while (node != NULL) {
		if (visited[list[node->vertex]->vertex] == 0)
			push(node->vertex);
		node = node->next;
	}

	topSort();
}

void print() {
	printf("Topological sort의 결과:\n\nvertex %d", answer[0]);
	for (int i = 1; i < count; i++)
		printf("->vertex %d", answer[i]);
	printf("\n");
}