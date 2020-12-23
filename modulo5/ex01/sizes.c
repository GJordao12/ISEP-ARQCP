#include <stdio.h>
union union_u1{
    char vec[32];
    float a;
    int b;
    } u;


struct struct_s1{
    char vec[32];
    float a;
    int b;
    } s;

void sizes(){

    printf("Tamanho de u: %d\n", sizeof(u)); // O tamanho da union é igual ao tamanho do maior dos dados. Neste caso é 32 pois o vetor vec tem tamanho 32.
    printf("Tamanho de s: %d\n", sizeof(s)); // Na struct os elementos estão todos seguidos, logo será 32 + 4 + 4 = 40. Temos de ter em conta tambem o alinhamento,
    //vec começa num endereço x multiplo de 4, logo "a" começa no endereço x + 32 (32 é multiplo de 4 por isso está seguido) e "b" começa no endereço x + 36, tambem multiplo de 4, logo esta seguido 
    //sem espaços vazios no meio deles.
    

}