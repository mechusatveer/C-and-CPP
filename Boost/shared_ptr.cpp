#include <boost/smart_ptr/shared_ptr.hpp>
#include <iostream>
#include <memory>

class A{};

int main()
{
	boost::shared_ptr<A> pA(new A);

	std::cout << pA.get() << std::endl;

	boost::shared_ptr<A> pB(pA);

	std::cout << pA.get() << std::endl;
	std::cout << pB.get() << std::endl;

	return 0;
}

002C0950
002C0950
002C0950

Since copying boost::shared_ptr works as we expect, it can be used in STL containers while we cannot 
use std::auto_ptr for STL containers.


#include <boost/smart_ptr/shared_ptr.hpp>;
#include <iostream>
#include <memory>

class classA
{
	boost::shared_ptr<int> ptA;
public:
	classA(boost::shared_ptr<int> p) : ptA(p) {}
	void setValue(int n) {
		*ptA = n;
	}
};

class classB
{
	boost::shared_ptr<int> ptB;
public:
	classB(boost::shared_ptr<int> p) : ptB(p) {}
	int getValue() const {
		return *ptB;
	}
};

int main()
{
	boost::shared_ptr<int> pTemp(new int(2013));
	classA a(pTemp);
	classB b(pTemp);

	a.setValue(2014);
	std::cout << "b.getValue() = " << b.getValue() << std::endl;

	return 0;
}
output
b.getValue() = 2014

For dynamically allocated arrays, we shouldn't use either of them because they use 
delete in their destructor but not delete[]. 

We can use vector instead. If we insist on using boost, we can use either
boost::shared_array or boost::scoped_array.

