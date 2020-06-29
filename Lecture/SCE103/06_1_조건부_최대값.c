// 실습 내용
// 주어진 조건을 만족하는 여러 개의 값들 중 최대값을 구하는 알고리즘을 고민해보자.
// 세 자연수 N, A, B가 주어진다. 폐구간 [1, N]범위의 모든 자연수들 중 아래의 조건을 만족하는 자연수들 중 가장 큰 값을 찾아 출력하는 프로그램을 작성하시오.
//     A로 나눈 나머지가 B이다.

// 입력 형식
// 문제의 입력은 한줄에 N A B형식으로 주어진다.
//     N은 100,000이하의 자연수다.
//     A, B는 모두 10,000이하의 자연수다.

// 출력 형식
// 문제 설명에 주어진 조건을 만족하는 최대값을 출력한다.
// 만약에 주어진 범위에서 문제에서 제시 된 조건을 만족하는 숫자가 존재하지 않는다면 -1을 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 10 3 1
// 출력
// 10
// 예시 2
// 입력
// 1000 9 9
// 출력
// -1

#include <stdio.h>

int main() {
	int N, A, B, result;
	
	result = -1;
	
	scanf("%d %d %d", &N, &A, &B);

	for (int i = 1; i <= N; i++)
	{
		if (i%A == B)
		{
			result = i;
		}
	}

	printf("%d", result);
	
	return 0;
}