#include <stdio.h>
#include "asm.h"

char *ptr1, *ptr2;
int main(void)
{
    char s1[] = "Vamos testar de novo";
    ptr1 = s1;
    ptr2 = s1;
    str_copy_porto2();
    printf("%s\n", ptr2);
    return 0;
}
