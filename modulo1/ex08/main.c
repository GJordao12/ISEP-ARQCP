#include <stdio.h>
#include "array_sort2.h"

int main()
{

    int vec[] = {1, 4, 2, 9, 7, 12};
    array_sort2(vec, sizeof(vec) / sizeof(int));
    printf("Ascending Order: \n");
    for (int i = 0; i < sizeof(vec) / sizeof(int); i++)
    {
        printf("%d\n", vec[i]);
    }
    return 0;
}