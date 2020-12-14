#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
#include "dmt2.h" 
int call_func(int (*f)(int**, int, int,int), int p_param, int ** p1 , int p2, int p3, int p4); 

}

//START: testGroup
TEST_GROUP(new_matrix)
{
    int  expected;   // found or not found 
    
    void setup()
    {
        expected=-1;  
    }
    void teardown()
    {
    }
    void expect( int n  )
    {
      expected=n;  
    }
    void given( int rows , int columns,int to_search)
    { 
	int **m; 
        int result; 
	m=new_matrix(rows,columns); 
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

   result=call_func(find_matrix,4,m,rows,columns,to_search);  

   LONGS_EQUAL(expected,result); 	
	
   for(j = 0; j < rows ; j++) free(m[j]);
    free(m);

    
    
    
    }
};
//END: testGroup


TEST(new_matrix, One)
{
    expect(1); 
    given(1,1,1);
}


TEST(new_matrix, OneB)
{
    expect(0); 
    given(1,1,0);
}


TEST(new_matrix,Two)
{
    expect(1);
    given(2,2,4);
}


TEST(new_matrix,TwoB)
{
    expect(0);
    given(2,2,-1);
}

TEST(new_matrix,Three)
{
    expect(1);
    given(3,3,1);
}

TEST(new_matrix,ThreeB)
{
    expect(0);
    given(3,3,19);
}

TEST(new_matrix,Ten)
{
    expect(1);
    given(10,10,100);
}

