// Stack and Queue
// 수식에 있는 괄호의 번호를 출력하는 프로그램 작성
// Input
// ((())(()))
// Output
// 1 2 3 3 2 4 5 5 4 1 

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>

int stack[MAX_SIZE];
int top = -1;

int push(int cnt);
void pop(int cnt);

int main() {
	char MathExp[10000] = { 0 };
	scanf("%s", MathExp);

	int i = 0;
	int cnt = 1;

	while (1) {
		if (MathExp[i] == '(') cnt = push(cnt);
		else if (MathExp[i] == ')') pop(cnt);
		else if (MathExp[i] == '\0') break;
		else if (MathExp[i] != '(' && MathExp[i] != ')') {
			printf("ERROR!");
			break;
		}

		i++;

		if (cnt == -1) break;
	}

	return 0;
}

int push(int cnt) {
	if (top > MAX_SIZE - 2) {
		printf("Stack Overflow");
		return -1;
	}
	else {
		stack[++top] = cnt;
		printf("%d ", cnt);
		return ++cnt;
	}
}

void pop(int cnt) {
	if (top == -1) {
		printf("Stack is empty");
	}
	else {
		printf("%d ", stack[top--]);
	}
}
