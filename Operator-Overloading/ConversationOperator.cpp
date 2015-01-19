 
1. Conversation operator work on objects not on pointers.
2. it not have return type
3. it will return a object not pointer 
 
#include<iostream>
 
using namespace std;
 
class Base
{
 
};
class Derived : public Base
{
   int x;
 
   public:
   Derived(int p)
   {
       x = p;
   }
   operator int()
   {
       return x;
   }
};
 
int main()
{
   Derived *d1 = new Derived(1);
   Derived *d2 = new Derived(2);
   Derived *d3 = new Derived(3);
 
   int i = *d1;
   int j = *d2;
   int k = *d3;
   cout<<i<<j<<k<<endl;
   return 0;
}
 
output = 123
 
conversation operator not hold any input parameter.
 
below programme fails
 
#include<iostream>
 
using namespace std;
 
class Base
{
 
};
class Derived : public Base
{
   int x;
 
   public:
   Derived(int p)
   {
       x = p;
   }
   operator int(const Derived &d)
   {
       return d.x;
   }
};
 
int main()
{
   Derived *d1 = new Derived(1);
   Derived *d2 = new Derived(2);
   Derived *d3 = new Derived(3);
 
   int i = *d1;
   int j = *d2;
   int k = *d3;
   cout<<i<<j<<k<<endl;
   return 0;
}
