http://geeksquiz.com/friend-class-function-cpp/
---------------------------------------------------------------------------
Friend Class A friend class can access private and protected members of
other class in which it is declared as friend. It is sometimes useful to
allow a particular class to access private members of other class. For 
example a LinkedList class may be allowed to access private members of Node.

class Node
{
private:
  int key;
  Node *next;
  /* Other members of Node Class */
 
  friend class LinkedList; // Now class Binary Tree can 
                           // access private members of Node
};
---------------------------------------------------------------------------

Friend Function Like friend class, a friend function can be given special grant
to access private and protected members. A friend function can be:
a) A method of another class
b) A global function

class Node
{
private:
  int key;
  Node *next;
 
  /* Other members of Node Class */
  friend int LinkedList::search(); // Only search() of linkedList 
                                  // can access internal members
};


