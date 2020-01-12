#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

int main() {
	int i, n;
	double t, x;

	scanf("%d", &n);

	for (i = 0; i < n; i++) 
	{
		scanf("%lf", &t);
		x = sqrt(t);
		if (((ull)x)*((ull)x) == (ull)t)
		{
			printf("%llu\n", (((ull)x + 1)*((ull)x + 1)));
		}
		else
		{
			printf("-1\n");
		}
	}
}