// 실습 내용
// 두 십진수가 입력으로 주어진다. 두 십진수를 더한 결과를 출력하는 프로그램을 작성하시오.입력 형식을 꼭 참고한다.

// 입력 형식
// 한 줄에 하나씩 총 두 줄에 걸쳐 두 개의 십진수가 주어진다. 모든 숫자는 0이상의 정수다. 그리고 모든 숫자는 최대 100자리 이하의 숫자다.

// 출력 형식
// 입력으로 주어진 두 숫자를 더한 결과를 한 줄에 십진수로 출력한다.

// 입/출력 예시
// 예시 1
// 입력
// 1 2
// 출력
// 3
// 예시 2
// 입력
// 36 58
// 출력
// 94
// 예시 3
// 입력
// 12421098901248112908 41722432895198758178957112421
// 출력
// 41722432907619857080205225329

#include <stdio.h>
#include <string.h>

int main() {
	char input1[101] = {};
	char input2[101] = {};
	char result[102] = {};
	
	scanf("%s %s", input1, input2);
	
	int length1 = strlen(input1);
	int length2 = strlen(input2);
	
	length1 > length2 ? int max = length1 : int max = length2;
	length1 > length2 ? int min = length2 : int max = length1;
	
	for (int i = max - 1; i >= 0; i--) {
		result[i] = input1[length1] + input[length2];
		length1--;
		length2--;
		
		if(length1 == 0 || length2 == 0) {
			
		}
	}
	
  return 0;
}
