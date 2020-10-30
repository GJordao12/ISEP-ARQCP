#include <stdio.h>
#include "asm.h"

int op1, op2;
int main()
{
    printf("Insira o numero 1: ");
    scanf("%d", &op1);

    printf("Insira o numero 2: ");
    scanf("%d", &op2);

    long long res = sum2ints();

    printf("O valor da soma é: %lld (0x%llx)\n", res, res);

    return 0;
}