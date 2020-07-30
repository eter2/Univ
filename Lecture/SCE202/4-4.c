// Tree

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	Node* left;
	Node* right;
	int data;
} Node;

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void leftPrint(Node* root) {
	while (root != NULL) {
		printf("%d\n", root->data);
		root = root->left;
	}

	printf("NULL");
}

void rightPrint(Node* root) {
	while (root != NULL) {
		printf("%d\n", root->data);
		root = root->right;
	}

	printf("NULL");
}

int main() {
	Node* root = newNode(15);
	root->left = newNode(4);
	root->right = newNode(20);
	root->left->left = newNode(1);
	root->right->left = newNode(16);
	root->right->right = newNode(25);

	printf("[루트의 왼쪽노드들을 모두 출력]\n");
	leftPrint(root);
	printf("\n\n");

	printf("[루트의 오른쪽노드들을 모두 출력]\n");
	rightPrint(root);

	return 0;
}