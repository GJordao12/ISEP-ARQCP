#include <stdio.h>

int count(int *vec, int n, int value)
{
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		if (vec[i] == value)
		{
			total++;
		}
	}

	return total;
}

int main(void)
{

	int n, value;

	printf("How many elements do you want to insert? ");
	scanf("%d", &n);
	int array[n];

	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("-> ");
		scanf("%d", &array[i]);
	}

	printf("Which element do you want to search? ");
	scanf("%d", &value);

	printf("The chosen value (%d) appears %d times.\n", value, count(array, n, value));
}