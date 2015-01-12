#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>  // std:: bind
#include <cmath>
#include <iterator>    // back_inserter

double power(double a, double b)
{
	return pow(a,b);
}

int main()
{
    std::set<int> s = { 1, 2, 3, 4, 5 };
    std::vector<int> v;
    auto fnc = std::function <double (double,double)>(power); // C++11
    std::transform(s.begin(), s.end(), 	
             std::back_inserter(v), 
             std::bind(fnc, std::placeholders::_1, 3));  // C++11
	         // {1, 8, 27, 64, 125}
}
