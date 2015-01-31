void PassPtr(int (*pt2Func)(float, std::string, std::string))
{
   int result = (*pt2Func)(12, "a", "b"); 
   cout << result << endl;
}

// execute example code
void Pass_A_Function_Pointer()
{
   PassPtr(&DoIt);
}
------------------------------------------------------------------
typedef int(*ptr2Func)(float,std::string,std::string);
void PassPtr(ptr2Func fptr)
{
   int result = (*fptr)(12, "a", "b"); 
   cout << result << endl;
}
-----------------------------------------------------------------
#include <functional>
#include <string>
#include <iostream>

void PassFxn(std::function<int(float, std::string, std::string)> func)
//           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
{
   int result = func(12, "a", "b"); // call using function object
   std::cout << result << std::endl;
}
-------------------------------------------------------------------
int DoIt(float f, std::string s1, std::string s2)
{
    std::cout << f << ", " << s1 << ", " << s2 << std::endl;
    return 0;
}

int DoItWithFourArgs(float f, std::string s1, std::string s2, bool b)
{
    std::cout << f << ", " << s1 << ", " << s2 << ", " << b << std::endl;
    return 0;
}

struct X
{
    int MemberDoIt(float f, std::string s1, std::string s2)
    {
        std::cout << "Member: " << f << ", " << s1 << ", " << s2 << std::endl;
        return 0;
    }

    static int StaticMemberDoIt(float f, std::string s1, std::string s2)
    {
        std::cout << "Static: " << f << ", " << s1 << ", " << s2 << std::endl;
        return 0;
    }
};
int main()
{
    PassFxn(DoIt); // Pass a function pointer...

    // But we're not limited to function pointers with std::function<>...

    auto lambda = [] (float, std::string, std::string) -> int
    {
        std::cout << "Hiho!" << std::endl;
        return 42;
    };

    PassFxn(lambda); // Pass a lambda...

    using namespace std::placeholders;
    PassFxn(std::bind(DoItWithFourArgs, _1, _2, _3, true)); // Pass bound fxn

    X x;
    PassFxn(std::bind(&X::MemberDoIt, x, _1, _2, _3)); // Use a member function!

    // Or, if you have a *static* member function...
    PassFxn(&X::StaticMemberDoIt);

    // ...and you can basically pass any callable object!
}
