#include <stdio.h>
#include <string.h>

int main( void ){

    //Alínea a: Define union com char [], float e int
    /**union union_u1{
        char vec[32];
        float a;
        int b;
    } u;
    **/

   //Alínea b
   struct struct_s1{
        char vec[32];
        float a;
        int b;
    } s;


    /**Alínea a: Define apontador para union u
    union union_u1 * ptr = &u;**/

    struct struct_s1 * ptr = &s;

    //Copia a string "arquitetura de computadores" para o elemento vec de u e imprime a mesma
    strcpy(ptr->vec, "arquitectura de computadores" );
    printf( "[1]=%s\n", ptr->vec );

    //Atribui 123.5 ao elemento a de u e imprime a mesma
    ptr->a = 123.5;
    printf( "[2]=%f\n", ptr->a );

    //Atribui 2 ao elemento b de u e imprime a mesma
    ptr->b = 2;
    printf( "[3]=%d\n", ptr->b );

    //Imprime o que atribuiu em último (2) em formato de string
    printf( "[1]=%s\n", ptr->vec );

    //Imprime o que atribuiu em último (2) em formato de float
    printf( "[2]=%f\n", ptr->a );

    //Imprime o que atribuiu em último (2) em formato de inteiro
    printf( "[3]=%d\n", ptr->b );

    return 0;

    /**Alíena a: O programa imprime primeiro "arquitetura de computadores", em segundo 123.5, terceiro 2 e 
     * depois nas 3 seguintes impressões o valor 2 (que foi a última atribuição) em formato string, float e 
     * finalmente em inteiro. Como se trata de um número inteiro, então nas impressões de string e float o resultado
     * será o inteiro 2 em float(0.000000) e em string. Isto deve-se ao facto de numa union apenas podemos utilizar 
     * um campo de cada vez. Esta union tem um tamanho de 32 bits (todas as variáveis têm este tamanho) e esta memória
     * é partilhada por todos os elementos. Quando atribuimos 2 ao campo b, interfere com todos os campos, sendo este
     * o único valor guardado.
    **/

   /**Alínea b: Depois de ter declarado uma estrutura, o progama imprimiu sempre "arquitetura de computadores" com o campo 
    * vec (char[]), imprimiu sempre 123.5 com o campo a (float) e imprimiu sempre 2 com o campo b (inteiro). A diferença
    * para a alínea anterior deve-se ao facto de que as estruturas não partilham a memória como as union. A estrutura 
    * definida tem 40 bytes. Assim, todos os campos têm o seu valor definido e não é subscrito pela atribuição dos outros
    * campos, como acontece nas union.
    **/
}