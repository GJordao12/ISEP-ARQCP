#include <stdio.h>
#include "asm.h"

int main(void)
{
    int num=6;
    unsigned int valores[6] = {-1,0x55555555, 0xaaaaaaaa,0x5555,1,2};
    int result = prendas(valores, num);
    printf("%d\n", result);
    return 0;
}
