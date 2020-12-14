#include <stdio.h>
#include "asm.h"

void print_result(char op, int o1, int o2, int res)
{
printf("%d %c %d = %d\n", o1, op, o2, res);

}

int main(void)
{
    int a = 3;
    int b = 5;

    int result = calculate(a,b);

    printf("O resultado é %d\n", result);

    return 0;
}
