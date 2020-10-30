#include <stdio.h>
#include "capitalize.h"

int main(void)
{

    char vec[2000];
    char *ptr = vec;
    printf("Text: ");
    fgets(vec, 2000, stdin);
    capitalize(ptr);
    printf("Text capitalized: %s", ptr);
    return 0;
}
