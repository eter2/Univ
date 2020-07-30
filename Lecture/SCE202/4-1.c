// List

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* prev;
	int data;
	struct Node* next;
} Node;

Node* newNode(int data);
void addNode(Node** head, Node* node);
void print(Node* head);
void search(Node* node, int num);

int main() {
	int n = 0;
	int data = 0;
	int searchNum = 0;
	Node* head = NULL;

	printf("노드의 개수: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("노드 #%d 데이터: ", i + 1);
		scanf("%d", &data);

		addNode(&head, newNode(data));
	}
	
	print(head);

	printf("탐색할 값: ");
	scanf("%d", &searchNum);
	search(head, searchNum);

	return 0;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

void addNode(Node** head, Node* node) {
	if (*head == NULL) {
		*head = node;
	}
	else {
		Node* temp = *head;
		temp->prev = node;
		node->next = *head;
		*head = node;
	}
}

void print(Node* head) {
	while (head != NULL) {
		printf("<-|%d|-> ", head->data);
		head = head->next;
	}

	printf("\n");
}

void search(Node* node, int num) {
	int flag = 0;
	
	while (node != NULL) {
		if (num == node->data) {
			flag = 1;
			break;
		}		
		node = node->next;
	}

	if (flag) {
		printf("값이 리스트 안에 있습니다\n");
	}
	else printf("값이 리스트 안에 없습니다.\n");
}