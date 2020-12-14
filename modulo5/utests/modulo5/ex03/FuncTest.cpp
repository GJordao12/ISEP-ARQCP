#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
void call_func(void (*f)(Student *, char , short , char * , char * ), int p_param, Student*  s, char age, 
			short number, char * name , char * address ); 
}



//START: testGroup
TEST_GROUP(fill_student)
{ 
    Student s; 	
     // unused int  expected;
    void setup()
    { 
      s.age=0; 
      s.number=0; 	
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
    void given(char t_age, short t_number, char t_name[] , char t_address[])
    { 
	call_func(fill_student,5,&s,t_age,t_number,t_name,t_address); 
	CHECK_EQUAL(t_age,s.age);
	CHECK_EQUAL(t_number,s.number); 
	STRCMP_EQUAL(t_name,s.name); 
	STRCMP_EQUAL(t_address,s.address);
 	CHECK_EQUAL(0x55,s.filler); 
	CHECK_EQUAL(0x55555555,s.grades[0]); 
	BYTES_EQUAL(0xaa,s.name[strlen(t_name)+1]);  
	BYTES_EQUAL(0xaa,s.address[strlen(t_address)+1]);  
	
    }
};
//END: testGroup

TEST(fill_student, Zero)
{
    expect();
    given(10, 200,(char*)"",(char*)"");
}

TEST(fill_student, One)
{
    expect();
    given(50, -1,(char*)"First Student",(char*)"Nowhere Street");
}
 


TEST(fill_student, Two)
{
    expect();
    given(-1, 23561,(char*)"Second Student",(char*)"Third  Street");
}

TEST(fill_student, Three)
{
    expect();
    given(71, 23561,(char*)"Third after Second  Student",(char*)"Third  Avenue,178");
}

