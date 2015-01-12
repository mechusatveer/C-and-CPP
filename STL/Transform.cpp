#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  // std:: bind
#include <cmath>
#include <iterator>    // back_inserter

int main()
{
    std::vector<int> v1 = { 101, 2, 38, 64, 55 };
    std::vector<int> v2;

    std::transform(v1.begin(), v1.end(),   // source
             std::back_inserter(v2),       // destination
             std::bind(std::logical_or<bool>(),
                       std::bind(std::greater<int>(), std::placeholders::_1, 100),
                       std::bind(std::less<int>(), std::placeholders::_1, 10))
	          );  // C++11 (bind)
	          // element > 100 or element < 10
}

all items which are greater than 100 || less than 10 put in v2
