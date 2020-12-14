#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
#include "dmt2.h" 
int call_func(int  (*f)(group * ), int p_param, group * p1 ); 

}

//START: testGroup
TEST_GROUP(approved_semester)
{
    int  expected; 
    group g;
    void setup()
    {
        expected = 0;
        g.individual_grades=NULL;
        g.n_students=0;
  
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
	
    }
    void given(int n, unsigned  char  p1[])
    { 
	int result; 
 	g.individual_grades=p1;
    g.n_students=n;  


	result=call_func(approved_semester,1,&g); 
	LONGS_EQUAL(expected,result);

    result=call_func(approved_semester,1,&g);   // twice to see if some bug 
	LONGS_EQUAL(expected,result);               // has changed the values 

    }
};
//END: testGroup

TEST(approved_semester, Zero)
{
    unsigned  char v[]={0};
    expect(0);
    given(1,v);
}

TEST(approved_semester, One)
{
    unsigned  char v[]={0b11111};
    expect(1);
    given(1,v);
}



TEST(approved_semester, Two)
{
    unsigned  char v[]={0b11111,0b10000000,0b11111000,0};
    expect(2);
    given(4,v);
}


TEST(approved_semester, Three)
{
    unsigned  char v[]={0b1111,0b11111,0b10000000,0b11111000,0b11110000,0xff};
    expect(3);
    given(6,v);
}

