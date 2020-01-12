#include <stdio.h>

int main() {
	int dec1, dec10, dec11, dec12;
	char hex[2];
	
	for (int i = 0; i < 2; i++)
	{
		scanf("%c", &hex[i]);
	}
	
	
		dec1 = hex[1] - 55;
	

		dec10 = (hex[0] - 55) * 16;
	

	int sum = dec1 + dec10;

  printf("%d", sum);
	
  return 0;
}
