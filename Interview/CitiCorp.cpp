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

Because the constructor never gets called actually.

Class object(); is interpreted as the declaration of a function object taking no 
argument and returning an object of Class [by value]

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
Problem 5
#include<iostream>

using namespace std;

class A
{
   int x;
   int &refobj;
   public:
   A(int &p) : x(p),refobj(p)
   {

   }
   ~A()
   {

       refobj = x;
   }
};

int main()
{
   int arr[] = {10,15};

       int j = 5;
       {
           A a(j);
           A b(arr[0]);
           A c(arr[1]);
           j = arr[0];
           arr[0] = arr[1];
           arr[1] = j;
           cout<<j<<" "<<arr[0]<<" "<<arr[1]<<endl;
       }
    cout<<j<<" "<<arr[0]<<" "<<arr[1]<<endl;
    return 0;
}

We want output as
10 15 10
5 10 15
write class A such a way

do not forget to receive input in ref format.
========================================================================================
Problem 6
#include<stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    cout<<sizeof("GEEKS");
    cout<<strlen("GEEKS");
    return 0;
}
Ouput 
6 5
==========================================================================================
Problem 7
#include<stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;

template<int N>
class A
{
   public:
   virtual void print()
   {
       cout<<"A::print"<<endl;
   }
};

class B : public A<2>
{
   public:
   virtual void print()
   {
       cout<<"B::print"<<endl;
   }
};

class C : public B
{

};

int main()
{
    A<2> *p = new C();
    p->print();
    return 0;
}

Output :
B::print
==============================================================================
problem 8
#include<stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;

class A
{
   public:
   A()
   {
        cout<<"Constructor called";
   }
   ~A()
   {
       cout<<"Destructor called";
   }
};

int main()
{
    delete new A();
    return 0;
}

Output:-
constructor called
Destructor called
======================================================================
problem 9

#include<stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;

class A
{

   public:
   A()
   {
        cout<<"Constructor called";
   }
   ~A()
   {
       cout<<"Destructor called";
   }
   void fun1()
   {
       cout<<"Fun called"<<endl;
   }
};

int main()
{
    const A a;
    a.fun1();
    return 0;
}
Error:-
Using const object we cannot call a non const function
