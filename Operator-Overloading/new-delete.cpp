
//Compilor itself send 1 if there is no data member so we not need to take care
//Using delete on a pointer returned by new [] or delete [] on a pointer returned 
//by new results in undefined behavior.

  void operator delete(void* ptr) throw() //keep throw as empty so if u try to throw an exception it raise error
  {
       free(ptr);
  }
  void operator delete[](void* ptr) throw()
  {
       free(ptr);
  }

//Both new and delete are static function even u not declared them
//bcoz they provide utility job so make static

/**********************************************************************************/


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
  static void* operator new(size_t s) throw(std::bad_alloc)
  {
      return malloc(s);
  }
  static void* operator new[](size_t s)throw(std::bad_alloc)
  {
       return malloc(s);
  }
  static void operator delete(void* ptr) throw()
  {
       free(ptr);
  }
  static void operator delete[](void* ptr) throw()
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
