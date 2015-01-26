Can a destructor be pure virtual in C++?

Yes

but we have to provide body to pure virtual destructor 

Yes, it is possible to have pure virtual destructor. Pure virtual destructor
are legal in standard C++ and one of the most important thing is that if class contains
pure virtual destructor it is must to provide a function body for the pure virtual destructor

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};
 
class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed";
    }
};
 
int main()
{
    Base *b=new Derived();
    delete b;
    return 0;
}

The linker will produce following error in the above program.

test.cpp:(.text$_ZN7DerivedD1Ev[__ZN7DerivedD1Ev]+0x4c): 
undefined reference to `Base::~Base()'

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};
Base::~Base()
{
    std::cout << "Pure virtual destructor is called";
}
 
class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed\n";
    }
};
 
int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}
