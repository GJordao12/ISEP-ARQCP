#include <stdio.h>
#include "new_matrix.h"
#include "fill_matrix.h"
#include "add_matrixes.h"

int main(){
    int nLinhas = 3;
    int nColunas = 3;
    //invoca a funçao e imprime o endereço da matrix
    int ** matrix1 = new_matrix(nLinhas, nColunas);
    int ** matrix2 = new_matrix(nLinhas, nColunas);


    //enche as matrizes com numeros aleatorios de 1 a 10
    fill_matrix(matrix1, nLinhas, nColunas);
    fill_matrix(matrix2, nLinhas, nColunas);

    //Imprime a matriz 1
    printf("\nMatriz 1:\n");
    int i, j;
    for (i = 0; i < nLinhas; i++){
        for(j = 0; j < nColunas; j++){
            printf("%d  ", matrix1[i][j]);
        }
        printf("\n");
    }
    
    //Imprime a matriz 2
    printf("\nMatriz 2:\n");
    for (i = 0; i < nLinhas; i++){
        for(j = 0; j < nColunas; j++){
            printf("%d  ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    //Adiciona as matrizes, devolvendo o apontador para o inicio da matriz reasultado. Imprime a matriz
    int ** result = add_matrixes(matrix1, matrix2, nLinhas, nColunas);
    printf("\nSoma das matrizes 1 e 2:\n");
    for (i = 0; i < nLinhas; i++){
        for(j = 0; j < nColunas; j++){
            printf("%d  ", result[i][j]);
        }
        
        printf("\n");
    }

    return 0;

}