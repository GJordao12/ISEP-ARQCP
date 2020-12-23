#include <stdlib.h>

int **new_matrix(int lines, int columns){
    int i; //inicia o indice a 0
    int ** ptrmatrix = (int **) malloc(lines * sizeof(int)); //uma matriz é um array de apontadores, 
    // onde cada elemento é um apontador para outro array (colunas).
    //Então reservamos (4 * nº de linhas) bytes
    int ** ptrmatrix1 = ptrmatrix; //copia do apontador para a matriz para não o perder
    for(i=0; i < lines; i++){ //para cada linha 
        *ptrmatrix1 = (int *) calloc(columns, sizeof(int)); //reserva (4* nº de colunas) bytes e coloca-os a 0. Também atribui a cada linha da matriz
        //um endereço para as suas colunas
        ptrmatrix1++; // proxima linha
    }
    

    return ptrmatrix; //devolva apontador para a matriz
}