Remember, inlining is only a request to the compiler, not a command.
Compiler can ignore the request for inlining. Compiler may not perf
orm inlining in such circumstances like:
1) If a function contains a loop. (for, while, do-while)
2) If a function contains static variables.
3) If a function is recursive.
4) If a function return type is other than void, and the return statement
doesn’t exist in function body.
5) If a function contains switch or goto statement.


There are some problems with the use of macros in C++. Macro cannot access
private members of class. Macros looks like function call but they are actually not.

C++ compiler checks the argument types of inline functions and necessary
conversions are performed correctly. Preprocessor macro is not capable for doing this. 
One other thing is that the macros are managed by preprocessor and inline 
functions are managed by C++ compiler

Remember: It is true that all the functions defined inside the class are implicitly
inline and C++ compiler will perform inline call of these functions, but C++ compiler
cannot perform inlining if the function is virtual. The reason is call to a virtual
function is resolved at runtime instead of compile time. Virtual means wait until 
and inline means
during compilation, if the compiler doesn’t know which function will be called, 
how it can perform inlining?
