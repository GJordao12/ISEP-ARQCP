#include <stdio.h>
#include "asm.h"

int num;
int main()
{
    printf("Insira o numero: ");
    scanf("%d", &num);

    int res = steps();

    printf("O resultado é: %d\n",res);
    
    return 0;
}

