#include <stdio.h>
#include "asm.h"

int main(void)
{
    short a[7] = {2,3,4,5,6,7,8};
    int n=7;
    short *vec;
    vec = a;
    int result = count_even(vec, n) ;
    printf("%d\n", result);
    return 0;
}
