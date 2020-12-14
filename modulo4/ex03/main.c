#include <stdio.h>
#include "asm.h"

int main(void)
{
    int a = 25;
    int b = 50;
    int c = 80;
    int result = greatest(a,b,c);
    printf("%d\n", result);
    return 0;
}
