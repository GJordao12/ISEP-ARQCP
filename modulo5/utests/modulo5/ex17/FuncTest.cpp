#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
#include "zxc_func.h" 
#include "dmt2.h" 
char call_func(char (*f)(structA **, int, int ), int p_param, structA ** p1 , int p2, int p3 ); 

}

//START: testGroup
TEST_GROUP(return_unionB_b)
{
    // char  expected;   // not used  
    
    void setup()
    {
  
    }
    void teardown()
    {
    }
    void expect(   )
    {
    
    }
    void given( int rows , int columns)
    { 
	structA **m; 
    char result; 
	m=zxc_new_matrix(rows,columns); 
	int pok=dmt_has(m); 
	int psize=dmt_size(m); 
	CHECK_TEXT(pok,"Pointer not in Dynamic Memory"); 
    LONGS_EQUAL(rows*sizeof(int*), psize);
    
   int i,j; 
   for (i=0;i<rows;i++) 
   	for (j=0;j<columns;j++) 
		m[i][j].ub.b=1+i*columns+j; 
   for (i=0;i<rows;i++) 
   	for (j=0;j<columns;j++) 
		{  
           result=call_func(return_unionB_b,3,m,i,j);
           BYTES_EQUAL(1+i*columns+j,result); 

        } 	
   	
	
   for(j = 0; j < rows ; j++) free(m[j]);
    free(m);

    
    }
};
//END: testGroup


TEST(return_unionB_b, One)
{
    expect(); 
    given(1,1);
}


TEST(return_unionB_b, OneB)
{
    expect(); 
    given(1,1);
}


TEST(return_unionB_b,Two)
{
    expect();
    given(2,2); 
}




TEST(return_unionB_b,Three)
{
    expect();
    given(3,3);
}


TEST(return_unionB_b,Ten)
{
    expect();
    given(10,10);
}

