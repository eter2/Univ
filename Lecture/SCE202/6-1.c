// Tree

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	Node* leftChild;
	int data;
	Node* rightChild;

} Node;

int main() {
	Node n[7];
	n[3] = { NULL, 2, NULL };
	n[4] = { NULL, 12, NULL };
	n[5] = { NULL, 16, NULL };
	n[6] = { NULL, 20, NULL };
	n[1] = { &n[3], 10, &n[4] };
	n[2] = { &n[5], 18, &n[6] };
	n[0] = { &n[1], 15, &n[2] };

	int num;

	printf("���� �Է��Ͻÿ�: ");
	scanf("%d", &num);

	int cnt = 0;

	for (int i = 0; i < 7; i++) {
		if (n[i].data < num) {
			printf("%d���� ���� ���: %d\n", num, n[i].data);
			cnt++;
		}
	}

	if(cnt == 0) printf("�Է��� %d���� ���� ���� ���� ���� �����ϴ�.", num);

	return 0;
}