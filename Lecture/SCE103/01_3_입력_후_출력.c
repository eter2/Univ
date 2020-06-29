/* 실습 내용
공백으로 구분 된 세 정수가 차례로 주어진다.
이 세 정수를 입력 순서와 반대로 출력하는 프로그램을 작성하시오.

입/출력 예시
예시 1
입력
1 2 3
출력
3 2 1
예시 2
1 1 1
출력
1 1 1
*/

#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d %d %d", c, b, a);
  return 0;
}
