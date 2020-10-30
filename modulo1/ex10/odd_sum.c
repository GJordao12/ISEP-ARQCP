int odd_sum(int *p)
{

    int soma = 0;
    for (int i = 0; i < (*p) - 1; i++)
    {
        soma += *(p + 1);
    }

    return soma;
}
