// 실습 내용
// 테스트케이스란 한 번 실행할 때 질문을 여러 번 하겠다는 의미이다. 그렇기에 문제에서 정의한 입력과 출력을 여러 번 반복하여 질문/답변 형식의 입출력을 반복하게 된다.
// 주어진 샘플 코드를 참고하여보자. 그리고 지우고 스스로 다시 작성해보자. 안그러면 과제 못한다.
// 두 정수 A와 B를 입력받아 두 수의 합을 출력하는 프로그램을 작성하시오.

// 입력 형식
// 첫 줄에는 테스트케이스의 수를 나타내는 100이하의 자연수 T가 주어진다. 이후 총 T개의 테스트케이스에대한 입력이 차레로 주어진다.
// 각 테스트케이스의 입력은 한 줄에 공백으로 구분된 두 정수로 주어진다.

// 출력 형식
// 각 테스트케이스에 대하여 정답을 한 줄에 출력한다. 정답을 출력하는 순서는 테스트케이스의 입력 순서와 일치해야 한다. 입력으로 주어진 두 정수의 합을 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 2
// 1 2
// 3 4
// 출력
// 3
// 7
// 예시 2
// 입력
// 5
// 1 2
// 1 2
// 1 2
// 2 3
// 3 2
// 출력
// 3
// 3
// 3
// 5
// 5
// 예시 3
// 입력
// 1
// 5 6
// 출력
// 11

#include <stdio.h>

int main() {
	int A, B, T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}
