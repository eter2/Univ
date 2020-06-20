// List
// 단순연결리스트에 입력받은 정수값의 최대값과 최소값

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* newNode(int data);
void addNode(Node** head, Node* node);
int max(Node* node);
int min(Node* node);

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

	printf("max = %d, min = %d", max(head), min(head));

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

int max(Node* node) {
	int maxNum = 0;
	while (node != NULL) {
		if (maxNum < node->data) maxNum = node->data;
		node = node->next;
	}

	return maxNum;
}

int min(Node* node) {
	int minNum = node->data;
	while (node != NULL) {
		if (minNum > node->data) minNum = node->data;
		node = node->next;
	}

	return minNum;
}