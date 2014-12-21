
//Compilor itself send 1 if there is no data member so we not need to take care


#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class A
{
  int x;
  public:
  A()
  {

  }
  void* operator new(size_t s) throw(std::bad_alloc)
  {
      return malloc(s);
  }
  void* operator new[](size_t s)throw(std::bad_alloc)
  {
       return malloc(s);
  }
  void operator delete(void* ptr)
  {
       free(ptr);
  }
  void operator delete[](void* ptr)
  {
       free(ptr);
  }

};

int main()
{
    A *a = new A();
    A* b = new A[10];

    delete a;
    delete b;
    delete []b;
    return 0;
}
