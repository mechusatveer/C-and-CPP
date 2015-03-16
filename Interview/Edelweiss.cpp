Virtual function should not be called from destructor

we should call them outside destructro

class Base
{
   void fun() = 0;

}

class Derived : public Base
{
  public:
  void fun()
  {
  
  
  }
}

class MostDerived : public Derived
{
  public:
  void fun()
  {
  
  }
}

if we call fun from destructor it be a issue

It is usually not a good idea to call a virtual function from a constructor/destructor

The reason for this is that dynamic dispatch is strange during these two operations. 
The actual type of the object changes during construction and it changes again during
destruction. When a destructor is being executed, the object is of exactly that type,
and never a type derived from it. Dynamic dispatch is in effect at all time, but the
final overrider of the virtual function will change depending where in the hierarchy
you are.
