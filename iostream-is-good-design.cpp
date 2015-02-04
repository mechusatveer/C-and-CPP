Who architected / designed C++'s IOStreams, and would it still be considered
well-designed by today's standards?
---------------------------------------------------------------------------------------
I would say NO, for several reasons:
1)Poor error handling
   - Error conditions should be reported with exceptions, not with operator void*.
2) Poor separation between formatting and I/O
This makes stream objects unnecessary complex, as they have to contain extra state
information for formatting, whether you need it or not.

It also increases the odds of writing bugs like:

using namespace std; // I'm lazy.
cout << hex << setw(8) << setfill('0') << x << endl;
// Oops!  Forgot to set the stream back to decimal mode.


IOStream use private inheritance 





Why does my program go into an infinite loop when someone enters an invalid input character?

int main()
{
  std::cout << "Enter numbers separated by whitespace (use -1 to quit): ";
  int i = 0;
  while (i != -1) {
    std::cin >> i;        // BAD FORM — See comments below
    std::cout << "You entered " << i << '\n';
  }
  ...
}

The problem with this code is that it lacks any checking to see if someone entered an invalid input character.
In particular, if someone enters something that doesn't look like an integer (such as an 'x'),
the stream std::cin goes into a "failed state," and all subsequent input attempts return immediately 
without doing anything. In other words, the program enters an infinite loop; if 42 was the last number
that was successfully read, the program will print the message You entered 42 over and over

An easy way to check for invalid input is to move the input request from the body of the while loop
into the control-expression of the while loop. E.g.,

#include <iostream>

int main()
{
  std::cout << "Enter a number, or -1 to quit: ";
  int i = 0;
  while (std::cin >> i) {    // GOOD FORM
    if (i == -1) break;
    std::cout << "You entered " << i << '\n';
  }
  ...
}

This will cause the while loop to exit either when you hit end-of-file, or when you enter a bad integer, 
or when you enter -1.

