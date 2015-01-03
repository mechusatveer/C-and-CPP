A object which behave like a function called function object
It can behave like a function if its define function call operator.
This can take one or more paramter also.

This become helpful in case of stl algo

sum of all items which are positive

class Add
{
   int sum;
   public:
   Add()
   {
      sum = 0;
   }
   int getSum(){ return sum;}
   void operator()(int x)
   {
      sum = sum + x;
   }
};


int main()
{
   Add a = for_each(v.begin(),v.end(),Add);
   cout<<a.get();

}
#include <iostream>

struct absValue
{
	float operator()(float f) {
		return f > 0 ? f : -f;
	}
};

int main( ) 
{ 
	using namespace std;

	float f = -123.45;
	absValue aObj;
	float abs_f = aObj(f);
	cout << "f = " << f << " abs_f = " << abs_f << endl;
	return 0; 
}

aObj is a object not a function
A object which behave like a function called function object

