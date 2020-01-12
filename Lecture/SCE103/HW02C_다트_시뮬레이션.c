#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define MAX_TRIALS 0x40000

/** @Brief
***  [-1, 1] 범위의 난수를 생성하는 함수
**/
double get_random_coordinate()
{
	double r = rand() * 2.0;
	return (r / RAND_MAX)- 1.0;
}

/** @Brief 
***  정의된 횟수만큼 임의의 시도를 반복하여
***  Hit율을 계산하는 함수 
**/
double simulate_randomly()
{	
	int i = 0; //시행 반복을 위한 반복자
	int nTrials = 0;  //총 시도 횟수 
	int nSuccess = 0; //총 성공 횟수 
	double x, y; //랜덤 생성된 좌표 
	
	//시도를 여러 번 반복해주는 반복문
	for(i = 0 ; i < MAX_TRIALS; i++)
	{ //한 번의 시도
		
		//임의의 좌표를 생성한다 
		x = get_random_coordinate();
		y = get_random_coordinate();
		/** Begin of your Algorithm **/
		
		if(sqrt(x*x+y*y)<=1) nSuccess++;
		nTrials++;
		
		/** End of your Algorithm **/
	}
	
	//총 성공 횟수를 시도 횟수로 나누어
	//성공률을 계산한다
	return (double)nSuccess / nTrials;
}

int main() {
	double ratio; //히트 확률을 저장할 변수
	
	//난수 생성을 위한 초기화 
	srand(time(0));
	
	//주어진 함수를 통해 Hit율을 계산한다 
	ratio = simulate_randomly();
	
	//소수점 세 번째 자리까지 출력한다
	printf("%.3lf\n", ratio);
  return 0;
}
