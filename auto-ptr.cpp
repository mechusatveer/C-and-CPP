An auto_ptr can't point to an array. When deleting a pointer to an array we must use delete[] 
to ensure that destructors are called for all objects in the array, but auto_ptr uses delete.

It can't be used with the STL containers-elements in an STL container. When an auto_ptr is 
copied, ownership of the memory is transferred to the new auto_ptr and the original is set 
to NULL. In other words, auto_ptrs don't work in STL containers because the containers, or
algorithms manipulating them, might copy the stored elements. Copies of auto_ptrs aren't equal
because the original is set to NULL after being copied. An STL container may make copies of its 
elements, so you can't guarantee that a valid copy of the auto_ptr will remain after the algorithm
processing the container's elements finishes.


the get() method returns a pointer to the object pointed by the auto_ptr object, if any, or 
zero if it does not point to any object.

#include <iostream>
#include <memory>

using namespace std;
class A{};

int main()
{
	auto_ptr<A> pA(new A);

	cout << pA.get() << endl;

	auto_ptr<A> pB(pA);

	cout << pA.get() << endl;
	cout << pB.get() << endl;

	return 0;
}

Output:-
0x8dde248
0
0x8dde248
