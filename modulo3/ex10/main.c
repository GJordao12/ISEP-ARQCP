#include <stdio.h>
#include "asm.h"

char *ptr1;
char *ptr2;
char *ptr3;
int main(void)
{
    char p1[] = "casa";
    char p2[] = "mento";
    char p3[80];
    ptr1 = p1;
    ptr2 = p2;
    ptr3 = p3;

    printf("Primeira frase: %s\n", p1);
	printf("Segunda frase: %s\n", p2);
	
	str_cat();
	
	printf("As frases juntas: %s\n", p3);
    return 0;
}
