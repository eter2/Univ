// 재귀함수는 단순한 산술 재귀식뿐만 아니라 특정 조건이나 알고리즘에 따라 변칙적인 처리도 구현할 수 있다. 값에 따라 처리 방식이 달라지는 유클리드 호제법을 재귀 함수로 구현해보자.

// 실습 내용
// 두 자연수 a, b가 입력으로 주어진다. 두 자연수의 최대공약수와 최소공배수를 출력하는 프로그램을 작성하시오. 단, 이 문제에서 입력으로 주어지는 자연수는 숫자의 크기가 크므로 일반적인 반복문으로는 시간제한 초과가 날 수 있다. 아래의 정의를 참고하여 유클리드 호제법을 직접 구현해보시오. 단, 유클리드 호제법의 재귀적인 성질을 이용하여 이를 재귀함수로 구현하시오.
//     두 숫자 a, b에 대하여 a를 b로 나눈 나머지를 c라고 하자.
//     c가 0이라면 b가 a와 b의 최대 공약수가 된다.
//     c가 0이 아니라면 b와 c의 최대 공약수가 a와 b의 최대 공약수가 된다.

// 입력 형식
// 한 줄에 두 자연수 a와 b가 공백으로 구분되어 주어진다. a와 b는 모두 21억이하의 자연수다.

// 출력 형식 
// 첫 줄에는 입력으로 주어진 두 숫자의 최대 공약수를 출력한다.
// 두 번째 줄에는 입력으로 주어진 두 숫자의 최소 공배수를 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 24 18
// 출력
// 6 72
// 예시 2
// 입력
// 9 7
// 출력
// 1
// 63
// 예시 3
// 입력
// 123456789 987654321
// 출력
// 9
// 13548070123626141

#include <stdio.h>


//a와 b의 최대 공약수를 반환하는 함수
// * 반복문을 사용하지 않고 구현하시오
long long gcd(long long a, long long b)
{
	//종료조건 및 예외처리 
	if (a < b) {
		int i = a;
		a = b;
		b = i;
	}
	
	//재귀 호출
	int c = a % b;
	if (c == 0)
	{
		return b;
	}
	else
	{
		gcd(b, a%b);
	}
	
	//값 반환 
	
}

//a와 b의 최소 공배수를 반환하는 함수 
long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

int main() {
	long long a, b;
	long long g, l;
	scanf("%lld %lld", &a, &b);
	
	g = gcd(a, b);
	l = lcm(a, b);
	
	printf("%lld\n", g);
	printf("%lld\n", l);
  return 0;
}
