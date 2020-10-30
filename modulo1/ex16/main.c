#include <stdio.h>
#include "where_exists.h"

int main(void)
{
    char word1[] = "TUA";
    char word2[] = "ATUA";
    char *ptr1 = word1;
    char *ptr2 = word2;
    printf("%s\n", where_exists(ptr1, ptr2));
}
