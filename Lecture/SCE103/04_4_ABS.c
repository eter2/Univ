// 실습 내용
// 정수 하나가 주어진다. 이 정수의 절대값을 출력하는 프로그램을 작성하시오..

// 입력 형식
// 한 줄에 절대값이 10억 이하인 정수가 하나 주어진다.

// 출력 형식
// 입력으로 주어진 정수의 절대값을 출력하시오.

// 입/출력 예시
// 예시 1
// 입력
// 2
// 출력
// 2
// 예시 2
// 입력
// -7
// 출력
// 7

#include <stdio.h>

int main() {
	int a;
	
	scanf("%d", &a);
	
	if(a >= 0)
	{
		printf("%d", a);
	}
	else
	{
		printf("%d", -1 * a);
	}
  return 0;
}
