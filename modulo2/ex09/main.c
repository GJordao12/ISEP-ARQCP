#include <stdio.h>
#include "asm.h"

char A;
short B;
int C,D;

int main()
{
    printf("Insira o numero 1: ");
    scanf("%c", &A);

    printf("Insira o numero 2: ");
    scanf("%hd", &B);

    printf("Insira o numero 3: ");
    scanf("%d", &C);

    printf("Insira o numero 4: ");
    scanf("%d", &D);

    long long res = sum_and_subtract();

    printf("O valor da soma é: %lld (0x%llx)\n", res, res);

    return 0;
}