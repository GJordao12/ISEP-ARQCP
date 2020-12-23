#ifndef FILL_GROUP_H
#define FILL_GROUP_H
typedef struct {
    int n_students;
    unsigned char * individual_grades;
    } group;

void fill_group(group *g , int numStudents, unsigned char * grades);
#endif