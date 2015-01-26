Can virtual functions be private in C++?

#include<iostream>
using namespace std;
 
class Derived;
 
class Base {
private:
    virtual void fun() { cout << "Base Fun"; }
friend int main();
};
 
class Derived: public Base {
public:
    void fun() { cout << "Derived Fun"; }
};
 
int main()
{
   Base *ptr = new Derived;
   ptr->fun();
   return 0;
}
Output:

Derived fun()
