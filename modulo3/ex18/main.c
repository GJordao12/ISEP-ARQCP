#include <stdio.h>
#include "asm.h"

int *ptrsrc, *ptrdest, num = 12;

int main(void){
	
	int src[] = {12, 13, 1, 4, 5, 8, 4, 4, 9, 16, 0, 20};
	int dest[12] = {0}, i;
	
	ptrsrc = src;
	ptrdest = dest;
	
	//sort_array();
	
	int num_elements = sort_without_reps();
	
	//int verifica = exists_in_array();
	//printf("%d\n", verifica);
	
	for(i = 0; i < 12; i++){
		printf("%d ", src[i]);
	}
	printf("\n");
	
	for(i = 0; i < 12; i++){
		printf("%d ", dest[i]);
	}
	printf("\n");
	
	printf("O número de elementos que foram postos no segundo array é %d\n", num_elements);
	
	return 0;
}