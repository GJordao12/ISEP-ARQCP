#include <stdio.h>
#include "asm.h"

int i = 0, j = 0, h = 0, g = 0, r = 0;
int main()
{
    printf("Insira o i: ");
    scanf("%d", &i);

    printf("Insira o j: ");
    scanf("%d", &j);

    int f()
    {
        if (i == j)
            h = i - j + 1;
        else
            h = i + j - 1;
        return h;
    }

    int f2()
    {
        int flag;
        if (i > j)
        {
            i = i - 1;
            flag = 1;
        }
        else
        {
            j = j + 1;
            h = j * i;
            flag = 2;
        }
        if (flag == 1)
        {
            i = i + 1;
        }
        else
        {
            j = j - 1;
        }
        return h;
    }

    int f3()
    {
        if (i >= j)
        {
            h = i * j;
            g = i + 1;
        }
        else
        {
            h = i + j;
            g = i + j + 2;
        }
        r = g / h;
        return r;
    }

    int f4()
    {
        if (i + j < 10)
            h = 4 * i * i;
        else
            h = j * j / 3;
        return h;
    }

    printf("\n#####Código em C:#####\n");
    printf("f() -> %d\n", f());
    printf("f2() -> %d\n", f2());
    printf("f3() -> %d\n", f3());
    printf("f4() -> %d\n", f4());
    printf("######################\n\n");

    printf("#####Código em Assembly:#####\n");
    printf("f() -> %d\n", fa());
    printf("f2() -> %d\n", fa2());
    printf("f3() -> %d\n", fa3());
    printf("f4() -> %d\n", fa4());
    printf("#############################\n\n");

    return 0;
}
