#include <stdio.h>
#include "line.h"

void multiplication_table_n(int n)
{
    for (int i = 1; i < 11; i++)
    {
        line(n, i);
    }
}
