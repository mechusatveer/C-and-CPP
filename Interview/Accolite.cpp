1) Can we decalre a destructor as pure virtual
We can do it no issue in declaring as pure virtual

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
