#include <stdio.h>
#include "average.h"

int main()
{
    int v[] = {2, 4};
    printf("Average = %d\n", average_array(v, 2));

    printf("Average = %d\n", average_global_array());

    return 0;
}
