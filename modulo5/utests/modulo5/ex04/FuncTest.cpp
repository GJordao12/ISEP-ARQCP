#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
void call_func(void (*f)(Student *,  char * ), int p_param, Student*  s, char * address ); 
}



//START: testGroup
TEST_GROUP(update_address)
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
    void given(char t_address[])
    { 
	call_func(update_address,2,&s,t_address); 
	CHECK_EQUAL(0x55,s.age);
	CHECK_EQUAL(0x5555,s.number); 
	BYTES_EQUAL(0xaa,s.name[79]); 
	STRCMP_EQUAL(t_address,s.address);
 	CHECK_EQUAL(0x55,s.filler); 
	CHECK_EQUAL(0x55555555,s.grades[0]); 
	BYTES_EQUAL(0xaa,s.address[strlen(t_address)+1]);  
	
    }
};
//END: testGroup

TEST(update_address, Zero)
{
    expect();
    given((char*)"");
}

TEST(update_address, One)
{
    expect();
    given((char*)"Nowhere Street");
}
 


TEST(update_address, Two)
{
    expect();
    given((char*)"Third  Street");
}

TEST(update_address, Three)
{
    expect();
    given((char*)"Third  Avenue,178");
}

