#include <stdio.h>
#include "asm.h"

int op1, op2;
int main()
{
    printf("Insira o numero 1: ");
    scanf("%d", &op1);

    printf("Insira o numero 2: ");
    scanf("%d", &op2);

    char res = test_flags();

    printf("O valor retornado é: %d\n", res);

    return 0;
}