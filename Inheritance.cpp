class A
{
public:
	int xPublic;
protected:
	int xProtected;	
private:
	int xPrivate;
};

class B : public A
{
public:
	void foo(A *a, B *b)
	{
		a->xProtected = 0.0;     // error: A::xProtected inaccessible
		b->xProtected = 0.0;     // OK: inherited member
		this->xProtected = 0.0;
	}
}

int main(int argc, char** argv)
{
	A a;
	B b;
	b.xProtected = 0.0;	// error: inaccessible outside of a class - inherited xProtected 
	b.foo(&a, &b);

	return 0;
}

if there is ambugity then we should resolve it 

else compiler flag error abt it


class A
{
public:
	void foo() const { std::cout << "A"; }
};

class B
{
public:
	void foo() const { std::cout << "B"; }
};

class C : public A, public B
{
    public:
	using A::foo;  // note that this is private section
};

int main()
{
	B b;
	b.foo();  // OK: B::foo()

	C c;
	c.foo();

	return 0;
}


#include <iostream>
using namespace std;

class A
{
public:
	A(int n = 1) : ia(n) { cout << "A()" << endl; }

protected:
    int ia;
};

class B : public A
{
public:
	B(int n) : ib(n) { cout << "B()" << endl; }

private:
    int ib;
};

int main()
{
    B b(2);

    return 0;
}


#include <iostream>
using namespace std;

class A
{
public:
	A(int n = 1) : ia(n) 
	{ cout << "A() ia = " << ia <<  endl; }
	~A() 
	{ cout << "~A() ia = " << ia << endl; }

protected:
        int ia;
};

class B : public A
{
public:
	B(int n) : a1(ia+10), a2(n)
	{ cout << "B()" << endl; }
	~B() 
	{ cout << "~B() ia = " << ia-- << endl; }

private:
	A a2;
	A a1;
};

int main()
{
	{B b(20);}

        return 0;
}

A() ia = 1
A() ia = 20
A() ia = 11
B()
~B() ia = 1
~A() ia = 11
~A() ia = 20
~A() ia = 0


#include <iostream>
using namespace std;

class A
{
public:
	A(int n = 1) : ia(n) 
	{ cout << "A() ia = " << ia <<  endl; }
	~A() 
	{ cout << "~A() ia = " << ia << endl; }

protected:
        int ia;
};

class B : public A
{
public:
	B(int n) : a1(new A[5]), a2(n)
	{ cout << "B()" << endl; }
	~B() 
	{ 
		cout << "~B() ia = " << ia-- << endl;
		delete[] a1;
	}

private:
	A a2;
	A* a1;
};

int main()
{
       {B b(20);}

       return 0;
}

A() ia = 1
A() ia = 20
A() ia = 1
A() ia = 1
A() ia = 1
A() ia = 1
A() ia = 1
B()
~B() ia = 1
~A() ia = 1
~A() ia = 1
~A() ia = 1
~A() ia = 1
~A() ia = 1
~A() ia = 20
~A() ia = 0


//class a top class and make constructor as private
//make base class as frind
class BaseTemp
{
     private:
     BaseTemp();
     friend Base;
}

//do a virtual inheritance
class Base : virtual public BaseTemp
{
      


}

class Derived : public Base
{


}



one other way can be

class Base
{
   private:
   Base();
   static Base* Create()
   {
        return new Base();
   }
}
above class does not allow object creation on stack too
class Derived : public Base //error

}
