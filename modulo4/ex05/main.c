#include <stdio.h>
#include "asm.h"

int main(void)
{
    int v2 = 10;
    int *v1;
    v1 = &v2;
    int result = inc_and_square(v1,v2);
    printf("%d\n", result);
    return 0;
}
