void array_sort2(int *vec, int n)
{
   int i, j, tmp;
   int *ptr = vec;
   for (i = 0; i < n; i++)
   {
      for (j = i + 1; j < n; j++)
      {
         if (*(ptr + i) > *(ptr + j))
         {
            tmp = *(ptr + i);
            *(ptr + i) = *(ptr + j);
            *(ptr + j) = tmp;
         }
      }
   }
}