#include <stdio.h>
#include "power_ref.h"

int main(void)
{
    int base, expoente;
    int *ptr = &base;
    printf("Insira a base: ");
    scanf("%d", &base);
    printf("Insira o exponente: ");
    scanf("%d", &expoente);
    power_ref(ptr, expoente);
    printf("The result is: %d\n", *ptr);
}