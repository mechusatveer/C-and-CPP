There are several libraries which are function objects and higher-order programming. They are 
used as the basis for functionality in TR1. One of those libraries is the Lambda library, 
which makes it so easy to create function objects on the fly:

#include <iostream>
#include <vector>
#include <algorithm>

#include <boost/lambda/lambda.hpp>

using namespace std;

void makeSquare(vector<int>&v)
{
	for_each(v.begin(), v.end(), cout << boost::lambda::_1*boost::lambda::_1 << " ");
}

int main()
{
	vector<int> v;
	for(int i = 1; i <= 10; i++) v.push_back(i);

	makeSquare(v);
	return 0;
}

For each element x in v, print x*x:
boost::lambda::_1*boost::lambda::_1
_1 is the Lambda library's placeholder for the current element.
