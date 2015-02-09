
http://www.bogotobogo.com/cplusplus/Boost/boost_AsynchIO_asio_tcpip_socket_server_client_timer_A.php

Blocking Timers
BLOCKING WAIT ON A TIMER (SYNCHRONOUS TIMER)
===============

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
  boost::asio::io_service io;
 
  for(int i = 0; i < 5; i++) {
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(i));
    timer.wait();
    std::cout << "Blocking wait(): " << i << " second-wait\n";
  }

  return 0;
}


Make file for this would be 

sync_timer: sync_timer.o
        g++ -o sync_timer sync_timer.o -lboost_system -lboost_thread -lpthread
sync_timer.o: sync_timer.cpp
        g++ -c sync_timer.cpp
clean:
        rm -f *.o sync_timer
        


$ make
g++ -c sync_timer.cpp
g++ -o sync_timer sync_timer.o  -L /usr/lib -lboost_system -lboost_thread -lpthread

$ ./sync_timer
Blocking wait(): 0 second-wait
Blocking wait(): 1 second-wait
Blocking wait(): 2 second-wait
Blocking wait(): 3 second-wait
Blocking wait(): 4 second-wait


To use timers, the Boost.Date_Time header file is included.
We declared an io_service object io:
boost::asio::io_service io;
we declared an object of type boost::asio::deadline_timer.
The asio classes that provide I/O (in this case timer) take a reference to an io_service as their
first argument. The second argument sets the timer to expire in i seconds.
boost::asio::deadline_timer t(io, boost::posix_time::seconds(i));
We used a blocking wait on the timer. In other words, the call to deadline_timer::wait() will not 
return until the timer has expired.

NON-BLOCKING WAIT ON A TIMER (ASYNCHRONOUS ASYNCHRONOUS WAIT ON THE TIMER)
==========================================================================
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void work_for_io_service(const boost::system::error_code& /*e*/)
{
  std::cout << "Non-blocking wait() \n";
}

int main()
{
  boost::asio::io_service io;

  boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));

  // work_for_io_service() will be called 
  // when async operation (async_wait()) finishes  
  // note: Though the async_wait() immediately returns
  //       but the callback function will be called when time expires
  timer.async_wait(&work_for_io_service);

  std::cout << " If we see this before the callback function, we know async_wait() returns immediately.\n This confirms async_wait() is non-blocking call!\n";

  // the callback function, work_for_io_service(), will be called 
  // from the thread where io.run() is running. 
  io.run();

  return 0;
} 

When we use boost.asio for asynchronous data processing, we're relying on I/O services and I/O objects.
While the I/O services abstract operating system interfaces that allow asynchronous data processing, 
the I/O objects are used to initiate certain operations such as boost::asio::io_service::run().

While it would be possible to call a function that returns after five seconds, an asynchronous
operation is started with asio by calling the method async_wait() and passing the name of 
handler function (work_for_io_service()) as its single argument.

Note that only the name of the handler function is passed but the function itself is not called.

The advantage of async_wait() is that the function call returns immediately instead of waiting 
five seconds. Once the time expires, the function provided as the argument is called accordingly.
The application thus can execute other operations after calling async_wait() instead of just blocking.

That's why we call async_wait() non-blocking compared to the blocking wait() we used in the
previous section where the execution flow should be blocked until a certain operation has finished.

While looking at the source code of the above example, it can be noticed that after the call to 
async_wait(), a method named run() is called on the I/O service. This is mandatory since control
needs to be taken over by the operating system in order to call the callback handler function after five seconds.

The asio library provides a guarantee that callback handlers will only be called from threads 
that are currently calling io_service::run(). Therefore unless the io_service::run() function
is called the callback for the asynchronous wait completion will never be invoked.

The io_service::run() function will also continue to run while there is still "work" to do. 
In this example, the work is the asynchronous wait on the timer, so the call will not return 
until the timer has expired and the callback has completed.

While async_wait() starts an asynchronous operation and returns immediately, run() actually blocks. 
Execution therefore stops at the call of run(). However, many operating systems support 
operations via a blocking function only. The following example demonstrates why this limitations is 
typically not an issue.
