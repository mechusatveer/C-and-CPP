#include <iostream>
using namespace std;

struct Iris
{
    ~Iris() { cout << "Iris dtor\n"; }
};

struct Setosa : public Iris
{
    ~Setosa() { cout << "Setosa dtor\n"; }
};

int main()
{
    Iris *i = new Setosa;
    delete i;
}
Output:

Iris dtor
================================================================================

#include <iostream>
using namespace std;

struct Iris

{
    virtual ~Iris() { cout << "Iris dtor\n"; }
};

struct Setosa : public Iris
{
    ~Setosa() { cout << "Setosa dtor\n"; }
};

int main()
{
    Iris *i = new Setosa;
    delete i;
}

Output:

Setosa dtor
Iris dtor
===============================================================

If we use boost::shared_ptr, we may not need virtual destructor since the smart 
point will take care of it for us:

// iris.cpp
#include <boost/shared_ptr.hpp>
#include <iostream>
using namespace std;

struct Iris
{
   ~Iris() { cout << "Iris dtor\n"; }
};

struct Setosa : public Iris
{
    ~Setosa() { cout << "Setosa dtor\n"; }
};

int main()
{
    boost::shared_ptr<Iris> i(new Setosa);

    return 0;
}
