If you run the same program twice, what section would be shared in the memory? 

The physical pages associated with shared libraries and the text segment are mapped 
into the virtual address space of both processes. Pages that are copy-on-write, until 
modified. Plus, any explicitly shared memory segments as well - mmap().

