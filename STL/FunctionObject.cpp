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

#include <iostream>
using namespace std;

class Line {
	double a;	// slope
	double b;	// y-intercept

public:
	Line(double slope = 1, double yintercept = 1):
		a(slope),b(yintercept){} 
	double operator()(double x){
		return a*x + b;
	}
};

int main () {
	Line fa;			// y = 1*x + 1
	Line fb(5.0,10.0);		// y = 5*x + 10

	double y1 = fa(20.0);		// y1 = 20 + 1
	double y2 = fb(3.0);		// y2 = 5*3 + 10

	cout << "y1 = " << y1 << " y2 = " << y2 << endl;
	return 0;
}
