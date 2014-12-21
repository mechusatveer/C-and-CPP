//Use vector to create array of objects if your class not have default constructor

/*We cannot create an array of objects if our class not have default constructOR
Fred a[10]; //Error
Fred *p = new Fred[10];
we should use vector in this case bcoz vector use any type of constructor
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;


class A
{
public:
    A(int x)
    {

    }
};
int main()
{
     //A a[10];
     //A *a = new A[10];
     vector<A> a(10,A(5)); //10 objects created with x as 5
     vector<A*> b(10,new A(5));

     A c[3] = {A(1),A(2),A(3)};
     A* d[3] = {new A(1),new A(2),new A(3)};

    return 0;
}
