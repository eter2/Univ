/* 실습 내용
정수 하나가 홀수인지 짝수인지 판별하는 프로그램을 작성하시오.

입력 형식
첫 줄에 0이상 10억이하의 정수가 하나 주어진다.

출력 형식
입력으로 주어진 정수가 짝수라면 EVEN을 출력하고, 홀수라면 ODD를 출력한다

입/출력 예시
에시 1
입력
3
출력
ODD
예시 2
입력
2
출력
EVEN */

#include <stdio.h>

int main() {
	int a;
	
	scanf("%d", &a);
	
	if(a%2 == 0)
	{
		printf("EVEN");
	}
	else
	{
		printf("ODD");
	}
	
  return 0;
}
