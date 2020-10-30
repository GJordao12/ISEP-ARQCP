#include <stdio.h>
#include "odd_sum.h"

int main(void)
{
    int array[] = {10, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int *ptr = array;
    printf("Soma = %d\n", odd_sum(ptr));
}
