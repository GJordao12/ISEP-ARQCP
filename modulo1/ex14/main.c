#include <stdio.h>
#include "frequencies.h"

int main(void)
{

    float grades[] = {5.5, 6.5, 20.0, 13.0, 14.0, 17.5};
    int freq[20];
    float *ptr = grades;
    int *p = freq;
    frequencies(ptr, sizeof(grades) / sizeof(float), p);

    for (int i = 0; i < 20; i++)
    {
        printf("%d -> %d\n", i, *(p + i));
    }
}
