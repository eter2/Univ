// List
// 단순연결리스트에 있는 모든 노드의 데이터값의 합

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* newNode(int data);
void addNode(Node** head, Node* node);
int sum(Node* node);

int main() {
	int n = 0;
	int data = 0;
	Node* head = NULL;

	printf("노드의 개수: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("노드 #%d 데이터: ", i + 1);
		scanf("%d", &data);

		addNode(&head, newNode(data));
	}

	printf("연결 리스트의 데이터 합은 = %d", sum(head));

	return 0;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void addNode(Node** head, Node* node) {
	Node* temp;

	if (*head == NULL) {
		*head = node;
	}
	else {
		temp = *head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = node;
	}
}

int sum(Node* node) {
	int sumNum = 0;
	while (node != NULL) {
		sumNum += node->data;
		node = node->next;
	}

	return sumNum;
}