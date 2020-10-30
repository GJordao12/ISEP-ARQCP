#include <stdio.h>

int string_to_int(char *str)
{
    int i = 0;
    int d = 0;

    while (str[i] != 0)
    {
        d = d + str[i] - 48;
        d = d * 10;
        i++;
    }

    return d;
}

int main()
{
    char str[] = "32123";

    printf("Char = \"%s\"\n", str);
    printf("Integer = %d\n", (string_to_int(str) / 10));

    return 0;
}
