C Style callbacks
-----------------

The following code illustrates a simple class that has a single callback that
is trigged when, for instance, a mouse button is pressed. The data for the 
callback consists of the mouse pointer location and a value determining
which mouse button was pressed; additional data specified by the user is
passed as a void pointer so that the user may encode any information in it.

enum mouse_button { mb_left, mb_middle, mb_right };

 typedef void (*click_callback_type)(mouse_button, int, int, void*);
 Your class have a function ptr as data member
 class widget
 {
     public:
       void set_click_callback(click_callback_type f, void* data)
       {
         m_click_callback = f;
         m_click_data = data;
       }
     private:
       click_callback_type m_click_callback;
       void*  m_click_data;
 };
 
 To use the click callback, one must create a function with the exact function signature 
 click_callback_type that decodes the void pointer into some meaningful data that was 
 initially set in the call to set_click_callback. The dangers of such a system are obvious:
 all type information is lost when the data is passed via a void pointer, so it becomes
 very easy for the programmer to lose track of the original type of the data or the
 memory allocated to store the data.
 
 Some changes to the widget class afford greater flexibility and safety, without losing 
 backward compatibility. The following code highlights the necessary changes in boldface:
 
 
 class widget
 {
       typedef boost::function3<void, mouse_button, int, int> generic_click_callback;
       static void click_thunk(mouse_button b, int x, int y, void* self)
       {
         static_cast<widget*>(self)->m_click_generic_callback(b, x, y);
       }
     public:
       template<typename F>
       void set_click_callback(F f)
       {
         m_click_callback = click_thunk;
         m_click_data     = static_cast<void*>(this);
         m_click_generic_callback = f;
       }
       void set_click_callback(click_callback_type f, void* data)
       {
         m_click_callback = f;
         m_click_data = data;
         m_click_generic_callback.clear();
       }
     private:
       click_callback_type m_click_callback;
       void*               m_click_data;
       generic_click_callback m_click_generic_callback;
 };
 
 
 The idea behind the above code is that we add a new member, m_click_generic_callback,
 that can call any function or function object that can accept a mouse_button argument
 followed by two int arguments. The click_thunk routine acts as a bridge between the
 C-style callback and the new version based on Boost.Function. This new code retains 
 backward compatibility by retaining the original function pointer/void pointer 
 interface, but enables a more flexible interface; the difference is analagous to
 the move from the C library's qsort routine to the C++ library sort routine.
 
 An Alternative Implementation using Boost.Bind
 ----------------------------------------------
 The recently introduced Boost.Bind library offers yet another solution to this problem, 
 though this solution requires changing the calls to the callback itself to remove the 
 void user data pointer. The updated code follows:
 
 enum mouse_button { mb_left, mb_middle, mb_right }; 
 typedef void (*click_callback_type)(mouse_button, int, int, void*);

 class widget {
   typedef boost::function3<void, mouse_button, int, int> generic_click_callback;
 public:
   template<typename F>
   void set_click_callback(F f)
   {
     m_click_callback = f;
   }
   void set_click_callback(click_callback_type f, void* data)
   {
     m_click_callback = boost::bind(f, _1, _2, _3, data);
   }
 private:
   generic_click_callback m_click_callback;
 };
 
 Here, we completely abandon the C-style callback and use Boost.Function directly. 
 The backwards-compatible version of set_click_callback uses the binding facilities
 of Boost.Bind to send the pointer to the old C-style callback without requiring it
 to be explicitly stored in a widget object. The call to boost::bind creates a
 function object taking three arguments, which will be passed to the function f in 
 their original order, but also a fourth parameter, the user data pointer data, will
 be passed to f. This makes the old C-style callback look like a new-style callback 
 to the rest of the widget class.
