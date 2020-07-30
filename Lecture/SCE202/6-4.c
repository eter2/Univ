// Tree

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

typedef struct heap {
	char name[10];
	int data;
} heap;

heap h[MAX];
int cnt = 0;

void swap(heap* a, heap* b) {
	heap temp = *a;
	*a = *b;
	*b = temp;
}

void push() {
	++cnt;
	if (cnt > 10) {
		printf("너무 많은 항목을 입력하였습니다.\n\n");
		return;
	}

	printf("전송데이타: ");
	scanf("%s", h[cnt].name);
	printf("용량(단위:KB): ");
	int data;
	scanf("%d", &data);
	h[cnt].data = data;
	printf("\n");

	int child = cnt;
	int parent = child / 2;
	while (child > 1 && h[parent].data < h[child].data) {
		swap(&h[parent], &h[child]);
		child = parent;
		parent = child / 2;
	}
}

void pop() {
	printf("%s : %d\n", h[1].name, h[1].data);

	swap(&h[1], &h[cnt]);
	cnt--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= cnt) {
		if (h[child].data > h[child + 1].data)	child = child;
		else child = child + 1;
	}

	while (child <= cnt && h[parent].data < h[child].data) {
		swap(&h[parent], &h[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= cnt) {
			if (h[child].data > h[child + 1].data)	child = child;
			else child = child + 1;
		}
	}
}

int main() {
	char flag[2] = "i";

	while (strcmp(flag, "p")) {
		printf("삽입(i), 삭제(d), 출력(p): ");
		scanf("%s", &flag);

		if (!strcmp(flag, "i")) {
			push();
		}

		if (!strcmp(flag, "d")) {
			if (cnt == 0) {
				printf("Empty!\n\n");
				continue;
			}

			pop();
			printf("\n");
		}
	}

	if (!strcmp(flag, "p") && cnt == 0) {
		printf("Empty!");
		return 0;
	}

	while (cnt != 0) {
		pop();
	}

	return 0;
}