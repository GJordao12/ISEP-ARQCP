#include <stdio.h>
#include "asm.h"
short s1 = 0;
short s2 = 0;
int main()
{
	printf("Insira o numero do s1: ");
	scanf("%hd", &s1);

	printf("Insira o numero do s2: ");
	scanf("%hd", &s2);

	short s3 = crossSumBytes();

	printf("O valor da soma é: %hd\n", s3);

	return 0;
}