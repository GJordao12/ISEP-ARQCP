#include "result.h"

long long total_risco(int *vec, int num)
{
    int i = 0, contador = 0;
    long long soma = 0;
    int verif = -1; // variável auxiliar para verficar se exitem 3 valores válidos consecutivos.
    for (i = 0; i < (num * 2); i++) // o ciclo é feito em pares de valores (tempo, proximidade).
    {
        tempo = *(vec + i);
        i++; // passa para o próximo valor do par.
        proximidade = *(vec + i);
        long long valor = result();
        if (valor != 0) // verificação da validade do risco.
        {
            contador++;
            if (contador == 3)
            {
                verif = 1;
            }
        }
        else
        {
            contador = 0;
        }
        soma += valor;
    }
    if (verif == 1)
    {
        return soma; // se existerem 3 valores consecutivos válidos.
    }
    return -1; // se não existerem 3 valores consecutivos válidos.
}
