#include <stdio.h>
#include "asm.h"

int main()
{
    printf("Insira A: ");
    scanf("%d", &A);

     printf("Insira B: ");
    scanf("%d", &B);
    
     printf("Insira C: ");
    scanf("%d", &C);

     printf("Insira D: ");
    scanf("%d", &D);

    int res = compute();

    printf("O resultado final é: %d\n", res);
    
    return 0;
}
