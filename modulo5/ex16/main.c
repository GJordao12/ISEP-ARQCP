#include <stdio.h>
#include "fill_group.h"
#include "approved_semester.h"

int main(){
    //Iterador
    int i;
    //Nº de estudantes
    int n_students = 3;
    //Array de notas individuais
    unsigned char grades[] = {0b11111000, 0b11001100, 0b11011001};
    //Apontador para o vetor de notas
    unsigned char * individual_grades = grades;
    //Intancia de group
    group grupo;
    //Vetor para a estrutura grupo
    group *g =  &grupo;

    //Enche o grupo com os valores estabelcidos anteriormente
    fill_group(g, n_students, individual_grades);

    //Imprime o nº de estudantes e as notas
    printf("Number of students: %d\n\n", g->n_students);
    for(i = 0; i < n_students; i++){
        printf("Grades %dº: %d\n", i+1, g->individual_grades[i]);
    }
    printf("\n");

    //Calcula o nº de estudantes aprovados no semestre e imprime o resultado
    int resultado = approved_semester(g);
    printf("Nº de alunos aprovados neste semestre: %d\n", resultado);

    return 0;
}