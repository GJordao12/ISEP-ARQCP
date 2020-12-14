#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
short  call_func(short (*f)(structB *), int p_param, structB*  s);
short * call_func3(short * (*f)(structB *), int p_param, structB*  s);  
}


//START: testGroup
TEST_GROUP(fun1)
{ 
   structA sa; 		
   structB sb;  
	short  expected; 

    void setup()
    { 
      memset(&sa,0xaa,sizeof(sa)); 	
      memset(&sb,0xaa,sizeof(sb)); 	
      sb.b=&sa; 
    }
    void teardown()
    {
    }
    void expect( short n   ) 
    { 
       expected=n; 
    }
    void given( short value  )
    {   
	short result;
	sb.a.x=value; 
	result=call_func(fun1,1,&sb); 
	CHECK_EQUAL(value,result);
    }
}; 
//END: testGroup

TEST(fun1, One)
{
    expect(1);
    given(1);
}  

TEST(fun1, MinusOne)
{
    expect(-1);
    given(-1);
}  


TEST(fun1, Zero)
{
    expect(0);
    given(0);
}  



//START: testGroup
TEST_GROUP(fun2)
{ 
   structA sa; 		
   structB sb;  
	short  expected; 

    void setup()
    { 
      memset(&sa,0xaa,sizeof(sa)); 	
      memset(&sb,0xaa,sizeof(sb)); 	
      sb.b=&sa; 
    }
    void teardown()
    {
    }
    void expect( short n   ) 
    { 
       expected=n; 
    }
    void given( short value  )
    {   
	short result;
	sb.z=value; 
	result=call_func(fun2,1,&sb); 
	CHECK_EQUAL(value,result);
    }
}; 
//END: testGroup

TEST(fun2, One)
{
    expect(1);
    given(1);
}  

TEST(fun2, MinusOne)
{
    expect(-1);
    given(-1);
}  


TEST(fun2, Zero)
{
    expect(0);
    given(0);
}  



//START: testGroup
TEST_GROUP(fun4)
{ 
   structA sa; 		
   structB sb;  
	short  expected; 

    void setup()
    { 
      memset(&sa,0xaa,sizeof(sa)); 	
      memset(&sb,0xaa,sizeof(sb)); 	
      sb.b=&sa; 
    }
    void teardown()
    {
    }
    void expect( short n   ) 
    { 
       expected=n; 
    }
    void given( short value  )
    {   
	short result;
	sb.b->x=value; 
	result=call_func(fun4,1,&sb); 
	CHECK_EQUAL(value,result);
    }
}; 
//END: testGroup

TEST(fun4, One)
{
    expect(1);
    given(1);
}  

TEST(fun4, MinusOne)
{
    expect(-1);
    given(-1);
}  


TEST(fun4, Zero)
{
    expect(0);
    given(0);
}  


//START: testGroup 
TEST_GROUP(fun3)
{ 
   structA sa; 		
   structB sb;  
	short  * expected; 

    void setup()
    { 
      memset(&sa,0xaa,sizeof(sa)); 	
      memset(&sb,0xaa,sizeof(sb)); 	
      sb.b=&sa; 
    }
    void teardown()
    {
    }
    void expect( short * n   ) 
    { 
       expected=n; 
    }
    void given(   )
    {   
	short * result;
	result=call_func3(fun3,1,&sb); 
	POINTERS_EQUAL(expected,result);
    }
}; 
//END: testGroup

TEST(fun3, One)
{
    expect(&sb.z);
    given();
}  






