#include <stdio.h>
#include "asm.h"

char frase[] = " Eu g0sto de 0 zeros!";
char* ptr1 = frase;
int main(void)
{
    int res = zero_count();
    printf("Number of Zeros = %d\n", res);
    return 0;
}
