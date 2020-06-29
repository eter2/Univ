// 실습 내용
// A 하나의 수식을 구성하는 연산자와 피연산자들의 정보가 중위 표기법으로 주어질 때, 해당 수식을 계산한 결과를 출력하는 프로그램을 작성하시오. 단, 이 문제에서 모든 연산자의 우선순위는 고려하지 않고 왼쪽에서 오른쪽 순서대로 계산한다.
// 중위 표기법이란 우리가 평소 수식 표기에 사용하는 구조다. 하지만 이 문제에서는 모든 연산자의 우선순위는 무시하며, 일부 피연산자가 숫자가 아닌 상수 기호로 표현될 수 있다. 각 상수가 어떤 숫자에 대응되는 지는 입력으로 모두 주어진다.
// 예를 들어서 상수 A = 5, X = 7이고 아래와 같은 수식이 입력으로 주어졌다고 가정해보자.
// 3 + X - A * X
// 위의 수식에서 각 상수를 실제 값으로 대치하면 아래와 같이 계산할 수 있다. 
// 3 + X - A * X = (3 + 7 - 5 ) * 7 = 35 

// 입력 형식
// 입력의 첫 줄에는 100이하의 두 자연수 N과 M이 입력으로 주어진다.
//     N은 입력으로 주어질 수식을 구성하는 성분의 수를 나타낸다.
//     M은 수식 계산에 사용 할 수 있는 상수 정보의 수를 나타낸다.
// 입력의 두 번째 줄에는 중위 표기법으로 표현 된 수식이 주어진다. 
//     수식은 공백으로 구분 된 N개의 성분으로 구성되어 있다.
//     피연산자, 연산자, 피연산자, ... , 연산자, 피연산자 순서로 주어진다.
//     모든 상수의 이름은 알파벳 대문자로 구성되어 있으며, 의 길이는 10글자를 넘지 않는다.
//     수식에 사용되는 연산자는 +, -, * 중 하나다.
// 이후 총 M줄에 걸쳐 한 줄에 하나씩 변수에 대한 정보가 C V형식으로 주어진다.
//     C는 상수의 이름을 나타내는 10글자 이하의 알파벳 대문자로만 구성된 문자열이다.
//     V는 해당 상수의 실제 값을 나타내는 값이다. 값의 범위는 32비트 int형 정수 범위를 벗어나지 않는다.
//     같은 이름을 가진 상수가 두 번이상 정의되지 않는다.

// 출력 형식
// 해당 수식을 계산한 결과를 정수로 출력한다. 계산의 결과는 32비트 int형 정수 범위를 벗어나지 않는다.

// 입/출력 예시
// 예시 1
// 입력
// 7 2
// 3 + X - A * X
// A 5
// X 7
// 출력
// 35
// 예시 2
// 입력
// 3 2
// A + B
// B 18
// A 83
// 출력
// 101
// 예시 3
// 입력
// 9 2
// HI * HI * HI * HI * HI
// BYE 10
// HI 2
// 출력
// 32

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char name[11];
	int value;
} symbol;


int isNumber(const char * str)
{	// => 문자열 str이 10진수 숫자를 나타낸 다면 1, 그렇지 않다면 -1을 반환하는 함수	
	// 예1 : isNumber("a") => -1
	// 예2 : isNumber("99") => 1
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return -1;
		}
	}
	return 1;
}

int convertToInt(const char * str)
{	// => 문자열 str이 나타내는 10진수 값을 정수형으로 변환하여 반환하는 함수 
	// 예1 : convertToInt("10") => 10
	// 예2 : convertToInt("025") => 25

	int value = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		value *= 10;
		value += str[i] - '0';
	}

	return value;
}

int getSymbolValue(const char * symbolName, symbol* symbolList, int symbolNum)
{	// => 심볼들의 배열 symbolList[0] ~ symbolList[symbolNum-1] 에서 
	// 심볼의 이름이 symbolName과 일치하는 심볼의 값을 반환하는 함수
	for (int i = 0; i < symbolNum; i++)
	{
		if (!strcmp(symbolName, symbolList[i].name))
		{
			return symbolList[i].value;
		}
	}

}



int main()
{
	int n, m;	//수식의 성분 수와 상수 기호의 수 
	int answer = 0;	//출력할 정답
	char** elements;	//수식의 성분들을 저장할 배열의 포인터
	symbol* constants;	//상수 기호들을 저장할 배열의 포인터 


	scanf("%d %d", &n, &m);

	elements = (char**)malloc(sizeof(char*) * n); //수식의 성분들을 저장할 배열의 포인터

	//수식의 각 성분을 입력받는다
	//elements[0] ~ elements[n-1]
	for (int i = 0; i < n; i++)
	{
		elements[i] = (char*)malloc(sizeof(char) * 12);
		scanf("%s", elements[i]);
	}


	constants = (symbol*)malloc(sizeof(symbol) * m); //상수 기호들을 저장할 배열의 포인터 

	//각 상수 기호들을 구조체로 입력받는다
	//constants[0] ~ constants[m-1]
	for (int i = 0; i < m; i++)
	{
		scanf("%s %d", constants[i].name, &constants[i].value);
	}

	//수식 계산하기
	if (isNumber(elements[0]) == 1)
	{
		answer = convertToInt(elements[0]);
	}
	else
	{
		answer = getSymbolValue(elements[0], constants, m);
	}
	for (int i = 1; i < n ;i++)
	{
		if (i % 2 == 0)
		{
			if (!strcmp(elements[i - 1], "+"))
			{
				if (isNumber(elements[i]) == 1)
				{
					answer += convertToInt(elements[i]);
				}
				else
				{
					answer += getSymbolValue(elements[i], constants, m);
				}
			}
			else if(!strcmp(elements[i-1],"-"))
			{
				if (isNumber(elements[i]) == 1)
				{
					answer -= convertToInt(elements[i]);
				}
				else
				{
					answer -= getSymbolValue(elements[i], constants, m);
				}
			}
			else if (!strcmp(elements[i - 1], "*"))
			{
				if (isNumber(elements[i]) == 1)
				{
					answer *= convertToInt(elements[i]);
				}
				else
				{
					answer *= getSymbolValue(elements[i], constants, m);
				}
			}
		}
	}


	printf("%d\n", answer);

	for (int i = 0; i < n; i++)
	{
		free(elements[i]);
	}
	free(elements);
	free(constants);

	return 0;
}
