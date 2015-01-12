#include <string>
#include <iostream>

int main()
{
	std::string name;
	std::cout << "Type your full name: ";
	std::cin >> name;     // stops at the first space
	std::cout << "Hello, " << name << std::endl;
	std::cout << "Re-type your full name: ";
	getline(std::cin, name);  // read the rest to the end of the line
	std::cout << "Welcome to C++ string, " << name << "!";
}

cin leaves out the new line character in the buffer, and the getline() function gets it.

#include <sstream>;
#include <string>
#include <iostream>

int main()
{
	std::string number_s = "99";
	int ss_to_number;
	std::stringstream ss;
	ss << number_s;     // load a string to ss
	ss >> ss_to_number; // extract an integer from ss
	int n = ss_to_number / 3;
	std::cout << "The extracted integer is " << n << std::endl;

	// to re-use ss, we need to empty and clear
	ss.str("");
	ss.clear();
	int number_i = 99;
	std::string ss_to_string;
	std::string text_out =
		"We extracted a string by converting an int sstream";
	ss << number_i;     // load an integer
	ss >> ss_to_string; // extract a string from ss
	text_out += " from " + ss_to_string;
	std::cout << text_out << std::endl;

	return 0;
}

#include <string>
#include <iostream>

int main()
{
	std::string book  = "Jane Austin's Pride and Prejudice";

	// starting from 29th, copy 9 character
	std::string sub = book.substr(24, 9);
	std::cout << sub << std::endl;        // "Prejudice"

	// the last character
	std::cout << book.at(book.size()-1) << std::endl;  //'e'

	return 0;
}
