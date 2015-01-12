const char *pHello = "hello";

string str = "hello";
const char *cp = str.c_str();
char *p = const_cast<char *> (str.c_str()); 

#include <sstream>
char *int2strB(int n, char *s)
{
    stringstream ss;
    ss << n;
    string cpp_string = ss.str();
    const char *pCstring = cpp_string.c_str();
    s = const_cast<char *>(pCstring);
    return s;
}

we can't even copy arrays using assignment.(arrayA = arrayB is not allowed)

int a[100];
int b[100];
a = b;     //error

char cArray[10];
cArray = "Hello!";  //error

char *cPtr;
cPtr = "Hello!";    //OK

char non_string [10] = {'n','o','n','_','s','t','r','i','n','g'};
char a_string [9] = {'a','_','s','t','r','i','n','g','\0'};

Both of these are arrays of char, but only the second is a string 


#include <string>
#include <cstring>

int main()
{
	using namespace std;
	string str1;
	const char *pc = "I am just a character array";

	// C++ string type automatically converting a C character string
	// into a string object. 
        // string class defines a char* - to-string conversion, which makes
        // it possible to initialize a string object to a C-style string.
      
	str1 = pc;   //ok


	// error C2440: 'initializing':
	// cannot convert from 'std::string' to 'char *'

	char *p1 = str1;  //not ok


	// error C2440: 'initializing' :
	// cannot convert from 'const char *' to 'char *'

	char *p2 = str1.c_str();   //not there yet


	const char *p3 = str1.c_str();  //ok


        // removing (casting) constantness 

        char *p4 = const_cast<char *> (str1.c_str());  // ok

	return 0;
}

