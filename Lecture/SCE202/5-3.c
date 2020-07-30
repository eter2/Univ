#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct Node {
	Node* left;
	char data;
	Node* right;
} Node;

int front = -1;
int rear = -1;
Node* queue[MAX];

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void enqueue(Node* node) {
	if ((rear + 1) % MAX == front) {
		printf("Queue is full.\n");
		return;
	}
	rear = (rear + 1) % MAX;
	queue[rear] = node;
}

Node* dequeue() {
	if (front == rear) {
		printf(" ");
	}
	else {
		front = (front + 1) % MAX;
		Node* node = queue[front];
		return node;
	}
}

void levelOrder(Node* node) {
	if (node == NULL) return;

	enqueue(node);

	while (1) {
		Node* temp = dequeue();

		printf("%d ", temp->data);
		if (temp->left != NULL) enqueue(temp->left);
		if (temp->right != NULL) enqueue(temp->right);

		if (front == rear) break;
	}
}

int main() {
	Node* root = newNode(6);
	root->left = newNode(4);
	root->left->left = newNode(2);
	root->left->left->left = newNode(1);
	root->left->left->right = newNode(3);
	root->left->right = newNode(5);
	root->right = newNode(9);
	root->right->left = newNode(7);
	root->right->right = newNode(10);
	root->right->right->left = newNode(8);
	root->right->right->right = newNode(11);

	printf("Level order traversal: ");
	levelOrder(root);

	return 0;
}