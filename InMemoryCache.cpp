=================================================================================================
An in-memory cache is used to store things that are typically stored externally, like a database
record, an HTTP request, or the contents of a file. Typically, you'll maintain an LRU list of objects. 
This is pretty easy to manage, as all you have to do is move an object to the head of the list when 
you get a request for it, and remove the last object in the list when you need to add a new one.
Obviously, you can add a lot of complexity to tune this behavior, but that's the basic algorithm.

You'll probably want a "read-through" cache. That is, the program always asks the cache for the 
object it needs, and if it doesn't exist in the cache then it's up to the cache to fetch it. 
This way, it simplifies the programming, as the application doesn't have to go to two different
places to get an object. It can also make it possible to invisibly add caching, 
if you can modify an existing module (e.g., a DAO) that is already responsible for
reading the object.
========================================================================================
class Integer
{
    int value;
public:
    Integer(int value) : value(value)
    {
        sleep(1000); // Simulates an expensive constructor
    }
};

Creating an object of Integer is expensive operation

Now imagine that you need to create instances of this class:

Integer one(1);
Integer two(2);
// etc.

Suppose after some time you want to create a new object of Integer with value 2
you cannot use constructor bcoz it takes two much time
May be copy constructor also take same

Integer two2(2);

This is expensive. What if you could recycle the old value? 
Using constructors, this isn’t possible but using factory methods 
we can do this easily:

class Integer
{
    int value;

    static std::map<int, Integer> cache;
    Integer(int value) : value(value)
    {
        sleep(1000); // Simulates an expensive constructor
    }

    friend Integer make_int(int);
};

Integer make_int(int value)
{
    std::map<int, Integer>::iterator i = Integer::cache.find(value);
    if (i != Integer::cache.end())
        return i->second;

    Integer ret = Integer(value);
    Integer::cache[value] = ret;
    return ret;
}

Now we can use make_int to create or retrieve an integer. 
Each value will only be created once:

Integer one = make_int(1);
Integer two = make_int(2);
Integer other = make_int(2); // Recycles instance from above.




