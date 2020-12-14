#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
#include "dmt2.h" 
char* call_func(char *  (*f)(char * ), int p_param,char * p1 ); 

}

//START: testGroup
TEST_GROUP(new_str)
{
    int  expected;
    char sexp[80]; 
    void setup()
    {
        expected = 0;
	memset(sexp,0,80);  
    }
    void teardown()
    {
    }
    void expect(int num, char *str  )
    {
        expected = num;
	strcpy(sexp,str); 
    }
    void given(const char  p1[])
    { 
	char* result; 
 	int slen=strlen(p1)+1; 
	result=call_func(new_str,2,(char*)p1); 
	int pok=dmt_has(result); 
	int plen=dmt_size(result); 
	CHECK_TEXT(pok,"Pointer not in Dynamic Memory"); 
        STRCMP_EQUAL(p1,result); 
        LONGS_EQUAL(slen, plen);
    }
};
//END: testGroup

TEST(new_str, Zero)
{
    expect(1,(char*)"" );
    given("");
}

TEST(new_str, One)
{
    expect(2,(char*)"1" );
    given("1");
}



TEST(new_str,Two)
{
    expect(3,(char*)"ab");
    given("ab");
}


TEST(new_str,Three)
{
    expect(4,(char*)"abc");
    given("abc");
}

