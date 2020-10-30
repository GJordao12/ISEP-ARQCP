#include <stdio.h>

void print_array(int *vec, int n)
{
	int index = 0;
	while (n != 0)
	{
		printf("Value of the vector in the index %d = %d\n", index, *vec);
		vec++;
		index++;
		n--;
	}
}
