#include "fill_group.h"
#include <stdio.h>
#include <string.h>

void fill_group(group *g, int numStudents, unsigned char * grades){
    g->n_students = numStudents;
    g->individual_grades = grades;
}