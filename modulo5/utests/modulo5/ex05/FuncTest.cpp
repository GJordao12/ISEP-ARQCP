#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
void call_func(void (*f)(Student *,  int * ), int p_param, Student*  s, const int * new_grades ); 
}



//START: testGroup
TEST_GROUP(update_grades)
{ 
    Student s; 	
     // unused int  expected;
    void setup()
    { 
      s.age=0x55; 
      s.number=0x5555; 	
      s.filler=0x55;
      s.grades[0]=0x55555555; 	
      memset(s.name,0xaa,80); 	
      memset(s.address,0xaa,120); 	
    }
    void teardown()
    {
    }
    void expect( )
    {
    }
    void given(const int new_grades[])
    { 
	call_func(update_grades,2,&s,new_grades); 
	CHECK_EQUAL(0x55,s.age);
	CHECK_EQUAL(0x5555,s.number); 
	BYTES_EQUAL(0xaa,s.name[0]); 
 	CHECK_EQUAL(0x55,s.filler); 
	MEMCMP_EQUAL(new_grades,s.grades,10*sizeof(int)); 
	
    }
};
//END: testGroup

TEST(update_grades, Zero)
{
    expect();
    given((const int[10]){1,2,3,4,5,6,7,8,9,10});
}  



TEST(update_grades, One)
{
    expect();
    given((const int[10]){10000,20000,30000,40000,50000,60000,70000,80000,90000,100000});
} 

TEST(update_grades, Two)
{
    expect();
    given((const int[10]){-1,-1,-1,-1,-1,-1,-1,-1,-1,-1});
}  

