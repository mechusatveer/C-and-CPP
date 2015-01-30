There was a question in written round that there is a global static
variable ‘lock’ initially set to 0 and there was a code segment given.

while(lock);
lock = 1;
//Critical section
lock = 0; 
Does this solve critical section problem. I answered that it will solve
in uni processor system but not in multiprocessor system. 
Then he asked me to explain my answer. After a long discussion we came
to a conclusion that this wont even solve in uni processor system. 
Then he asked me the solution to solve this. 
I did that using testandset instruction.

Suppose in a uniprocessor we have two thread

If thread transition happen after while(lock); and before lock = 1;
so both threads makes it 1.

TestAndSet instruction first check it for zero and then if its
true make it 1 in single cpu instruction.
----------------------------------------------------------------------------
When a function is called in thread, what variables can be accessed from it. 
There was a long discussion on this too. I went in the wrong direction but 
corrected myself later. Stack variables are copied but heap variables are same.
-------------------------------------------------------------------------------
