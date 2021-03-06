
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

new & delete should write in pairs.
do not do like you override delete but not write new for your class

void* raw = operator new(sizeof(Foo), pool);
Foo *a = new(raw)Foo();

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
  ~A()
  {
     cout<<"Destructor called"<<endl;
  }
  static void* operator new(size_t s) throw(std::bad_alloc)
  {
      cout<<"Base 1 constructor called "<<s<<endl;
      return malloc(s);
  }

  static void operator delete(void* ptr, size_t s) throw()
  {
       cout<<"Base 1 destructor called "<<s<<endl;
       free(ptr);
  }

  static void* operator new[](size_t s) throw(std::bad_alloc)
  {
      cout<<"Base 2 constructor called "<<s<<endl;
      return malloc(s);
  }

  static void operator delete[](void* ptr, size_t s) throw()
  {
       cout<<"Base 2 destructor called "<<s<<endl;
       free(ptr);
  }
};

int main()
{
    A *b = new A[10];
    delete b;
    delete []b;
    return 0;
}

void* operator new(size_t nbytes)
{
  if (nbytes == 0)
  nbytes = 1; // so all alloc's get a distinct address
  void* ans = malloc(nbytes + 4); // overallocate by 4 bytes
  *(Pool**)ans = NULL; // use NULL in the global new
  return (char*)ans + 4; // don't let users see the Pool*
}
void* operator new(size_t nbytes, Pool& pool)
{
  if (nbytes == 0)
  nbytes = 1; // so all alloc's get a distinct address
  void* ans = pool.alloc(nbytes + 4); // overallocate by 4 bytes
  *(Pool**)ans = &pool; // put the Pool* here
  return (char*)ans + 4; // don't let users see the Pool*
}

void operator delete(void* p)
{
  if (p != NULL)
  {
      p = (char*)p - 4; // back off to the Pool*
      Pool* pool = *(Pool**)p;
      if (pool == null)
      free(p); // note: 4 bytes left of the original p
      else
      pool->dealloc(p); // note: 4 bytes left of the original p
  }
}
