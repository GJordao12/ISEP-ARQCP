int find_matrix(int ** m, int y, int k, int num){
    //Uma matriz é um vetor de apontadores
    //Guarda o apontador para o primeiro elemento da matriz
    int ** ptrLinha = m;
    //Guarda o apontador para as colunas (apontado pela linha)
    int * ptrColuna = *ptrLinha;
    //Iteradores
    int i, j;
    //Até ao nº de linhas
    for(i = 0; i < y; i++){
        //Até nº de colunas
        for (j = 0; j < k; j++){
            //Se o apontado pelo apontador da coluna (m[i][j]) for igual ao num
            if((*ptrColuna) == num){
                //Encontrou o número: retorna 1
                return 1;
            }
            //Coluna seguinte 
            ptrColuna++;
        }
        //Próxima linha 
        ptrLinha++;
        //Atualiza o apontador da coluna para a linha seguinte
        ptrColuna = *ptrLinha;
    }
    //Se chegou a este ponto, significa que não encontrou o número na matriz: retorna 0
    return 0;
}