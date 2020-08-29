// Grpah

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cost[5] = { 0 };
int change[5] = { 1, 0, 0, 0, 0 };
int cnt = 0;
int top = -1;
int rear = -1;
int queue[100] = { 0 };
int matrix[5][5] = {
	{ 0, 6, 0, 7, 0 },
	{ 0, 0, 5, 8, -4 },
	{ 0, -2, 0, 0, 0 },
	{ 0, 0, -3, 0, 9 },
	{ 2, 0, 7, 0, 0 }
};

void BF(int start);
void push(int num);
int pop();

int main() {
	int num;
	int start = 0;

	BF(0);
	
	printf("도착 vertex를 입력하세요: ");
	scanf("%d", &num);

	while (1) {
		if (0 <= num && 5 > num) break;

		printf("잘못 입력하셨습니다. 다시 입력해주세요: ");
		scanf("%d", &num);
	}

	printf("\nvertex 0에서 vertex %d로 가는 최단 경로의 길이는 %d입니다.\n", num, cost[num]);

	return 0;
}

void BF(int start) {
	if (top != -1 && top == rear) {
		top = -1;
		rear = -1;
		return BF(++cnt);
	}
	if (cnt > 4) return;

	for (int i = 0; i < 5; i++) {
		if (matrix[start][i] == 0) continue;

		int len = cost[start] + matrix[start][i];

		if (cost[i] == 0 && change[i] == 0) {
			cost[i] = len;
			change[i] = 1;
			push(i);
		}

		if (cost[i] > len) {
			cost[i] = len;
			push(i);
		}
	}

	if (top == -1) return BF(++cnt);

	return BF(pop());
}

void push(int num) {
	queue[++top] = num;
}

int pop() {
	return queue[++rear];
}