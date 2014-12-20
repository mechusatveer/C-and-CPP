   // Standard LockGuard.  
   //Acquires lock at construction and releases at destruction.   No manual acquisition or releasal 
   // is allowed.
   
   //Implemented using template
   
   //Copy constructor & assignment operator should be disallowed
   //We should keep referance of Lock variable
   
   /*****************************************************************/
   1. Receive as a referance
   2. Use explicit
   3. Keep as a referance
   4. Disallow copy constructor and assignment operator
   5. LockGuard class holding a referance of Lock class object
   /*****************************************************************/
   template <class Lock>
   class LockGuard 
   {
   public:
      explicit LockGuard(Lock& resource) : m_lock(resource) 
      {
         m_lock.acquire();
      }

      ~LockGuard() {
         m_lock.release();
      }

   private:
      LockGuard(const LockGuard<Lock>&);
      LockGuard<Lock>& operator=(const LockGuard<Lock>&);

      Lock& m_lock;
   };
