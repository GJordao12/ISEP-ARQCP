#include <stdio.h>
#include "asm.h"

int array[] = {2,4,5,2,3,8};
int* ptrvec = array;
int num =6;

int main(void)
{
    int sum = vec_sum();
    printf("Sum of the elements in the array = %d\n", sum);

    return 0;
}
