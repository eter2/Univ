// 실습 내용
// 결국 두 숫자의 최대 공약수를 구하는 문제도 조건부 최대값을 구하는 것과 다르지 않다는 것을 이해하자
// 두 자연수 A, B가 입력으로 주어진다. 두 숫자의 최대공약수를 출력하는 프로그램을 작성하시오.

// 입력 조건
// 1,000이하의 두 자연수 A와 B가 공백으로 구분되어 입력으로 주어진다.

// 출력 조건
// 두 자연수의 최대 공약수를 한 줄에 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 24 18
// 출력
// 6
// 예시 2
// 입력
// 7 9
// 출력
// 1

#include <stdio.h>

int main() {
	int A, B, C, result;

	result = 1;

	scanf("%d %d", &A, &B);

	for (int i = 1; i <= 1000; i++)
	{
		if (A%i == 0 && B%i == 0)
		{
			result = i;
		}
	}

	printf("%d", result);

	return 0;
}