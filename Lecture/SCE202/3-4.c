// List
// 정수가 순차적으로 입력될 때 조건에 맞게 처리하는 프로그램
// 1) 오름차순으로 삽입하는 단순연결리스트
// 2) 1)에서 구현한 리스트를 역순으로 변환

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* newNode(int data);
Node* insert(Node* head, Node* node);
Node* reverse(Node* head);
void print(Node* node);

int main() {
	int data = 0;
	Node* head = NULL;

	char flag[2] = "Y";

	while (!strcmp(flag, "Y")) {
		printf("정수를 입력하시오: ");
		scanf("%d", &data);

		head = insert(head, newNode(data));

		printf("더 입력하시겠습니까? (Y / N) ");
		scanf("%s", &flag);
	}
	printf("오름차순 리스트: ");
	print(head);

	head = reverse(head);
	printf("역순 리스트: ");
	print(head);

	return 0;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

Node* insert(Node* head, Node* node) {
	if (head == NULL) return node;

	Node* temp = head;
	Node* prev = NULL;
	while (temp != NULL && temp->data <= node->data) {
		prev = temp;
		temp = temp->next;
	}
	if (prev == NULL) {
		node->next = head;
		return node;
	}
	else {
		prev->next = node;
		node->next = temp;
		return head;
	}

}

Node* reverse(Node* head) {
	if (head == NULL) return head;

	Node* nxt = NULL;
	Node* nhd = NULL;

	while (head) {
		nxt = head->next;
		head->next = nhd;
		nhd = head;
		head = nxt;
	}

	return nhd;
}

void print(Node* head) {
	Node* temp = head;
	printf("%d", temp->data);
	temp = temp->next;
	while (temp != NULL) {
		printf("-%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}