// 실습 내용
// 입력으로 주어진 문자열에서 모든 소문자를 대문자로 변경하는 프로그램을 작성하시오.

// 입력 형식
// 첫 줄에 공백 없는 문자열 하나가 주어진다. 문자열의 길이는 100글자를 넘지 않는다.

// 출력 형식
// 한 줄에 입력으로 주어진 문자열을 대문자화 한 결과를 출력하시오.

// 입/출력 예시
// 예시 1
// 입력
// aBc
// 출력
// ABC
// 예시 2
// 1q2w3e4r!
// 출력
// 1Q2W3E4R!

#include <stdio.h>
#include <string.h>

//문자열 포인터 *str을 받아 이후의 문자들을 대문자로 바꾸어 주는 함수
void Upper(char *str)
{
	for (int i = 0; i < 101; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
	}
}

int main()
{
	char input[101];
	scanf("%s", input);

	Upper(input);

	printf("%s", input);
	return 0;
}
