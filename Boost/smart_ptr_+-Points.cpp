Smart pointers are objects that act like pointers, but automate management of the underlying memory. 
If we actually need pointer semantics, scoped_ptr is great. We should only use std::tr1::shared_ptr 
with a non-const referent when it is truly necessary to share ownership of an object
(e.g. inside an STL container).
We should never use auto_ptr.

Pros
Smart pointers are extremely useful for preventing memory leaks, and are essential for writing
exception-safe code. They also formalize and document the ownership of dynamically allocated memory.
Cons
We prefer designs in which objects have single, fixed owners. Smart pointers which enable sharing or
transfer of ownership can act as a tempting alternative to a careful design of ownership semantics, 
leading to confusing code and even bugs in which memory is never deleted. The semantics of smart 
pointers (especially auto_ptr) can be nonobvious and confusing. The exception-safety benefits of 
smart pointers are not decisive, since we do not allow exceptions.
Decision
scoped_ptr
Straightforward and risk-free. Use wherever appropriate.
auto_ptr
Confusing and bug-prone ownership-transfer semantics. Do not use.
shared_ptr
Safe with const referents (i.e. shared_ptr<const T>). Reference-counted pointers with non-const
referents can occasionally be the best design, but try to rewrite with single owners 
where possible.
