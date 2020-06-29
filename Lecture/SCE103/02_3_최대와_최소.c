/* 실습 내용
절대값이 10억 이하인 정수가 공백으로 구분되어 네 개 주어진다.
그 중 최대값을 첫 번째 줄에 출력하시오.
그 중 최소값을 두 번째 줄에 출력하시오.

입/출력 예시
입력
-1 0 1 3
출력
3
-1 */

#include <stdio.h>

int main() {
	int a, b, c, d, max, min;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		max = a;
		if (max < b) {
			max = b;
		}
		if (max < c) {
			max = c;
		}
		if (max < d) {
			max = d;
		}
		min = a;
		if (min > b) {
			min = b;
		}
		if (min > c) {
			min = c;
		}
		if (min > d) {
			min = d;
		}
	printf("%d\n%d", max, min);
  return 0;
}
