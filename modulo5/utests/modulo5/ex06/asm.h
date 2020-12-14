#ifndef ASM_H 
#define ASM_H 
typedef struct {
       char age;
       char filler; 
       short number;
       int grades[10];
       char name[80];
       char address[120];
} Student;

int locate_greater(Student *s, int minimum , int * greater_grades);
#endif 

