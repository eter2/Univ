#include <stdio.h>

int main() {
	int x, k, m, t, l;
	int arr2[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
	int arr[16];
	
	scanf("%d", &x);
	
	k = x;
	
	if ( x % 2 == 0)
	{
		for (int i = 15; i >= 0; i--)
		{
			m = k - arr2[i];
			if ( m >= 0 && m % 2 == 0)
			{
				arr[i] = 1;
				k = m;
			}
			else
			{
				arr[i] = 0;
			}
		}
	}	
	else
	{
		arr[0] = 1;
		k = k - 1;
		for (int i = 15; i > 0; i--)
		{
			m = k - arr2[i];
			if (m >= 0 && m % 2 == 0)
			{
				arr[i] = 1;
				k = m;
			}
			else
			{
				arr[i] = 0;
			}
		}
	}

	for (int i = 0; i < 16; i++)
	{
		printf("a bit of %d : %d\n", arr2[i], arr[i]);
	}
	
  return 0;
}
