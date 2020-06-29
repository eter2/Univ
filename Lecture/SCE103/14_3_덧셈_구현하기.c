// 실습 내용
// 비트연산과 반복문(혹은 재귀함수)만을 사용하여 구현하세요.
// 사칙연산의 사용 없이 구현이 가능합니다.
// 두 개의 정수가 입력으로 주어질 때, 두 정수의 합을 구하는 함수를 비트연산으로 구현해보자.
// 실제 CPU는 비트연산으로 사칙연산을 구현하고 있다.

// 입력 형식
// 두 개의 정수가 공백으로 구분되어 주어진다. 입력으로 주어지는 모든 정수와 두 정수의 합은 항상 32비트 unsigned int 형식으로 표현할 수 있는 범위 내로 주어진다.

// 출력 형식
// 두 개의 정수의 합을 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 0 0
// 출력
// 0
// 예시 2
// 입력
// 1 1
// 출력
// 2
// 예시 3
// 입력
// 12 25
// 출력
// 37
// 예시 4
// 입력
// 654987 654987
// 출력
// 1309974

#include <stdio.h>

/**
 * 두 개의 정수 a, b를 비트연산으로 더하기 연산을 수행하는 함수
 *
 * @param a
 * @param b
 * @return 두 정수의 합
 */
unsigned int ADD(unsigned int a, unsigned int b) {
	unsigned int carry = 0;
	unsigned int sum = 0;

	// 비트연산과 반복문(혹은 재귀함수)만으로 구현해보자.
	// 사칙연산 및 나머지 사용 X\
	
	carry = a&b;
	sum = a^b;
	carry = carry<<1;
	if(carry==0) return sum;
	return ADD(carry,sum);
	
	return 0;
}

int main() {
	unsigned int dec_a, dec_b;
	scanf("%u %u", &dec_a, &dec_b);

	unsigned int dec_sum = ADD(dec_a, dec_b);

	printf("%u", dec_sum);
	return 0;
}
