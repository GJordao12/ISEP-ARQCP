#include <stdio.h>
#include "asm.h"

int i;
int main()
{
    printf("Insira o i: ");
    scanf("%d", &i);

    printf("Insira o A: ");
    scanf("%d", &A);

    printf("Insira o B: ");
    scanf("%d", &B);

    int res = somatorio();

    printf("O resultado do somatório é: %d\n",res);
    
    return 0;
}


