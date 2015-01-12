A callback is a pointer to a function within Module_A that is passed to Module_B 
so that Module_B can invoke the function in Module_A. But Module_B does not know
anything about Module_A, and it has no include or does not have any dependency on
Module_A. Therefore, callbacks are particularly useful to allow low-level code to 
execute high-level code that it cannot have any link dependency. That's why callbacks
are a popular way of breaking cyclic dependencies in huge projects.

Sometimes, it is useful to provide a closure with the callback functions. 
The closure is a piece of data that Module_A passes to Module_B,
and it is sort of states.

We will declare a function ptr in module B

#include <string>
class Module_B
{
   public:
      typedef void (*CallbackType)(const std::string &name, void *data);
      void setCallback(CallbackType cb,void *data);
   private:
      CallbackType mCallback;
      void *mClosure;
};

Then the Module_B can invoke the callback function with something like this:

if(mCallback)
{
   (*mCallback) ("Hi", mClosure);
}

However, using callbacks in C++ has one implication. In other words, it is non-trivial 
to use a method as a callback because the this pointer of the object also needs to be passed.
Actually, boost::bind in Boost library provides a solution to this issue. 
It implements functors (functions with state) that can be realized in C++ as a class with 
private member variables to hold the state and an overloaded operator() to
execute the function.

