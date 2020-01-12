#include <stdio.h>

int main() {
	char c;
	
	scanf("%c", &c);
	
	if(c >= 'A' && c <= 'Z')
	{
		printf("The %c corresponds to %d", c, c);
	}
	else
	{
		if(c >= 'a' && c <= 'z')
			printf("The %c corresponds to %d", c, c);
		else
			printf("ERROR");
	}
	
  return 0;
}
