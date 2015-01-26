Is assignment operator inherited?

In C++, like other functions, assignement operator function is inherited in derived class.

using namespace std;
 
class A {
 public:
   A & operator= (A &a) { 
    cout<<" base class assignment operator called "; 
    return *this;
   }
};
 
class B: public A { };
 
int main()
{
  B a, b;
  a.A::operator=(b); //calling base class assignment operator function 
                    // using derived class
  getchar();
  return 0;
}

++a = 20 its ok pre increment can be used as l value
a++ = 20 error
