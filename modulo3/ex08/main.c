#include <stdio.h>
#include "asm.h"

int even;
int main(void)
{
    even = 1;
    int result = test_even();
    if (result == 1)
    {
        printf("é par\n");
    }
    else
    {
        printf("é impar\n");
    }

    
    return 0;
}
