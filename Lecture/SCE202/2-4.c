// Array and Structure
// 각 사람의 점수들을 입력받고, 전체적으로 출력한 후
// 원하는 사람을 검색할 수 있는 프로그램을 작성
// 모든 변수는 지역변수, 최대 100명의 자료를 처리할 수 있도록 2차원 배열로 선언

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define STUDENT_MAX 100
#define NAME_MAX 7
#define SCORE_MAX 3

struct Student {
	char name[NAME_MAX];
	int scores[SCORE_MAX];
	int sum, ave, rank;
};

void input(struct Student s[STUDENT_MAX], int idx);
void sum(struct Student s[STUDENT_MAX], int idx);
void ave(struct Student s[STUDENT_MAX], int idx);
void rank(struct Student s[STUDENT_MAX], int size);
void print(struct Student s[STUDENT_MAX], int size);
void search(struct Student s[STUDENT_MAX], int size);

int main()
{
	struct Student s[STUDENT_MAX];
	int cnt = 0;

	while (1)
	{
		int flag;
		input(s, cnt);
		sum(s, cnt);
		ave(s, cnt);
		rank(s, ++cnt);

		printf("입력을 종료하려면 0을, 계속하려면 아무 숫자나 입력: ");
		scanf("%d", &flag);
		printf("\n");

		if (flag == 0)
			break;
	}

	print(s, cnt);
	search(s, cnt);

	return 0;
}

void input(struct Student s[STUDENT_MAX], int idx) {
	printf("이름을 입력해주세요: ");
	scanf("%s", &s[idx].name);
	printf("띄어쓰기로 구분해서 국어, 영어, 수학점수를 입력해주세요: ");
	scanf("%d %d %d", &s[idx].scores[0], &s[idx].scores[1], &s[idx].scores[2]);
	printf("\n");
}

void sum(struct Student s[STUDENT_MAX], int idx) {
	s[idx].sum = s[idx].scores[0] + s[idx].scores[1] + s[idx].scores[2];
}

void ave(struct Student s[STUDENT_MAX], int idx) {
	s[idx].ave = (s[idx].scores[0] + s[idx].scores[1] + s[idx].scores[2]) / 3;
}

void rank(struct Student s[STUDENT_MAX], int size) {
	for (int i = 0; i < size; i++) {
		s[i].rank = 1;
		for (int j = 0; j < size; j++) {
			if (s[i].sum < s[j].sum)
				++s[i].rank;
		}
	}
}

void print(struct Student s[STUDENT_MAX], int size) {
	printf("이름\t국어\t영어\t수학\t합계\t평균\t등수\n");
	printf("=================================================================\n");
	for (int i = 0; i < size; i++) {
		printf("%s\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d\t\n",
			s[i].name, s[i].scores[0], s[i].scores[1], s[i].scores[2], s[i].sum, s[i].ave, s[i].rank);
	}
	printf("\n");
}

void search(struct Student s[STUDENT_MAX], int size) {
	char name[100];
	printf("검색하고자하는 사람의 이름: ");
	scanf("%s", &name);

	for (int i = 0; i < size; i++) {
		if (strcmp(name, s[i].name) == 0) {
			printf("이름: %s\n국어: %d점\n영어: %d점\n수학: %d점\n합계: %d점\n평균: %d점\n등수: %d등\n",
				s[i].name, s[i].scores[0], s[i].scores[1], s[i].scores[2], s[i].sum, s[i].ave, s[i].rank);
			return;
		}
	}
	printf("검색하고자 하는 사람이 없습니다.\n");
}
