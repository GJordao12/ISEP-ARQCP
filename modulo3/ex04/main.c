#include <stdio.h>
#include "asm.h"

int *ptrvec;
int main(void)
{
    int num[] = {1, 2, 3, 4, 5};
    ptrvec = num;
    vec_add_one();
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", *(ptrvec + i));
    }
    return 0;
}
