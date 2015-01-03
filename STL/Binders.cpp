Binders are function adapters.

Function adapter converts some other interface to an interface used by STL.

template <class Operation, class T>
  binder2nd<Operation> bind2nd (const Operation& op, const T& x);
  
It returns function object with second parameter bound. This function constructs an 
unary function object from the binary function object op by binding its second parameter 
to the fixed value x.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct PrintElm
{
	void operator()(int & elm) const { cout << elm << ' ';}
};

int main()
{
	int size = 10;
	vector<int> v;
	for(int i = 0; i < size; i++) v.push_back(i);
	for_each(v.begin(), v.end(), PrintElm()); cout << endl;
	replace_if(v.begin(), v.end(), 
		   bind2nd(equal_to<int>(),0), 
	           101);
	for_each(v.begin(), v.end(), PrintElm()); cout << endl;
	v.erase(
		remove_if(v.begin(), v.end(), 
		           bind2nd(less<int>(), 3)), 
		v.end()
		);
	for_each(v.begin(), v.end(), PrintElm()); cout << endl;
	transform(v.begin(), v.end(),
	          ostream_iterator<int>(cout, " "),           
		  negate<int>()); 
	return 0;
}

To count all the elements within a vector that are less than or equal to 100, we can use count_if():
count_if(vec.begin(), vec.end(),
			bind2nd(less_equal<int>(), 100));
			
			
