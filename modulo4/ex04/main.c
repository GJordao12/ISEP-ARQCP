#include <stdio.h>
#include "asm.h"

int main(void)
{
    int num1 = 105;
    int num2 = 5;
    int *smaller;
    printf("%d\n", sum_smaller(num1, num2, smaller));
    printf("%d\n", *(smaller));
    return 0;
}
