#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
void call_func(void (*f)(s1 *, int,char, int , char ), int p_param, s1*  s,
				 int vi, char vc , int vj , char vd); 
}

// void fill_s1(s1 *s,int vi, char vc, int vj, char vd); 

//START: testGroup
TEST_GROUP(fill_s1)
{ 
    s1 s; 	
    /// int  expected; // not used 
    void setup()
    { 
      memset(&s,0xaa,sizeof(s)); 	
    }
    void teardown()
    {
    }
    void expect(  ) 
    {
    }
    void given(int vi, char vc , int vj,  char vd  )
    {  
	call_func(fill_s1,5,&s,vi,vc,vj,vd); 
	
	CHECK_EQUAL(vi,s.i);
	CHECK_EQUAL(vc,s.c);
	CHECK_EQUAL(vj,s.j);
	CHECK_EQUAL(vd,s.d);
	BYTES_EQUAL(0xaa,*(char*)(&(s.c)+1)); 
	BYTES_EQUAL(0xaa,*(char*)(&(s.d)+1)); 
	
    }
};
//END: testGroup

TEST(fill_s1, One)
{
    expect();
    given(1,2,3,4);
}  



TEST(fill_s1, MinusOne)
{
    expect();
    given(-1,-2,-3,-4);
}  

TEST(fill_s1, Big)
{
    expect();
    given(100000,70,300000,70);
}  

