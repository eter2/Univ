// 실습 내용
// 특정 결과를 구하기 위해서 중간에 다른 결과를 구하여 활용할 수 있음을 이해하자.
// 두 자연수 A, B가 입력으로 주어진다. 입력으로 주어진 두 자연수의 최소공배수를 출력하는 프로그램을 작성하시오.

// 힌트
//     최소 공배수를 단순히 반복문으로 직접 찾으려고 하면 시간제한 초과에 걸린다.
//     보통 수천만 번 이상의 반복문을 수행하면 1초 이상의 시간이 소요된다.

// 입력 형식
// 첫 줄에 3만 이하의 자연수 A와 B가 공백으로 구분되어 주어진다.

// 출력 형식
// 입력으로 주어진 두 자연수의 최소 공배수를 공백없이 출력하시오.

// 입/출력 예시
// 예시 1
// 입력
// 24 18
// 출력
// 72
// 예시 2
// 입력
// 9 7
// 출력
// 63

#include <stdio.h>

int main() {
	int A, B, C, result;

	result = 1;

	scanf("%d %d", &A, &B);

	for (int i = 1; i <= 30000; i++)
	{
		if (A%i == 0 && B%i == 0)
		{
			result = i;
		}
	}

	printf("%d\n", A*B/result);

	return 0;
}