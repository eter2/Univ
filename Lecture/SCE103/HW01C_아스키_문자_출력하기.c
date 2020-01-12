#include <stdio.h>

int main() {
	int c;
	scanf("%d", &c);

	if (c >= 65 && c <= 90)
		printf("The %d corresponds to %c", c, c);
	else
	{
		if (c >= 97 && c <= 122)
			printf("The %d corresponds to %c", c, c);
		else
			printf("ERROR");
	}
	return 0;
}
