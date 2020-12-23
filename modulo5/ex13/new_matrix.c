#include <stdlib.h>
// FUNÇÃO COMENTADA NO EXERCICIO 11. NADA MUDOU.
int **new_matrix(int lines, int columns){
    int i;
    int ** ptrmatrix = (int **) malloc(lines * sizeof(int));
    int ** ptrmatrix1 = ptrmatrix;
    for(i=0; i < lines; i++){
        *ptrmatrix1 = (int *) calloc(columns, sizeof(int));
        ptrmatrix1++;
    }
    

    return ptrmatrix;
}