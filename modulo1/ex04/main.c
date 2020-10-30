#include <stdio.h>
#include "upper1.h"

int main(void)
{
	char vec[2000];
	printf("Text: ");
	fgets(vec, 2000, stdin);
	upper1(vec);
	printf("Text capitalized: %s", vec);
	return 0;
}
