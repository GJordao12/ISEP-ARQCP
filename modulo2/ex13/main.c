#include <stdio.h>
#include "asm.h"

int main()
{
    printf("Insira a base: ");
    scanf("%d", &base);

    printf("Insira a altura: ");
    scanf("%d", &height);

    int area = getArea();

    printf("A área do trinângulo é: %d\n",area);
    
    return 0;
}
