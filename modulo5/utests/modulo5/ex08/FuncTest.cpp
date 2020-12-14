#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
void call_func(void (*f)(s2 *, short *, int , char *), int p_param, s2*  s,
				 short*  w  , int j , char * b); 
}

// void fill_s2(s2 *s, short vw[3], int vj, char vc[3]); 

//START: testGroup
TEST_GROUP(fill_s2)
{ 
    s2 s; 	
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
    void given( short * vw , int vj,  char * vc  )
    {  
	call_func(fill_s2,4,&s,vw,vj,vc); 
	
	CHECK_EQUAL(vj,s.j);
	MEMCMP_EQUAL(vw,s.w,3*sizeof(short)); 
	MEMCMP_EQUAL(vc,s.c,3*sizeof(char)); 
	BYTES_EQUAL(0xaa,*((char*)(&(s.w[2])+1))); 
	BYTES_EQUAL(0xaa,*(char*)(&(s.c[2])+1)); 
	
    }
}; 
//END: testGroup

TEST(fill_s2, One)
{
    expect();
    given((short*)(const short[]) {1,2,3} ,4,(char*)(const char []){5,6,7});
}  



TEST(fill_s2, Two)
{
    expect();
    given((short*)(const short[]) {1000,20000,30000} ,-1,(char*)(const char []){50,60,70});
}  


TEST(fill_s2, MinusOne)
{
    expect();
    given((short*)(const short[]) {-1,-2,-3} ,-4,(char*)(const char []){-5,-6,-7});
}  

