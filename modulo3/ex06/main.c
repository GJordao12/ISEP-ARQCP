#include <stdio.h>
#include "asm.h"

char *ptr1;
int main(void)
{
    char string[] = "ola amanha";
    ptr1 = string;
    int changed = encrypt();
    printf("%d\n", changed);
    return 0;
}
