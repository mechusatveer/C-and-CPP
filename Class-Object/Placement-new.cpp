What is "placement new" and why would I use it?

There are many uses of placement new. The simplest use is to place an object at a particular
location in memory. This is done by supplying the place as a pointer parameter to the new part of
a new expression:

char memory[sizeof(Fred)];//Allocate memory somewhere
void* place = memory;
Fred* f = new(place) Fred();

//placement new operator overload
void operator new(size_t s, void* buffer)
{
    return new(buffer) char[s];
}
/***************************************************************************************************/
Do not use placement new till it not necessary to place an object to some particular memory location.

For example, when your
hardware has a memory-mapped I/O timer device, and you want to place a Clock object at that
memory location.
/***************************************************************************************************/

/***************************************************************************************************/

Do not use delete operator if you used placement new bcoz memory allocation done by you,
new is just placing your object to your allocation you need to call explicit destructor

f->~Fred();
After this you should free your memory
If this is allocated on stakc like here do not call delete on place even.
Just call destrocut explicit and calling delete on depend on how you allocated it.

/**************************************************************************************************/

Waste to do like this but its good we can reserve memory in programme start that we can use later to
use, so later stage if new fail cna happen we not really need memory from new we done it programme start
when there was a lot memory available.
One more case

char* p = new char[sizeof(Fred)];
Fred *f = new(p) Fred();
f->~Fred();
delete []p;

/***************************************************************************************************/
