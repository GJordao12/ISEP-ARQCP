#include <stdio.h>

int g_v[100] = {2, 2};
int g_n = 2;

int average_array(int v[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i];
    }
    return sum / n;
}

int average_global_array()
{
    int soma = 0;

    for (int i = 0; i < g_n; i++)
    {
        soma = soma + g_v[i];
    }
    return soma / g_n;
}
