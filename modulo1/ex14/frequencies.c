void frequencies(float *grades, int n, int *freq)
{
    int count, index, j, grade;

    for (index = 0; index < 21; index++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            grade = (int)*(grades + j);
            if (grade == index)
            {
                count++;
            }
        }
        *(freq + index) = count;
    }
}
