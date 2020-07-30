// Tree

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	char name[20];
	int age;
	char region[20];
	char gender[7];
	char phone[14];
} element;

typedef struct Node {
	element data;
	Node* left;
	Node* right;
} Node;

int numFlag;

Node* newNode(element data);
Node* search(Node* root, element data);
Node* insert(Node* root, Node* node);
void deleteNode(Node* root, element data);

int main() {
	Node* root = NULL;

	while (1) {
		char flag[2];
		printf("회원정보입력(i), 회원정보검색(s), 회원정보삭제(d): ");
		scanf("%s", &flag);

		if (!strcmp(flag, "i")) {
			element data;
			printf("회원 이름: ");
			scanf("%s", data.name);
			printf("회원 나이: ");
			scanf("%d", &data.age);
			printf("회원 지역: ");
			scanf("%s", data.region);
			printf("회원 성별: ");
			scanf("%s", data.gender);
			printf("회원 전화번호: ");
			scanf("%s", data.phone);
			root = insert(root, newNode(data));
			printf("\n");
		}

		if (!strcmp(flag, "s")) {
			element data;
			printf("회원 이름: ");
			scanf("%s", data.name);
			
			Node* result = search(root, data);

			if (numFlag != 0) {
				printf("잘못된 이름입니다.\n\n");
				continue;
			}

			printf("\n회원 %s의 정보는 다음과 같습니다.\n\n", data.name);
			printf("회원 이름: %s\n", result->data.name);
			printf("회원 나이: %d\n", result->data.age);
			printf("회원 지역: %s\n", result->data.region);
			printf("회원 성별: %s\n", result->data.gender);
			printf("회원 전화번호: %s\n\n", result->data.phone);
		}

		if (!strcmp(flag, "d")) {
			element data;
			printf("회원 이름: ");
			scanf("%s", data.name);

			deleteNode(root, data);
			if (root == NULL) 
				continue;
			if (numFlag != 0) {
				printf("삭제할 수 없습니다.\n\n");
				continue;
			}

			printf("회원 %s의 정보가 삭제되었습니다.\n\n", data.name);
		}
	}
	return 0;
}

Node* newNode(element data) {
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node* search(Node* root, element data) {
	if (root == NULL) {
		return root;
	}

	int result = strcmp(root->data.name, data.name);
	numFlag = result;

	while (!(root->left == NULL && root->right == NULL)) {
		if (result == 0) {
			return root;
		}

		if (result == 1) {
			if (root->left == NULL)
				break;

			return search(root->left, data);
		}

		if (result == -1) {
			if (root->right == NULL)
				break;

			return search(root->right, data);
		}
	}

	return root;
}


Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;

	Node* temp = search(root, node->data);
	if (numFlag == 0) {
		printf("같은 이름이 이미 있습니다.\n");
		return root;
	}

	if (numFlag == 1) {
		temp->left = node;
	}

	if (numFlag == -1) {
		temp->right = node;
	}

	return root;
}

void deleteNode(Node* root, element data) {
	if (root == NULL) {
		printf("삭제할 수 없습니다.\n\n");
		return;
	}

	Node* temp = search(root, data);

	if (numFlag != 0)
		return;

	// leaf일 때
	if (temp->left == NULL && temp->right == NULL) {
		*temp->data.name = NULL;
		return;
	}

	// left child와 right child 모두 있을 때
	if (temp->left != NULL && temp->right != NULL) {
		Node* right = temp->right;

		if (right->left == NULL) {
			right->left = temp->left;
			*temp = *right;
			return;
		}

		while (right->left->left) right = right->left;

		if (right->left->right == NULL) {
			right->left->right = temp->right;
			right->left->left = temp->left;
			*temp = *right->left;
			return;
		}

		if (right->left->right != NULL) {
			Node* rightTemp = right->left;
			*right->left = *right->left->right;
			rightTemp->left = temp->left;
			rightTemp->right = temp->right;
			*temp = *rightTemp;
			return;
		}
	}

	// left child와 right child 둘 중 하나만 있을 때
	if (temp->left == NULL || temp->right == NULL) {
		if (temp->left != NULL) {
			Node* left = temp->left;

			if (left->right == NULL) {
				*temp = *left;
				return;
			}

			while (left->right->right) left = left->right;

			if (left->right->left == NULL) {
				left->right->left = temp->left;
				*temp = *left->right;
				left->right = NULL;
				return;
			}

			if (left->right->left != NULL) {
				Node* leftTemp = left->right;
				*left->right = *left->right->left;
				leftTemp->left = temp->left;
				*temp = *leftTemp;
				return;
			}
		}

		if (temp->right != NULL) {
			Node* right = temp->right;

			if (right->left == NULL) {
				*temp = *right;
				return;
			}

			while (right->left->left) right = right->left;

			if (right->left->right == NULL) {
				right->left->right = temp->right;
				*temp = *right->left;
				right->left = NULL;
				return;
			}

			if (right->left->right != NULL) {
				Node* rightTemp = right->left;
				*right->left = *right->left->right;
				rightTemp->right = temp->right;
				*temp = *rightTemp;
				return;
			}
		}
	}
}