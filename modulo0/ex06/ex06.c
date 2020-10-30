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

float average(float a, float b)
{
    return (a + b) / 2;
}

int main(void)
{
    printf("Write down the two values:\n");

    printf("a: ");
    char a[12];
    scanf("%s", a);

    printf("b: ");
    char b[12];
    scanf("%s", b);

    printf("The average of the two chosen numbers is: %.2f\n", average(string_to_int(a) / 10, string_to_int(b) / 10));

    return 0;
}
