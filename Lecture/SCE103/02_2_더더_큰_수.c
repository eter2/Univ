/* 실습 내용
절대값이 10억 이하인 세 정수가 공백으로 구분되어 입력된다.
세 숫자중에 가장 큰 값을 출력하는 프로그램을 작성하시오.

입/출력 예시
예시 1
입력
1 2 3
출력
3
예시 2
입력
6 5 4
출력
6
예시 3
입력
7 9 8
출력
9 */

#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a > b){
		if (a > c){
			printf("%d", a);
		}
		else {
			printf("%d", c);
		}
	}
	else {
		if (b>c){
			printf("%d", b);
		}
		else {
			printf("%d", c);
		}
	}
	return 0;
	}
