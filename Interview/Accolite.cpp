-----------------------------------------------------------------------------------
1) Can we decalre a destructor as pure virtual

There is nothing wrong to declare destructor as virtual or pure virtual
below two example show this.

#include<iostream>
using namespace std;

class A
{
   public:
   virtual ~A()= 0;
};

int main()
{
   return 0;
}

#include<iostream>
using namespace std;

class A
{
   public:
   virtual ~A()= 0;
};

A::~A()
{
   cout<<"destructor called"<<endl;
}

int main()
{
   return 0;
}
--------------------------------------------------------------------------------------
2)Can we declare a virtual function as inline
  Can virtual functions be inlined?
  
  By default all the functions defined inside the class are implicitly or 
  automatically considered as inline except virtual functions (Note that inline
  is a request to the compiler and its compilers choice to do inlining or not).
  
  Whenever virtual function is called using base class reference or pointer it 
  cannot be inlined (because call is resolved at runtime), but whenever called 
  using the object (without reference or pointer) of that class, can be inlined 
  because compiler knows the exact class of the object at compile time.
  
  #include <iostream>
using namespace std;
class Base
{
public:
    virtual void who()
    {
        cout << "I am Base\n";
    }
};
class Derived: public Base
{
public:
    void who()
    { 
        cout << "I am Derived\n";
    }
};
 
int main()
{
    // note here virtual function who() is called through
    // object of the class (it will be resolved at compile
    // time) so it can be inlined.
    Base b;
    b.who();
 
    // Here virtual function is called through pointer,
    // so it cannot be inlined
    Base *ptr = new Derived();
    ptr->who();
 
    return 0;
}
---------------------------------------------------------------------------
3) Can virtual function can be private
In C++, virtual functions can be private and can be overridden by the derived class. 
For example, the following program compiles and runs fine.

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

There are few things to note in the above program.
1) ptr is a pointer of Base type and points to a Derived class object. 
When ptr->fun() is called, fun() of Derived is executed.
2) int main() is a friend of Base.  If we remove this friendship, the program 
won’t compile (See this).  We get compiler error. 
-------------------------------------------------------------------------------
4) What is use of pure virtual private
What is the point of a private pure virtual function?

class Engine
{
public:
    void SetState( int var, bool val );
    {   SetStateBool( int var, bool val ); }

    void SetState( int var, int val );
    {   SetStateInt( int var, int val ); }
private:
    virtual void SetStateBool(int var, bool val ) = 0;    
    virtual void SetStateInt(int var, int val ) = 0;    
};

#include <iostream>

class Engine
{
public:
  void SetState( int var, bool val )
  {
    SetStateBool( var, val );
  }

  void SetState( int var, int val )
  {
    SetStateInt( var, val );
  }

private:

    virtual void SetStateBool(int var, bool val ) = 0;
    virtual void SetStateInt(int var, int val ) = 0;

};

class DerivedEngine : public Engine
{
private:
  virtual void SetStateBool(int var, bool val )
  {
    std::cout << "DerivedEngine::SetStateBool() called" << std::endl;
  }

  virtual void SetStateInt(int var, int val )
  {
    std::cout << "DerivedEngine::SetStateInt() called" << std::endl;
  }
};


int main()
{
  DerivedEngine e;
  Engine * be = &e;

  be->SetState(4, true);
  be->SetState(2, 1000);
}

DerivedEngine::SetStateBool() called
DerivedEngine::SetStateInt() called

 I see that a derived class can override its base class private virtual method
 but it cannot use it. So, this is essentially a Template Method pattern

---------------------------------------------------------------------------------
