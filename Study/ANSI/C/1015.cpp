/*
Description
소들과의 거친 생활로 마음이 지친 농부 존 류는 마음의 평안을 얻고자 물벼룩을 키우기로 결심한다.
근처에서 소고기 식당을 운영하는 허세에게서 물벼룩을 몇 마리 받아서 키우던 존 류는 어느 날 물벼룩이 한 마리 밖에 남아 있지 않은 것을 발견했다.
“이건 사건이군!! 범인은 이 안에 있어!!” 
그리하여 사건의 진상을 알아내기 위해 존 류는 허세에게서 물벼룩을 다시 받아와 관찰하다 중요한 사실을 알아내게 되었다.
허세에게서 받아온 물벼룩에겐 이상한 특징이 있었는데 물벼룩이 홀 수로 존재할 경우, 다음날 (기존개체수∗3+1)만큼 늘어나고 짝 수로 존재할 경우 서로 싸워서 결국 다음날 기존 개체 수의 절반으로 줄어드는 것이다.
그리하여 결국엔 최후의 한 마리가 남게 되는 것이었다.
1등만 살아남는 더러운 세상! 최후의 물벼룩이 남을 때까지 몇 일이 걸리는지 계산하는 프로그램을 작성해보자.

Input
첫 줄에는 Test Case의 수 T가 입력된다. (0≤T≤200)
다음 줄부터 한 줄씩 T번 물벼룩의 수 N이 입력된다.(1≤N≤1000)

Output
주어진 물벼룩이 한 마리가 될 때까지 몇 일이 걸리는지 출력한다.
*/

#include <stdio.h>

int main() {
	int T, N, sum;

	scanf("%d", &T);
	sum = 0;

	while (T--)
	{
		int day = 0;
		scanf("%d", &N);
			while (N > 1)
			{
				if (N % 2 == 1)
				{
					N = 3 * N + 1;
				}
				else
				{
					N = N / 2;
				}
				day++;
			}
		printf("%d\n", day);
	}

	return 0;
}