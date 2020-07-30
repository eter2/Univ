// List

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int base;
	int exp;
	Node* next;
} Node;

Node* newNode(int base, int exp);
void addNode(Node** head, Node* node);
void insert(Node* poly1, Node* poly2);
void polyAdd(Node* poly1, Node* poly2);
void print(Node* head);

int main() {
	Node* head[2];
	head[0] = NULL;
	head[1] = NULL;

	for (int i = 0; i < 2; i++) {
		int base, exp;
		char c;
		printf("\n다항식%d 입력: ", i + 1);
		scanf("%d^%d", &base, &exp);
		addNode(&head[i], newNode(base, exp));
		scanf("%c", &c);
		while (c != '\n') {
			scanf("%d^%d", &base, &exp);
			addNode(&head[i], newNode(base, exp));
			scanf("%c", &c);
		}
	}
	
	polyAdd(head[0], head[1]);
	printf("\n차= ");
	print(head[0]);
	printf("\n");

	return 0;
}

Node* newNode(int base, int exp) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->base = base;
	node->exp = exp;
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

void insert(Node* poly1, Node* poly2) {
	Node* temp = poly2;
	Node* prev = NULL;

	while (poly1->exp > poly2->exp) {
		prev = poly1;
		poly1 = poly1->next;
	}
	if (prev != NULL) {
		prev->next = poly2;
		poly2->next = poly1;
	}
}

void polyAdd(Node* poly1, Node* poly2) {
	Node* temp;
	Node* temp2 = poly2;
	Node* prev = NULL;

	if (poly1->next == NULL) {
		poly2->base = -poly2->base;
		poly1->next = poly2;
		return;
	}

	while (temp2 != NULL) {
		temp = poly1;
		while (temp != NULL) {
			if (temp->exp == temp2->exp) {
				temp->base -= temp2->base;
				break;
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
	}

	temp2 = poly2;
	while (temp2 != NULL) {
		temp = poly1;
		while (temp != NULL) {
			if (temp->exp == temp2->exp) break;

			if (temp->exp < temp2->exp) {
				insert(poly1, newNode(-temp2->base, temp2->exp));
				break;
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
	}
}

void print(Node* head) {
	Node* temp = head;

	while (temp->next != NULL) {
		printf("%d^%d + ", temp->base, temp->exp);
		temp = temp->next;
	}

	printf("%d^%d", temp->base, temp->exp);
}
