// 실습 내용
// 학생들의 학번과 성적들이 입력으로 주어질 때 이를 정렬하는 프로그램을 작성하시오.
//     학생들의 총점을 기준으로 내림차순으로 정렬한다.
//     학생들의 총점이 같다면 학번을 기준으로 오름차순 정렬한다.
// 각 학생들의 총점은 각 과목에 대해 가중치를 곱해서 계산한다.
//     국어의 가중치는 1이다.
//     과학과 영어의 가중치는 2이다.
//     수학의 가중치는 3이다.
// 예를 들어서 한 학생이 국어 2점, 수학 3점, 영어 4점, 과학 5점을 획득한 경우 총 점은 아래와 같다.
//     2x1 + 3x3 +4x2 + 5x2 = 29

// 입력 형식
// 첫 줄에는 학생의 수를 나타내는 10만 이하의 자연수 N이 주어진다. 이후 총 N명의 학생에 대한 정보가 한 줄에 하나씩 주어진다.
// 각 학생의 정보는 다섯개의 정수가 공백으로 구분되어 주어진다. 각각 순서대로 학생의 학번, 국어 성적, 수학 성적, 영어 성적, 과학 성적을 나타낸다.
//     학생의 학번은 서로 다른 10만이하의 자연수다.
//     각 과목의 점수는 0이상 30이하의 정수다.

// 출력 형식 
// 문제에 주어진 순서에 따라 정렬된 학생의 정보를 출력한다.
//     학생의 학번과 계산된 총점을 공백으로 구분하여 한 줄에 한 명씩 출력한다.
//     우선순위가 높은 학생을 먼저 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 6
// 1 2 3 4 5
// 2 5 4 3 2
// 6 5 4 3 2
// 3 5 4 3 2
// 4 0 10 0 1
// 5 4 3 2 1
// 출력
// 4 32
// 1 29
// 2 27
// 3 27
// 6 27
// 5 19
// 예시 2
// 입력
// 10
// 1 28 15 17 14
// 4 26 2 3 19
// 10 2 1 9 22
// 9 22 6 12 26
// 2 30 21 13 24
// 3 20 10 5 12
// 7 30 0 13 23
// 6 1 14 15 15
// 5 7 8 19 7
// 8 10 4 7 30
// 출력
// 2 167
// 1 135
// 9 116
// 6 103
// 7 102
// 8 96
// 3 84
// 5 83
// 4 76
// 10 67

#include<stdio.h>
#include<string.h>
#include<malloc.h>

// qsort 사용을 위해서는 stdlib.h를 참조해야 합니다.
#include<stdlib.h>

// 각 점수의 가중치
#define WEIGHT_MATH			3
#define WEIGHT_SCIENCE	2
#define WEIGHT_ENGLISH	2
#define WEIGHT_KOREAN		1

typedef struct student_t {
	int student_id;     // 학번
	int point_korean;   // 국어 점수
	int point_math;     // 수학 점수
	int point_english;  // 영어 점수 
	int point_science;  // 과학 점수 
} student_t;

/**
 * 해당 학생의 과목별 성적으로 총점을 계산해 반환해주는 함수
 *
 * @param e 	학생 정보 구조체의 포인터
 * @return 		가중치를 사용해 계산한 총점
 */
int get_total_point(const student_t *e) {
	int total = 0;

	total = e->point_korean + e->point_math * 3 + e->point_english* 2 + e->point_science * 2;
	return total;
}

/**
 * 두 학생의 정보를 비교해 비교 결과를 반환하는 함수
 * 1. 총 점이 높은 학생이 우선순위가 높다.
 * 2. 총 점이 같다면 학생 번호가 작은 학생이 우선순위가 높다.
 *
 * @param e1	비교식의 좌항
 * @param e2	비교식의 우항
 * @return		비교 결과 (음수, 0, 양수)
 */
int student_cmp(const void *e1, const void *e2) {
	student_t* a = (student_t*)e1;
	student_t* b = (student_t*)e2;
	int tot_a=get_total_point(a);
	int tot_b=get_total_point(b);
	if(tot_a>tot_b) return -1;
	if(tot_a<tot_b) return 1;
	if(tot_a==tot_b){
		if(a->student_id<b->student_id) return -1;
		if(a->student_id>b->student_id) return 1;
		return 0;
	}
}

int main() {
	unsigned int n_students;
	student_t *arr;

	scanf("%u", &n_students);

	arr = (student_t *)malloc(sizeof(student_t) * n_students);

	for (int i = 0; i < n_students; i += 1) {
		scanf("%d %d %d %d %d", &arr[i].student_id, &arr[i].point_korean,
			&arr[i].point_math, &arr[i].point_english, &arr[i].point_science);
	}

	/** 이 곳에 qsort를 사용하여 데이터 정렬을 작성하세요
	 *  [Reference] https://msdn.microsoft.com/ko-kr/library/zes7xw0h.aspx?f=255&MSPPError=-2147217396
	 */
	 //qsort(blar blar ... );
	qsort(arr, n_students, sizeof(student_t), student_cmp);



	for (int i = 0; i < n_students; i += 1) {
		int pt = get_total_point(&arr[i]);
		printf("%d %d\n", arr[i].student_id, pt);
	}

	
	free(arr);
	

	return 0;
}