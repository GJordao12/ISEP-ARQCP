#include <stdio.h>
#include "asm.h"

short s = 0;
int main(void)
{
    printf("Valor s: ");
    scanf("%hd", &s);
    printf("number: %hd (0x%x)\n", s, s);
    short res = swapBytes();
    printf("swapped number %hd (0x%x)\n", res, res);
    return 0;
}
