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

