#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
#include "dmt2.h" 
int ** call_func(int**  (*f)(int , int ), int p_param, int  p1 , int p2); 

}

//START: testGroup
TEST_GROUP(new_matrix)
{
    // int  expected;   // not used 
    
    void setup()
    {
         
    }
    void teardown()
    {
    }
    void expect(  )
    {
       
    }
    void given( int rows , int columns)
    { 
	int **m; 
 
	m=call_func(new_matrix,2,rows,columns); 
	int pok=dmt_has(m); 
	int psize=dmt_size(m); 
	CHECK_TEXT(pok,"Pointer not in Dynamic Memory"); 
    LONGS_EQUAL(rows*sizeof(int*), psize);
    
   int i,j; 
   for (i=0;i<rows;i++) 
   	for (j=0;j<columns;j++) 
		m[i][j]=1+i*columns+j; 
   int sum=0; 
   for (i=0;i<rows;i++) 
   	for (j=0;j<columns;j++) 
		sum+=m[i][j]; 	
   LONGS_EQUAL((rows*columns+1)*(rows*columns)/2, sum);	
   for(j = 0; j < rows ; j++) free(m[j]);
    free(m);

    
    
    
    }
};
//END: testGroup


TEST(new_matrix, One)
{
    expect(); 
    given(1,1);
}



TEST(new_matrix,Two)
{
    expect();
    given(2,2);
}


TEST(new_matrix,Three)
{
    expect();
    given(3,3);
}

TEST(new_matrix,Ten)
{
    expect();
    given(10,10);
}

