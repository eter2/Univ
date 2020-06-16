// Array and Structure
// 구조체를 작성한 후, 동적 메모리를 할당하고
// 정보를 입력한 후, 출력하고 동적 메모리를 반납하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

struct person{
	char name[6];
	int age;
	float salary;
};

int main() {
	struct person *p;
	
	// 동적 메모리 할당
	p = (struct person*)malloc(sizeof(struct person) * 3);

	printf("사람 이름은 영문 5자 이상 입력할 수 없습니다.\n");

		// 3명 정보 저장
	for (int i = 0; i < 3; i++) {
		printf("Enter person's name:");
		scanf("%s", &p[i].name);
		printf("Enter person's age:");
		scanf("%d", &p[i].age);
		printf("Enter person's salary:");
		scanf("%f", &p[i].salary);
	}

	// 나이의 평균 계산해서 출력
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += p[i].age;
	}
	printf("Average Age: %d", sum / 3);

	// 동적 메모리 반납
	free(p);

	return 0;
} 