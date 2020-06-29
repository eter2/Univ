// 실습 내용
// 작은 자연수가 하나 주어진다. 이 숫자가 소수인지 판별하는 프로그램을 작성하시오.

// 입력 형식
// 첫 줄에 50이하의 자연수가 하나 주어진다.

// 출력 형식
// 입력으로 주어진 숫자가 소수라면 PRIME을 출력하고, 그렇지 않다면 NOT PRIME을 출력한다.

// 입/출력 에시
// 예시 1
// 입력
// 2
// 출력
// PRIME
// 예시 2
// 입력
// 3
// 출력
// PRIME
// 예시 3
// 입력
// 4
// 출력
// NOT PRIME

#include <stdio.h>

int main() {
	int a, i;

	scanf("%d", &a);

	if(a <= 1)
		printf("NOT PRIME");
	else if(a % 2 == 0)
	{
		if (a == 2)
		{
			printf("PRIME");
		}
		else if(a % 2 == 0)
		{
			printf("NOT PRIME");
		}
	}
	else
	{
		for(i = 2; i < a; i++)
		{
			if(a%i == 0)
			{
				printf("NOT PRIME");
				break;
			}
			if( i == a - 1 )
			{
				printf("PRIME");
				break;
			}
		}
	}
	return 0;
}
