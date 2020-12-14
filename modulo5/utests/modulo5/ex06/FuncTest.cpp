#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
int call_func(int (*f)(Student *, int,  int * ), int p_param, Student*  s, int minimum, const int * new_grades ); 
}



//START: testGroup
TEST_GROUP(locate_greater)
{ 
    Student s; 	
    int best_grades[10]; 
    int expected_grades[10]; 
    int  expected;
    void setup()
    { 
      s.age=0x55; 
      s.number=0x5555; 	
      s.filler=0x55;
      memset(s.grades,0,10*sizeof(int)); 	
      memset(best_grades,0xff,10*sizeof(int)); 	
      memset(s.name,0xaa,80); 	
      memset(s.address,0xaa,120); 	
    }
    void teardown()
    {
    }
    void expect(int n, const int  vec[]  ) 
    {
	expected=n; 
	memcpy(expected_grades,vec,n*sizeof(int)); 
    }
    void given(int minimum,const int new_grades[])
    {  
        int result; 
	memcpy(s.grades,new_grades,10*sizeof(int)); 
	result=call_func(locate_greater,3,&s,minimum, best_grades); 
	
	CHECK_EQUAL(0x55,s.age);
	CHECK_EQUAL(0x5555,s.number); 
	BYTES_EQUAL(0xaa,s.name[0]); 
 	CHECK_EQUAL(0x55,s.filler); 
	CHECK_TEXT(result<=10,"Wrong result for function"); 
	LONGS_EQUAL(expected,result);
	MEMCMP_EQUAL(expected_grades,best_grades,expected*sizeof(int)); 

	if (expected <10)
		LONGS_EQUAL(0xffffffff,best_grades[expected]); 
	
    }
};
//END: testGroup

TEST(locate_greater, Zero)
{
    expect(0,(const int[]){0});
    given(200,(const int[10]){1,2,3,4,5,6,7,8,9,10});
}  


TEST(locate_greater, One)
{
    expect(1,(const int[]){10});
    given(9,(const int[10]){1,2,3,4,5,6,7,8,9,10});
}  


TEST(locate_greater, Two)
{
    expect(2,(const int[]){9,10});
    given(8,(const int[10]){1,2,3,4,5,6,7,8,9,10});
}  


TEST(locate_greater,Five)
{
    expect(5,(const int[]){6,7,8,9,10});
    given(0,(const int[10]){-1,-2,-3,-4,-5,6,7,8,9,10});
}  

TEST(locate_greater,FiveB)
{
    expect(5,(const int[]){6,7,8,9,10});
    given(0,(const int[10]){6,7,8,9,10,-1,-2,-3,-4,-5});
}  

TEST(locate_greater, Ten)
{
    expect(10,(const int[]){1,2,3,4,5,6,7,8,9,10});
    given(-3,(const int[10]){1,2,3,4,5,6,7,8,9,10});
}  


