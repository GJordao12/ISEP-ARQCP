#include <stdio.h>
#include "asm.h"

int A, B;
int main()
{
    printf("Insira o numero A: ");
    scanf("%d", &A);

    printf("Insira o numero B: ");
    scanf("%d", &B);

    char res = isMultiple();

    if (res == 0)
    {
        printf("A não é múltiplo de B\n");
    }
    else
    {
        printf("A é múltiplo de B\n");
    }

    return 0;
}