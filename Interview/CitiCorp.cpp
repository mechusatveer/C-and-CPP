Problem 1
=========
What type inheritance it affect data access only, it does not mean 
if we inherited private then it not go further inheritance
#include<iostream>

using namespace std;

class A
{
   public:
   void print()
   {
       cout<<"A::print"<<endl;
   }
};

class B : private A
{
   public:
   void print()
   {
       cout<<"B::print"<<endl;
   }
};

class C : public B
{
   public:
   void print()
   {
       cout<<"C::print"<<endl;
   }
};

int main()
{
    C c;
    c.print();
    return 0;
}
Output:-
C::Print
============================================================================================
Problem 2
#include<iostream>

using namespace std;

class A
{
   public:
   void print()
   {
       cout<<"A::print"<<endl;
   }
};


class C : public A
{
   int x;
   public:
   C(int p = 0)
   {
       x = p;
   }
   void print()
   {
       cout<<"C::print"<<endl;
   }
   int getx()
   {
       return x;
   }
};

int main()
{
    C c;
    A *a  = &c;
    cout<<a->getx();
    return 0;
}

Output:-
Error class A not have any member called getx
=======================================================================================
Problem 3

http://stackoverflow.com/questions/3810570/why-is-there-no-call-to-the-constructor
We declared a function object which taking nothing and returning a class object by value.
#include<iostream>

using namespace std;

class A
{
   public:
   A()
   {
       cout<<"A::A"<<endl;
   }
   A(const A &obj)
   {
       cout<<"Copy constrcutor called"<<endl;
   }

};

int main()
{
    //A a = A();//A::A
    //A();//A::A
    A a();//no output on screen not even any error
    return 0;
}

This code doesn't behave how I expect it to.
#include<iostream>
using namespace std;

class Class
{
    Class()
    {
        cout<<"default constructor called";
    }

    ~Class()
    {
        cout<<"destrutor called";
    }
};

int main()
{    
    Class object();
}

I expected the output 'default constructor called',
but I did not see anything as the output. What is the problem?

==========================================================================
Problem 4


#include<iostream>

using namespace std;

class A
{
   int x;
   public:
   A(int v)
   {
       x = v;
   }

};

int main()
{
    A a[10];
    return 0;
}

Error now matching function A::A()
=====================================================================

