In order to correctly use shared_ptr with an array, you must supply a custom deleter.

template< typename T >
struct array_deleter
{
  void operator ()( T const * p)
  { 
    delete[] p; 
  }
};

Create the shared_ptr as follows

std::shared_ptr<int> sp( new int[10], array_deleter<int>() );
Now shared_ptr will correctly call delete[] when destroying the managed object.

With C++11, you can also use a lambda instead of the functor.

std::shared_ptr<int> sp( new int[10], []( int *p ) { delete[] p; } );
