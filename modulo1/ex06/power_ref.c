void power_ref(int *x, int y)
{

    if (y == 0)
    {
        *x = 1;
    }

    int result = 1;
    for (int i = 1; i <= y; i++)
    {
        result = *x * result;
    }

    *x = result;
}
