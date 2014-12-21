//How to handle constructor failure
//We cannot return a error
//1. Throw an exception
//2. Declare a error flag
//3. Set it to show constrcutro failure

//What abt if new itself get failed
//Constructor will not even get called
// new will throw an exception in case of memory failure

//we use std::nothrow with new operator so in place of exception
//new will return a null ptr in case of failure

/********************************************************************/
How to handle destructor failure

Golden rule - never throw an exception
Write this failure in log file
/********************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class A
{
  int x;
  public:
  A(int i):x(i)
  {
     throw 5;
  }
  void print()
  {
    cout<<x<<endl;
  }
};

int main()
{
    try
    {
        A *a = new A(3);
    }
    catch(int &x)
    {
       cout<<x<<endl;
    }
    return 0;
}
