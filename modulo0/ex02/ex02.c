#include <stdio.h>

int sum(int a, int b)
{

	return a + b;
}

int main(void)
{

	int a, b, c = 11;

	while (c > 10)
	{
		printf("a: ");
		scanf("%d", &a);
		printf("b: ");
		scanf("%d", &b);
		c = sum(a, b);
		if (sum(a, b) > 10)
		{
			printf("The sum is not less than 10, enter other values!\n");
		}
	}
	printf("a + b = %d\n", c);
	return 0;
}
