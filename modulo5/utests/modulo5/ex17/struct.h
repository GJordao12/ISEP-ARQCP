#ifndef STRUCT_H
#define STRUCT_H 

typedef union {
        int a;
        char b;
        short c;
        long int d;
}unionB; 



typedef struct {
   short int a[3];
   char b;
   long long int c;
   int d;
   unionB ub;
   char e;
}structA;

#endif 
