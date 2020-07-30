// Tree

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	Node* left;
	Node* right;
	int data;
} Node;

Node* newNode(int data);
void inorder(Node* node);
void preorder(Node* node);
void postorder(Node* node);

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

	printf("inorder traversal: ");
	inorder(root);
	printf("\n");

	printf("preorder traversal: ");
	preorder(root);
	printf("\n");

	printf("postorder traversal: ");
	postorder(root);
	printf("\n");

	return 0;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void inorder(Node* node) {
	if (node == NULL) return;

	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}

void preorder(Node* node) {
	if (node == NULL) return;

	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
}

void postorder(Node* node) {
	if (node == NULL) return;

	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);
}
