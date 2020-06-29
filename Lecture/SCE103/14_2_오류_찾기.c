// 실습 내용
// 반복문을 사용하지 않고 해결해보세요.
// 비트 연산 만으로 해결할 수 있습니다.
// 세 개의 unsigned int 형 정수가 입력으로 주어진다. 세 개의 정수를 2진수 비트로 표현했을 때, 일치하지 않는 비트를 찾아 출력하는 프로그램을 작성하시오. 세 개의 숫자의 비트가 일치하지 않는 비트를 1로, 모두 일치하는 비트를 0으로 하여 결과를 표현한다.
// 예를 들어서 세 개의 이진수 10011111 10010111 10011110  에서 오른쪽에서 첫번째 비트와 네번째 비트는 세 이진수에서 다르게 나타난다. 이 경우 결과를 00001001과 같이 출력한다. 비트는 MSB(Most Significant Bit)부터 LSB(Least Significant Bit)순서로 왼쪽에서 오른쪽으로 출력한다.

// 입력 형식
// 세 개의 정수가 공백으로 구분되어 차례로 주어진다. 모든 정수는 32비트 unsigned int 형식의 범위 내에서 주어진다.

// 출력 형식
// 문제에서 주어진 규칙에따라 정답을 32비트 2진수로 출력한다. 왼쪽이 MSB, 오른쪽이 LSB가 되도록 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 3 7 3
// 출력
// 00000000000000000000000000000100
// 예시 2
// 입력
// 654654654 654654724 654654754
// 출력
// 00000000000000000000000110111110
// 예시 3
// 입력
// 65535 65525 65531
// 출력
// 65535 65525 65531

#include <stdio.h>

#define BIT_LENGTH 32

/**
 * 32비트 정수 변수의 비트값을 MSB->LSB형식으로 한 줄에 출력하는 함수
 * @param b
 */
void print_dec2bits(unsigned int b) {
	char strbits[BIT_LENGTH + 1] = {0,};
	for (int i = 0; i < BIT_LENGTH; i += 1) {
		strbits[BIT_LENGTH-1-i] = (char) (((b >> i) & 1) + '0');
	}
	printf("%s\n", strbits);
}


/**
 * 세 개의 32비트 이진수에서 일치하지 않는 부분을 비트로 표현해 반환하는 함수
 *
 * @param a
 * @param b
 * @param c
 * @return
 */
unsigned int find_error_bits(unsigned int a, unsigned int b, unsigned int c) {
	return (a ^ b) | (b ^ c) | (c ^ a);
}


int main() {
	unsigned int dec_a, dec_b, dec_c;
	scanf("%u %u %u", &dec_a, &dec_b, &dec_c);

	unsigned int different_bits = find_error_bits(dec_a, dec_b, dec_c);
	print_dec2bits(different_bits);

	return 0;
}
