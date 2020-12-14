#include <stdio.h>
#include "asm.h"

int main(void)
{
    int x = 20;
    printf("%d\n", activate_bit(&x, 5));
    return 0;
}
