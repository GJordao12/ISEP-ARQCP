#include <stdio.h>

int main(void)
{
    int x = 20;
    int i;
    int auxiliar;
    int contador = 0;
    for (i = 1; i <= 32; i++)
    {
        auxiliar = x >> i;
        if (!(auxiliar & 1))
        {
            contador++;
        }
    }

    printf("%d\n", contador);
    return 0;
}
