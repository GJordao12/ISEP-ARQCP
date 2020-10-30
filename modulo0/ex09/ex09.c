#include <stdio.h>
#include <string.h>

int containsAtLeastOneOf(char *baseStr, char *toVerify)
{
    int pos = 0;
    int position = 0;
    int len = strlen(baseStr);
    int numberOfChars = strlen(toVerify);

    while (pos < len)
    {
        while (position < numberOfChars)
        {
            if (baseStr[pos] == toVerify[position])
            {
                return 1;
            }
            position++;
        }
        position = 0;
        pos++;
    }
    return -1;
}

char numberFormaterIdentifier(char *number)
{
    char hexa[7] = "ABCDEF";
    char deca[3] = "89";
    char octa[7] = "234567";
    char bina[3] = "01";

    if (containsAtLeastOneOf(number, hexa) == 1)
    {
        return 'H';
    }
    if (containsAtLeastOneOf(number, deca) == 1)
    {
        return 'D';
    }
    if (containsAtLeastOneOf(number, octa) == 1)
    {
        return 'O';
    }
    if (containsAtLeastOneOf(number, bina) == 1)
    {
        return 'B';
    }
    return 'E';
}

int main(void)
{
    char number[] = "1001011";
    char format = numberFormaterIdentifier(number);
    if (format == 'H')
    {
        printf("%s is Hexadecimal.\n", number);
    }
    if (format == 'D')
    {
        printf("%s is Decimal.\n", number);
    }
    if (format == 'O')
    {
        printf("%s is Octal.\n", number);
    }
    if (format == 'B')
    {
        printf("%s is Binary.\n", number);
    }
    if (format == 'E')
    {
        printf("No format could be identified!\n");
    }

    return 0;
}