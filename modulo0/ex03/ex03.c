#include <stdio.h>

void fill_array(int *vec)
{

     printf("Enter 30 numbers:\n");
     for (int i = 0; i < 30; i++)
     {
          printf("-> ");
          scanf("%d", &vec[i]);
     }
}

int main(void)
{

     int values[30];
     fill_array(values);
     double sum = 0;
     for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
     {
          sum = sum + values[i];
     }

     printf("Average: %.2f\n", (sum / 30));

     return 0;
}