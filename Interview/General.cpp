1) If you run the same program twice, what section would be shared in the memory? 

The physical pages associated with shared libraries and the text segment are mapped 
into the virtual address space of both processes. Pages that are copy-on-write, until 
modified. Plus, any explicitly shared memory segments as well - mmap().
--------------------------------------------------------------------------------------------------
2) What do you do if your program does a core dump? 
Assuming you have 'ulimit -c 10000000' to get it to coredump in the first place, 
run it through gdb

Possible coredumps: 
Stack Overflow 
Accessing an uninitialized pointer 
Any type of undefined behavior
Access out of boundry memory

# gdb binary_name core_file_name 

 when a program does a core dump. It will save the stack, registers contents and important
 global variables and it will save the cause of the crash in the Non volatile memory area.
---------------------------------------------------------------------------------------------------
What are the various ways of doing IPC in Unix/Linux? How do you implement it?

Signals
Message passing 
using shared memory 

Server-client Model 
1. using socket 
2. using pipe- ordinary pipe or named pipe 
3. RPC- Remote procedure call 

----------------------------------------------------------------------------------------------------
Design a system like friend's functionality in facebook. should have all features of facebook's friends
functionality. like for each person , he can have any number of friends , he will get suggestions for new
firends , showing common friends if we visits any other profile . algo should be scalable , robust .

Basically a friends network is an undirected graph. Each person is a vertex of the graph and friendship 
is an edge between the two vertices. We can represent the graph by by maintaining an adjacency list. 
- Like: Each person maintains a list of Posts. Lets say person A puts a post, persons who are connected 
to person A will be notified about the post (observer pattern). Friend B can like a post which increase 
the 'Like' count. 
-For common friends check the nodes which are at distance 1 from A then from that list check the list of 
friends which are at distance 1 from B. For friends suggestion we can consider all the nodes which are 
not at distance 1 from A or not connected to A.
-------------------------------------------------------------------------------------------------------

Can we write a collection class in C++ that can store elements of different data types?

#include <iostream> 

using namespace std; 

class BaseDataType 
{ 
  public: 
  virtual void print() = 0; 
}; 

class IntDataType: public BaseDataType 
{ 
  int m_x; 
  public: 
  void print() 
  { 
  cout << "IntDataType" << endl; 
  } 
}; 

class FloatDataType: public BaseDataType 
{ 
  float m_x; 
  public: 
  void print() 
  { 
  cout << "FloatDataType" << endl; 
  } 
}; 

class DoubleDataType: public BaseDataType 
{ 
  double m_x; 
  public: 
  void print() 
  { 
  cout << "DoubleDataType" << endl; 
  } 
}; 

int main() 
{ 
  BaseDataType* a[3]; 
  a[0] = new IntDataType; 
  a[1] = new FloatDataType; 
  a[2] = new DoubleDataType; 
  
  for(int i = 0; i < 3; ++i) 
  { 
  a[i]->print(); 
  } 
  return 0; 
}

 
