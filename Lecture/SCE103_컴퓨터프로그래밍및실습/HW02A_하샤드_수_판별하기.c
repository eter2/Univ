#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int x;
		scanf("%d", &x);

		if (x <= 0)
		{
			printf("%d is not a positive integer.\n", x);
		}
		else
		{
			int m = 0;
			int n = x;
			while (n > 0) {
				m += n % 10;
				n = n / 10;
			}

			if (x % m == 0)
			{
				printf("%d is a Harshad number.\n", x);
			}
			else
			{
				printf("%d is not a Harshad number.\n", x);
			}
		}
	}
	return 0;
}