#include <stdio.h>
#include "asm.h"

char byte1, byte2;
int main(void)
{
    printf("Valor byte1: ");
    fgets(&byte1,20000,stdin);
    printf("Valor byte2: ");
    fgets(&byte2,20000,stdin);
    short res = (short) concatBytes();
    printf("short = %hd (0x%x)\n", res, res);
    return 0;
}
