#include <stdio.h>
#include "asm.h"

int main(void)
{
    int x= 2;
    int result = cube(x);
    printf("%d\n", result);
    return 0;
}
