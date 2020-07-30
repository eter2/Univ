// Tree

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTS 16
#include <stdio.h>
#include <string.h>

int parent[MAX_ELEMENTS] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

void SimpleUnion(int i, int j) {
	while (1) {
		if (parent[i] == i) break;
		i = parent[i];
	}

	parent[i] = j;
}

int SimpleFind(int i) {
	while (1) {
		if (parent[i] == i) break;
		i = parent[i];
	}
	
	return parent[i];
}

void print() {
	for (int i = 1; i < MAX_ELEMENTS; i++) {
		int temp = i;
		while (1) {
			if (parent[temp] == temp) break;
			temp = parent[temp];
		}

		printf("노드 %d의 root는 %d\n", i, parent[temp]);
	}
}

int main() {
	SimpleUnion(1, 2);
	SimpleUnion(1, 3);
	SimpleUnion(3, 4);
	SimpleUnion(5, 7);
	SimpleUnion(9, 10);
	SimpleUnion(12, 13);
	SimpleUnion(13, 14);

	printf("[현재 각 노드의 root를 출력]\n\n");
	print();

	char flag[10] = "Y";

	printf("\n\n[두 노드가 같은 집합에 속하였는지 서로 다른 집합에 속하였는지 여부를 출력]\n");

	while (strcmp(flag, "N")) {
		int node1, node2;
		printf("\n두 개 노드 입력(형식: 노드1 노드2): ");
		scanf("%d %d", &node1, &node2);

		while (node1 > 15 || node2 > 15) {
			printf("ERROR!\n");
			printf("다시 두 개 노드 입력(형식: 노드1 노드2): ");
			scanf("%d %d", &node1, &node2);
		}

		int root1 = SimpleFind(node1);
		int root2 = SimpleFind(node2);

		if (root1 == root2) {
			printf("\n노드 %d과 노드 %d는 같은 집합에 속한 노드들입니다.\n", node1, node2);
		}
		else {
			printf("\n노드 %d과 노드 %d는 서로 다른 집합의 노드들입니다.\n", node1, node2);
		}
		printf("\n더 입력하려면 Y, 그만하려면 N을 입력하세요: ");
		scanf("%s", flag);

		while (strcmp(flag, "Y") && strcmp(flag, "N")) {
			printf("잘못 입력하였습니다. 다시 입력하세요\n");
			printf("\n더 입력하려면 Y, 그만하려면 N을 입력하세요: ");
			scanf("%s", flag);
		}
	}

	return 0;
}