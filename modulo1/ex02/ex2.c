#include <stdio.h>
#include "print_array.h"
#include "copy_vec.c"

int main(void)
{
	int vec1[] = {1, 2, 3, 4, 5};
	int vec2[] = {6, 7, 8, 9, 10};
	printf("Values of vector 1:\n");
	print_array(vec1, sizeof(vec1) / sizeof(int));
	printf("Values of vector 2:\n");
	print_array(vec2, sizeof(vec2) / sizeof(int));
	copy_vec(vec1, vec2, sizeof(vec1) / sizeof(int));
	printf("New values of vector 2:\n");
	print_array(vec2, sizeof(vec2) / sizeof(int));
	return 0;
}
