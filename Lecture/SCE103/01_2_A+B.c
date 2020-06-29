/* 실습 내용
공백으로 구분 된 두 정수를 입력받아 합을 출력하는 프로그램을 작성하시오
입출력 예시를 참고한다.

입/출력 예시
예시 1
입력
3 7
출력
10
예시 2
입력
1 2
출력
3
*/

#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a+b);
  return 0;
}
