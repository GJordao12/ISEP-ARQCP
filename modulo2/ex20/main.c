#include <stdio.h>
#include "asm.h"

int num;
int main()
{
    printf("Insira o número: ");
    scanf("%d", &num);

    char verificar = check_num();
    if (verificar == 1)
    {
        printf("O número é par e negativo.\n");
    }
    if (verificar == 2)
    {
        printf("O número é impar e negativo.\n");
    }
    if (verificar == 3)
    {
        printf("O número é par e positivo.\n");
    }
    if (verificar == 4)
    {
        printf("O número é impar e positivo.\n");
    }

    return 0;
}
