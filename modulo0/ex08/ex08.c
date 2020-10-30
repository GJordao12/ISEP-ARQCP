#include <stdio.h>

int i = 0;

int x_int(char *str)
{
    int d = 0;

    while (str[i] != '.')
    {
        d = d + str[i] - 48;
        d = d * 10;
        i++;
    }

    return d / 10;
}

int x_frac(char *str)
{

    int d = 0;
    i++;

    while (str[i] != 0)
    {
        d = d + str[i] - 48;
        d = d * 10;
        i++;
    }

    return d / 10;
}

int main(void)
{

    char muc[] = "123.456";

    printf("Integer part: %d\n", x_int(muc));
    printf("Fractional part: %d\n", x_frac(muc));
}
