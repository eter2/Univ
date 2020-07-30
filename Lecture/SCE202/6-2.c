// Tree

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sumNum = 0;

typedef struct Node {
	Node* leftChild;
	int data;
	Node* rightChild;

} Node;

void postOrder(Node* node);
void print(Node* node);


int main() {
	Node n[11];
	n[7] = { NULL, 100, NULL };
	n[8] = { NULL, 150, NULL };
	n[9] = { NULL, 50, NULL };
	n[10] = { NULL, 150, NULL };
	n[3] = { &n[7], 2, &n[8] };
	n[4] = { NULL, 15, NULL };
	n[5] = { NULL, 40, NULL };
	n[6] = { &n[9], 70, &n[10] };
	n[1] = { &n[3], 0, &n[4] };
	n[2] = { &n[5], 10, &n[6] };
	n[0] = { &n[1], 0, &n[2] };

	print(&n[0]);

	return 0;
}

void postOrder(Node* node) {
	if (node == NULL) return;

	postOrder(node->leftChild);
	postOrder(node->rightChild);
	sumNum += node->data;
}

void print(Node* node) {
	Node* temp;

	temp = node->leftChild;
	postOrder(temp);
	printf("C:의 용량:%dM입니다.\n", sumNum);

	sumNum -= sumNum;
	temp = node->rightChild;
	postOrder(temp);
	printf("D:의 용량:%dM입니다.\n", sumNum);

	sumNum -= sumNum;
	temp = node;
	postOrder(temp);
	printf("내컴퓨터의 전체용량: %dM입니다.\n", sumNum);
}