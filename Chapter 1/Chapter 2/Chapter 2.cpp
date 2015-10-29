// Chapter 2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <string>
using std::cin; using std::endl;
using std::cout; using std::string;
/*exercise 9
int main() {
	//take in input from user
	cout << "Please input two numbers, seperated by a space... ";
	int x, y;
	cin >> x >> y;
	cout << "The larger of these numbers is... ";
	if (x - y > 0) {
		cout << x;
	}
	if (y - x > 0) {
		cout << y;
	}
	else {
		cout << "N/A, these numbers are equal";
	}
	cout << endl;
	return 0;

}
*/
/*exercise 8
int main() {
	//ask user for a range
	cout << "Min? ";
	int min;
	cin >> min;
	cout << "Max? ";
	int max;
	cin >> max;

	//do the math prod starts at Identity so as to take on the value of min, this fullfills the loop invariant
	//that at each step i prod = product of numbers [min,min+i)
	int prod = 1;
	for (int i = min; i != max; i++) {
		prod *= i;
		cout << prod << endl;
	}
}


/*Exercise 6/7
using std::cin; using std::endl;
using std::cout; using std::string;
int main()
{
	int i = 11;
	while (i > -5) {
		i -= 1;
		cout << i << endl;
	}

	return 0;
}
*/
/*Exercise 5
int main()
{
	cout << "Welcome to *Draw!" << endl;
	cout << "What kind of shape would you like to draw?\n" << "1-Square|2-Rectangle|3-Triangle: ";
	int choice;
	cin >> choice;
	//cout << choice << endl;
	if (choice == 1) {
		//getting square's parameters 
		cout << "What is the height of your square? ";
		int height;
		cin >> height;

		//creating the square
		string full(height, '*');
		string foo((height - 2), ' ');
		string empty = "*" + foo + "*";
		//cout << empty << " " << full << " " << height << endl;
		for (int i = 0; i != height; ++i) {
			//cout << i << endl;
			if (i == 0) {
				cout << full << endl;
			}
			else {
				cout << empty << endl;
			}
		}
		cout << full << endl;
		
	}
	if (choice == 2) {
		//getting rectangle's parameters
		cout << "What is the height of your rectangle? ";
		int height;
		cin >> height;
		cout << "What is the width of your Rectangle? ";
		int width;
		cin >> width;

		//creating the rectangle
		string full(width, '*');
		string foo((width - 2), ' ');
		string empty = "*" + foo + "*";
		//cout << empty << " " << full << " " << height << endl;
		for (int i = 0; i != height; ++i) {
			//cout << i << endl;
			if (i == 0) {
				cout << full << endl;
			}
			else {
				cout << empty << endl;
			}
		}
		cout << full << endl;
		 

	}
	if (choice == 3) {
		//getting triangles parameters

		cout << "Height? ";
		int height;
		cin >> height;

		//creating right triangle

			cout << "*\n";
			string last(height, '*');
			//height minus two because the last line has two more * than the second to last
			for (int i = 0; i != (height - 2); i++) {
				string blanks(i, ' ');
				cout << "*" << blanks << "*" << endl;
			}
			cout << last << endl;
			
		
	}
	return 0;
}
*/
/*Exercise 2/3/4
// say what standard-library names we use
int main()
{
	//ask for the person's name  
	cout << "Please enter your first name: ";
	//read the name
	string name;
	cin >> name;
	//the number of blanks surrounding the greeting
	//ask for x padding
	cout << "How much horizontal frame padding would you like? ";
	//read x padding
	int x_pad;
	cin >> x_pad;
	//ask for y padding
	cout << "How much vertical frame padding would you like? ";
	//read y padding
	int y_pad;
	cin >> y_pad;
	//test write x/y pads
	//cout << (x_pad * 2)<<" " << (y_pad * 2) << endl;
	
	//build the message that we intend to write 
	const string greeting_only = "Hello, " + name + "!";

	//the number of rows and columns to write 
	const int rows = (y_pad * 2) + 3;
	const string::size_type cols = greeting_only.size() + (x_pad * 2) + 2;

	//build the mostly blank seperator lines
	string foo((cols - 2), ' ');
	string blank_line = "*" + foo + "*\n";
	
	//build greeting line with added blanks. 
	int greeting_blanks = (foo.size() - greeting_only.size())/2;
	string bar((greeting_blanks), ' ');
	string bar2((foo.size() - bar.size() - greeting_only.size()), ' ');
	string greeting = "*" + bar + greeting_only + bar2 + "*\n";

	//build the line of ******
	string ast1(greeting.size()-1,'*');
	string ast = ast1 + "\n";
	//write a blank line to separate the output from the input  
	cout << greeting <<  TEST "r "<< rows << "c " << cols << "gr " << greeting  << endl;	
	
	//rows of output  rows write  
	//invariant: we have written r rows so far  
	int i = rows - 3;
	for (int r = 0; r != rows; ++r) {
		if (r == 0 || r==rows) {
			cout << ast;
		}
		if (r == y_pad + 1) {
			cout << greeting;
		}
		else {
			//if (i-- != 0) {
				cout << blank_line;
			//}
			
		}	
	}
	cout << ast << endl;
	return 0;
}
*/

/*exercise 1
// say what standard-library names we use
int main()
{
	//ask for the person's name  
	cout << "Please enter your first name: ";
	//read the name
	string name;
	cin >> name;
	//build the message that we intend to write 
	const string greeting = "Hello, " + name + "!";
	//the number of blanks surrounding the greeting  CHANGED TO 0 FOR NO PADDING
	const int pad = 0;
	//the number of rows and columns to write 
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	//write a blank line to separate the output from the input  
	cout << endl;
	//rows of output  rows write  
	//invariant: we have written r rows so far  
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;
		//invariant: we have written c characters so far in the current row  
		while (c != cols) {
			//is it time to write the greeting? 
			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				//are we on the border?
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	return 0;
}
*/


/*exercise 0
// say what standard-library names we use
int main()
{
	//ask for the person's name  
	cout << "Please enter your first name: ";
	//read the name
	string name;
	cin >> name;
	//build the message that we intend to write 
	const string greeting = "Hello, " + name + "!";
	//the number of blanks surrounding the greeting  
	const int pad = 1;
	//the number of rows and columns to write 
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	//write a blank line to separate the output from the input  
	cout << endl;
	//rows of output  rows write  
	//invariant: we have written r rows so far  
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;
		//invariant: we have written c characters so far in the current row  
		while (c != cols) {
			//is it time to write the greeting? 
			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				//are we on the border?
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	return 0;
}
*/

