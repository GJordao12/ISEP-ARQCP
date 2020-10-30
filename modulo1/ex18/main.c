#include <stdio.h>
#include "compress_shorts.h"

int main(void)
{

    short letters[] = {1, 2, 2, 1};
    int num[2000];
    short *ptr1 = letters;
    int *ptr2 = num;
    compress_shorts(ptr1, (sizeof(letters) / sizeof(short)), ptr2);

    for (int i = 0; i < (sizeof(letters) / sizeof(short)) - 1; i++)
    {
        printf("Index %d: %d\n", i, *(ptr2 + i));
    }
}
