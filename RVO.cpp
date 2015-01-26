Returning an object of built-in type from a function usually carries little 
to no overhead, since the object typically fits in a CPU register. Returning
a larger object of class type may require more expensive copying from one
memory location to another. To avoid this, an implementation may create a 
hidden object in the caller's stack frame, and pass the address of this object to the function.
The function's return value is then copied into the hidden object.[5] Thus, code such as this:

struct Data { 
  char bytes[16]; 
};
 
Data f() {
  Data result = {};
  // generate result
  return result;
}
 
int main() {
  Data d = f();
}


struct Data { 
  char bytes[16]; 
};
 
Data * f(Data * _hiddenAddress) {
  Data result = {};
  // copy result into hidden object
  *_hiddenAddress = result;
  return _hiddenAddress;
}
 
int main() {
  Data _hidden; // create hidden object
  Data d = *f(&_hidden); // copy the result into d
}

