// Tree

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	short int leftThread;
	Node* leftChild;
	char data;
	Node* rightChild;
	short int rightThread;

} Node;

Node* insucc(Node* tree);
void tinorder(Node* tree);

int main() {
	Node n1 = { 0, NULL, 'G', NULL, 0 };
	Node n2 = { 0, NULL, 'C', NULL, 0 };
	Node n3 = { 0, NULL, 'F', NULL, 0 };
	Node n4 = { 1, &n1, 'A', &n2, 1 };
	Node n5 = { 1, &n2, 'B', &n1, 1 };
	Node n6 = { 1, &n1, 'D', &n3, 1 };
	Node n7 = { 1, &n3, 'E', &n1, 1 };
	n1.leftChild = &n2;
	n1.rightChild = &n3;
	n2.leftChild = &n4;
	n2.rightChild = &n5;
	n3.leftChild = &n6;
	n3.rightChild = &n7;

	printf("Inorder traversal of a threaded binary tree: ");
	tinorder(&n4);

	return 0;
}

Node* insucc(Node* tree) {
	Node* temp = tree->rightChild;
	if (!tree->rightThread) {
		while (!temp->leftThread) temp = temp->leftChild;
	}

	return temp;
}

void tinorder(Node* tree) {
	Node* temp = tree;
	while (1) {
		if (temp->data == 'E') {
			printf("%c", temp->data);
			break;
		}
		printf("%c->", temp->data);
		temp = insucc(temp);
	}
}