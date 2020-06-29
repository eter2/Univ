// 실습 내용
// 세 행렬 X, Y, Z에 대하여 각각 아래와 같은 세 가지 정보가 주어진다.
//     행의 수
//     열의 수
//     행렬을 구성하는 각 원소
// 세 행렬을 곱한 결과 M = XYZ를 출력하는 프로그램을 작성하시오.

// 입력 형식
// 각 행렬에 대하여 아래와 같은 정보가 주어진다. 행렬의 정보는 X, Y, Z 순서대로 구분되어 주어진다.
// 각 행렬 정보의 첫 줄에는 행과 열의 수를 나타내는 200이하의 두 자연수 R C가 주어진다.
// 이후 총 R줄에 걸쳐서 한 줄에 C개의 정수가 입력으로 주어진다.
//     1번째 행, 2번째 행, ... , R번째 행 순서로 주어진다.
//     각 행에는 1번째 열의 원소, 2 번째 열의 원소, ... , C번째 열의 원소 순으로 주어진다.
//     행렬의 원소는 절대값이 10이하인 정수다.

// 출력 형식
// 세 행렬을 곱하는 연산이 불가능하다면 -1만을 출력하고 종료한다. 곱셈이 가능하다면 아래와 같은 형식으로 정답을 출력한다.
//     첫 줄에는 결과 행렬의 행의 수와 열의 수를 공백으로 구분하여 R C형식으로 출력한다.
//     이후 각 행렬의 원소를 여러 줄에 걸쳐서 출력한다.
//     하나의 행을 한 줄에 출력한다.
//     한 행의 각 원소는 따로 공백으로 구분하지 않고 %8d 형식으로 출력하시오.

// 힌트
// 두 행렬의 곱셈을 하나의 함수로 구현하면 코드가 간결해진다.

// 입/출력 예시
// 예시 1
// 입력
// 2 3
// 4 5 6
// 7 8 9
// 3 1
// 9
// 6
// 3
// 1 3
// 1 2 3
// 출력
// 2 3
//       84     168     252
//      138     276     414
// 예시 2
// 입력
// 2 3
// 4 5 6
// 7 8 9
// 3 2
// 9 6
// 7 8
// 8 5
// 2 4
// 1 2 3 4
// 4 5 7 5
// 출력
// 2 4
//      495     708    1015     946
//      795    1137    1630    1519
// 예시 3
// 입력
// 2 3
// 4 5 6
// 7 8 9
// 3 3
// 2 5 8
// 7 4 1
// 0 0 0
// 1 3
// 1 -1 0
// 출력
// -1

#include <stdio.h>

#define MAX_LENGTH 201

//행렬 MA( ra행 ca열) 과 MB( rb행 cb열 )을 곱하여 MX에 결과를 저장해주는 함수
void multiply(int ma[][MAX_LENGTH], int ra, int ca, int mb[][MAX_LENGTH], int rb, int cb, int mx[][MAX_LENGTH])
{

	//MX을 영행렬으로 초기화하자
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < cb; j++)
		{
			for (int k = 0; k < ca; k++)
			{
				mx[i][j] += ma[i][k] * mb[k][j];
			}
		}
	}
	//MA와 MB의 각 원소를 곱해 MX에 저장하자

}



int main()
{
	int ra, ca;
	int ma[MAX_LENGTH][MAX_LENGTH];
	
	scanf("%d %d", &ra, &ca);
	
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < ca; j++)
		{
			scanf("%d", &ma[i][j]);
		}
	}
	
	int rb, cb;
	int mb[MAX_LENGTH][MAX_LENGTH];
	
	scanf("%d %d", &rb, &cb);
	
	for (int i = 0; i < rb; i++)
	{
		for (int j = 0; j < cb; j++)
		{
			scanf("%d", &mb[i][j]);
		}
	}
	
	int rc, cc;
	int mc[MAX_LENGTH][MAX_LENGTH];
	
	scanf("%d %d", &rc, &cc);
	
	for (int i = 0; i < rc; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			scanf("%d", &mc[i][j]);
		}
	}
	
	if (ca != rb || cb != rc)
	{
		printf("-1\n");
		return 0;
	}
	
	int mx[MAX_LENGTH][MAX_LENGTH];
	int mx2[MAX_LENGTH][MAX_LENGTH];
	
	multiply(ma, ra, ca, mb, rb, cb, mx);
	multiply(mx, ra, cb, mc, rc, cc, mx2);
	
	printf("%d %d\n", ra, cc);
	
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			printf("%8d", mx2[i][j]);
		}
		printf("\n");
	}
	
  return 0;
}
