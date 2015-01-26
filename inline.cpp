Remember, inlining is only a request to the compiler, not a command.
Compiler can ignore the request for inlining. Compiler may not perf
orm inlining in such circumstances like:
1) If a function contains a loop. (for, while, do-while)
2) If a function contains static variables.
3) If a function is recursive.
4) If a function return type is other than void, and the return statement
doesn’t exist in function body.
5) If a function contains switch or goto statement.
