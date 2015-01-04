public exception {
public:
  virtual const char* what() const throw();
}; 


bad_alloc 
This exception is thrown whenever the global operator new fails 
(except when the nothrow version of new is used). This is the most
important exception because it might occur at any time in any nontrivial program.

bad_cast 
This exception is thrown by dynamic_cast if a type conversion on a reference 
fails at runtime.


bad_exception
This is used to handle unexpected exceptions. It does this by using the function unexpected().
unexpected() is called if a function throws an exception that is not listed in an exception 
specification. For example:



#include <iostream>
#include <exception>
using namespace std;

class child_exception: public exception {
  virtual const char* what() const throw(){
    return "child exception occurred";
  }
}; 

int main () {
  try {
    child_exception cex;
    throw cex;
  }
  catch (exception& e) {
    cout << e.what() << endl;
  }
  return 0;
}

class E1;
	class E2;
	void f() throw(E1, std::bad_exception) {	
				//throws exception of type E1 or 
				//bad_exception for any other exception type
		throw E1();	//throws exception of type E1
		throw E2();	//calls unexpected(), which throws bad_exception()
	}
	
	bad_typeid 
This exception is thrown by typeid. If the argument to typeid is zero or the 
null pointer, this exception is thrown.

#include <iostream>
#include <exception>
using namespace std;

int main () {
  try {
	long double * arr= new long double[150000000];
  }
  catch (bad_alloc&){
	cout << "Error allocating memory." << endl;
  }
  return 0;
}
