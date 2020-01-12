#include <stdio.h>

double degree(int h, int m);

int main() {
	int h, m;
	scanf("%d %d", &h, &m);	
	printf("%.2lf\n", degree(h, m));	
  return 0;
}

double degree(int h, int m) {
	double hd = h * 30.0 + m * 0.5;
	double md = m * 6.0;
	return hd < md ? 360 - md + hd : hd - md;
}