//For matrix we cannot use [] bcoz this takes only 1 paramter
//we should overload () operator

#include<iostream>

using namespace std;

class Matrix
{
    private:
    int row;
    int col;
    int *data;
    public:
    Matrix(int r, int c)
    {
        row = r;
        col = c;
        data = new int[row*col];
    }

    int& operator()(int r, int c)
    {
       cout<<"1"<<endl;
       return data[r*col + c];
    }

};

int main()
{
   Matrix m(3,4);
   m(0,0) = 5;
   m(0,1) = 6;
   cout<<m(0,1)<<endl;
}
