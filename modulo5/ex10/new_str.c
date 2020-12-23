# include <stdlib.h>

char *new_str(char str[80]){
    //Reserva apenas 1 byte na heap, pois não sabemos quantos bytes vamos necessitar
    char *new_str = (char *) malloc(1);
    //Contador
    int i = 0;
    //Enquanto o char não for for null
    while(str[i] != '\0'){
        //Copia o char da str para a nova str
        *(new_str+i) = str[i];
        //Se o próximo byte for null, já não adiciona mais espaço
        if(str[i+1] != '\0'){
            /**Se não for null, então redimensiona o tamanho da nova string (i representa o tamanho da str - 1, 
            por isso adicionamos mais 2)**/
            new_str = (char *) realloc(new_str, i+2);
        }
        //Contador ++
        i++; 
    }
    //Retorna o apontador da nova string: como a string é um vetor de chars, retornamos o apontador para a primeira letra
    return new_str;
}