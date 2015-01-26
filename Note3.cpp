Why we should make a destructor as pure virtual

Do u think we forcing to override destructor in derived class ?
No we cannot enforce them bcoz in derived destructor name is different

then what is use of making destructor as pure virtual

making virtual used to consistant order while child object destroy
pure we can use when we have none of function which we can enforce to derived
but making destructor as pure virtual we make base as abstract class and child are totally free

#include<iostream>

using namespace std;

class A
{
   public:
   virtual ~A()=0;
};
A::~A()
{
   cout<<"Destructor called for A"<<endl;
}

class B : public A
{

};

int main()
{
  A a; //Error
  B b;//This work fine
  return 0;
}

