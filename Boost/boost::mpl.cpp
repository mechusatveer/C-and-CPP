The boost::mpl is a high-level C++ template metaprogramming framework of compile-time algorithms, 
sequences and metafunctions.
Here is an example of calculating a factorial during compilation. It demonstrates looping through
recursive template instantiation. It also demonstrates one way in which variables are created and 
used in template metaprogramming (TMP):

#include <iostream>

template <int n>
struct Factorial 
{
    enum { value = n * Factorial<n - 1>::value };
};
 
template <>
struct Factorial<0> 
{
    enum { value = 1 };
};
 
int main()
{
	std::cout << "Factorial<5>::value = " << Factorial<5>::value << std::endl;	
}
