#include <stdlib.h>
#include "new_matrix.h"

int **add_matrixes(int ** matrix1, int ** matrix2, int nLinhas, int nColunas) {
    //Iteradores
    int i, j;
    //Cria a matriz resultado e recebe o apontador para a mesma
    int ** ptrResult = new_matrix(nLinhas, nColunas);
    //Cria um apontador copia para manter o vetor para a matriz resultado
    int ** ptrCopia = ptrResult;
    //Apontador para as linhas da matriz 1
    int ** ptrLinha_m1 = matrix1;
    //Apontador para as linhas da matriz 2
    int ** ptrLinha_m2 = matrix2;
    //Para cada linha das matrizes 1 e 2
    for(i = 0; i < nLinhas; i++){
        //Guardamos em ptr a address para o conteudo da linha
        int * ptr = *ptrCopia;
        //Para cada coluna
        for(j = 0; j < nColunas; j ++){
            //Guardamos a soma da do m1[i][j] + m2[i][j]
            int soma = (*(*ptrLinha_m1)) + (*(*ptrLinha_m2));
            //Guardamos a soma na matriz resultado
            *ptr = soma;
            //Proxima coluna da m1 (mesma linha)
            (*ptrLinha_m1)++;
            //Proximo espaço da matriz resultado
            ptr++;
            //Proxima coluna da m2 (mesma linha)
            (*ptrLinha_m2)++; 
        }
        //Próxima linha da m1, m2 e matriz resultado
        ptrLinha_m1++;
        ptrLinha_m2++; 
        ptrCopia++;
    }
    //Retorna a matriz resultado
    return ptrResult;
}