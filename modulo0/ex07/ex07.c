#include <stdio.h>

int count_words(char *str)
{
    int i = 0;
    int amount = 0;

    while (str[i] != 0)
    {
        if (str[i] == ' ')
        {
            amount++;
        }
        i++;
    }
    amount++;

    return amount;
}

int main()
{

    char f1[] = "Hello! How are you?";
    char f2[] = "Im fine, thanks!";
    char f3[] = "My name is ARQCP.";

    printf("\"%s\" have %d words.\n", f1, count_words(f1));
    printf("\"%s\" have %d words.\n", f2, count_words(f2));
    printf("\"%s\" have %d words.\n", f3, count_words(f3));
}