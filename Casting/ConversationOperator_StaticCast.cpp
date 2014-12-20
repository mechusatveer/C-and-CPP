TThere are 4 type of case

1) Static cast related type and its ok if conversation operator defined
2) Dynamic cast related type cast 
3) const cast  only similar type
4) reinterpret cast Any to any cast


static cast work on ovject, * and ref all three type
we can apply static cast if conversation operator defined for that class
B b(10);
A a = static_cast<A>(b)

if class B deinfe a conversation operator then static cast will work else not

conversation operator not have a return type

operator op_name()
{
     return op_name(args);
}
class can have a public method for specific data type conversions.
for example:
class Boo
{
  double value;
  public:
  Boo(int i )
  operator double()
  {
      return value;
  }
};
Boo BooObject;
double i = BooObject; // assigning object to variable i of type double.
now conversion operator gets called to assign the value. 

#include<iostream>
#include<vector>
using namespace std;

class A
{
  int x;
  public:
  A(int i):x(i){}
  void print()
  {
    cout<<x<<endl;
  }
};
class B
{
   public:
       operator A()
       {
           return A(3);
       }
};
int main()
{
    B b;
    A a = static_cast<A>(b);
    a.print();
    return 0;
}
