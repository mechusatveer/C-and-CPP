/*************************************************************************************/
Make base class constructor as protected bcoz use of this only to provide a generic way
Same like InstanceCounter.

It should expose a public method static T* getInstance()

getInstance calls constructor of derived
this can be done only if its declared as friend in derived class
/************************************************************************************/

#include<iostream>
#include<map>
using namespace std;

template<class T>
class singleton
{
   private:
   static T* ptr;
   protected:
   singleton()
   {
     cout<<"Singleton :: constrcutor called"<<endl;
   }
   public:
   static T* getInstance()
   {
      if(ptr == NULL)
      {
          ptr = new T();
      }
      return ptr;
   }
};
template<class T>
T* singleton<T>::ptr = NULL;

class Student : public singleton<Student>
{
   friend singleton;
   private:
   Student()
   {
      cout<<"Student::constrocut"<<endl;
   }
};

int main()
{
   Student *p = Student::getInstance();
   Student *q = Student::getInstance();
   Student *r = Student::getInstance();

   return 0;
}
