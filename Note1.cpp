Can we make copy constructor private?

Yes, a copy constructor can be made private. When we make a copy constructor
private in a class, objects of that class become non-copyable. This is 
particularly useful when our class has pointers or dynamically allocated 
resources. In such situations, we can either write our own copy constructor like above 
String example, or make a private copy constructor so that users get compiler
errors rather than surprises at run time

