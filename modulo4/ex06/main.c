#include <stdio.h>
#include "asm.h"

int main(void)
{
    char *a = "ola";
    char *b = "ola";
    printf("%d\n", test_equal(a, b));
    return 0;
}
