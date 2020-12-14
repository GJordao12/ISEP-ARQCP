#include <string.h> 
#include <stdlib.h>
#include "struct.h" 
structA ** zxc_new_matrix (int lines, int columns) 
// avoid name "collision" with other functions

{ 
   structA **m=malloc(lines*sizeof(structA*)); 
    
   int i; 
   for (i=0;i<lines;i++) 
	m[i]=malloc(columns*sizeof(structA)); 
   		
   return m; 

} 

