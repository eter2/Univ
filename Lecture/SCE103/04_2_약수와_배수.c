/* 실습 내용
두 정수 a와 b가 주어진다. a가 b의 배수인지 판단하는 프로그램을 작성하시오.

입력 형식
첫 줄에 공백으로 구분된 두 자연수가 a b형식으로 주어진다.
모든 숫자는 10억 이하의 자연수다.

출력 형식
a가 b의 배수라면 TRUE를 출력하고, 그렇지 않다면 FALSE를 출력한다. */

#include <stdio.h>

int main() {
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	if(a%b == 0)
	{
		printf("TRUE");
	}
	else
	{
		printf("FALSE");
	}
  return 0;
}
