#include <stdio.h>
#include "asm.h"

int code, currentSalary, res;
int main()
{
    printf("Insira um código: ");
    scanf("%d", &code);

    printf("Insira o salário atual: ");
    scanf("%d", &currentSalary);

    res = new_salary();
    
    printf("O novo salário é de: %d\n",res);

    return 0;
}
