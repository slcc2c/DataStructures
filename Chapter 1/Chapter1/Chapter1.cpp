// a small C++ program
#include "stdafx.h"
#include <iostream>
#include <string>


int main()
{
	/*exercise 0a
	//ask for the person's name 
	std::cout << "Please enter your first name: ";
	//read the name  
	std::string name; //define name
	std::cin >> name; //read into
	//write a greeting 
	std::cout << "Hello, " << name << "!" << std::endl;
    */

	/*exercise 0b
	std::cout << "Please input your first name: ";
	std::string name;
	std::cin >> name;

	//build message we want to write
	const std::string greeting = "Hello, " + name + "!";

	//build second and fourth lines of the output
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";

	//first and fifth lines of output
	const std::string first(second.size(), '*');

	//write output
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *"<<std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
	*/

	/*exercise 3
	{const std::string s = "a string";
	std::cout << s << std::endl; }
	{const std::string s = "another string";
	std::cout << s << std::endl; }
	*/

	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;

	return 0;
}

