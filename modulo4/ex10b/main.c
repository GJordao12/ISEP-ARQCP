#include <stdio.h>
#include "asm.h"

int main(void)
{
    int x = 20;
    printf("%d\n", count_bits_zero(x));
    return 0;
}
