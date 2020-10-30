#include <stdio.h>

int size(char *str)
{
    int size = 0;
    int i = 0;
    while (*(str + i) != 0)
    {
        size++;
        i++;
    }
    return size;
}

char *where_exists(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL || size(str1) == 0 || size(str2) == 0 || size(str1) > size(str2))
    {
        return NULL;
    }

    int aux = 0;

    for (int i = 0; i < size(str2); i++)
    {
        if (*(str2 + i) == *(str1 + aux))
        {
            aux++;
        }
        else
        {
            aux = 0;
        }
        if (size(str1) == aux)
        {
            int diff = (i - aux) + 1;
            return str2 + diff;
        }
    }
    return NULL;
}