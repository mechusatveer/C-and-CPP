While a global variable has external linkage by default, a const global has internal 
linkage by default. In other words, C++ treats a global const definition as if the 
static had been used as in the following code.

const int a = 10;

//this have internal linkage
However, if we want to make a constant have external linkage, we can use the extern keyword
to override the default internal linkage:

extern const int a = 20;

#include <iostream>

class Car
{
	enum Color {silver = 0, maroon, red };  
	int year;
	int mileage = 34289;                   // error: not-static data members
	                                       // only static const integral data members 
	                                       // can be initialized within a class

	static int vin = 12345678;             // error: non-constant data member
	                                       // only static const integral data members 
	                                       // can be initialized within a class

	static const string model = "Sonata";  // error: not-integral type
	                                       // cannot have in-class initializer

	static const int engine = 6;           // allowed: static const integral type
};

int Car::year = 2013;                          // error: non-static data members 
                                               // cannot be defined out-of-class

int main()
{
	return 0;
}

The exception to the initialization of a static data member inside the class declaration 
is if the static data member is a const of integral or enumeration type.

#include <iostream>
int xGlobal = 7; 

struct Foo 
{ 
  int xMember; 

  static int xStatic; 

  Foo(int x) : xMember(x) {} 

  int a(int x = xGlobal) 
  { 
    return x; 
  } 

  int b(int x = xMember) // wrong: won't compile
  { 
    return x; 
  } 

  int c(int x = xStatic) 
  { 
    return x; 
  } 
}; 

int Foo::xStatic = 1; 

int main() 
{ 
  Foo f(911); 

  std::cout << f.a() << std::endl; 
  std::cout << f.b() << std::endl; 
  std::cout << f.c() << std::endl; 

  return 0; 
}


====================================================
const int MY_CONSTANT = 199;     // (note)In C++, this has internal linkage, it is same as "static const"
std::string MY_NAME = "BoGo";
void My_Function() {}

extern const int MY_CONSTANT;
extern std::string MY_NAME;
extern void MY_Function();

static const int MY_CONSTANT = 199;
static std::string MY_NAME = "BoGo";
static void My_Function() {}

namespace 
{
   const int MY_CONSTANT = 199;
   std::string MY_NAME = "BoGo";
   void My_Function() {}
}

