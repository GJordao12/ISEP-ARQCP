
void compress_shorts(short *shorts, int n_shorts, int *integers)
{
    for (int i = 0; i < (n_shorts - 1); i++)
    {
        *(integers + i) = ((int)*(shorts + i)) + ((int)*(shorts + i + 1));
    }
}
