// Chapter3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::vector; using std::setprecision;

int main()
{
	/*Exercise 0a

	//ask for and read the student's name  //
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//ask for HW grades
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	//The number of grades read so far
	int count = 0;
	double sum = 0;

	//a variable in which to read
	double x;

	//invariant:
	//we have read count grades so far, and
	//sum is the sum of the first count grades.
	while (cin >> x) {
		++count;
		sum += x;
	}

	//write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< .2*midterm + .4*final + .4*sum / count
		<< setprecision(prec) << endl;

	*/
	/*Exercise 0b

	//ask for and read the student's name  //
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//ask for HW grades
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	//revised version w/ median
	double x;
	vector<double> homework;

	//invariant:homework contains all of the homework grades read so far
	while (cin >> x) {
		homework.push_back(x);
	}
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size == 0) {
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}
	sort(homework.begin(), homework.end());

	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
		: homework[mid];
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;
   */
   /*Exercise 1
   Consider the input 1 2 3 4 5
   After input 1 the median is 1
   input 2 it is 1.5 if we discard it is 1
   input 3 it is 2 if we discard it is either 2.5 or 2
   etc
   */
   /*exercise 2
   //take input
   cout << "Give me numbers and I'll give you a 5 number summary"
	   << endl;
   //create input buffer and vector
   int x;
   vector<int> nums;
   //create container for vector size
   typedef vector<int>::size_type vec_sz;
   vec_sz size;
   //take in grades
   //invariant:nums contains every input so far
   while (cin >> x) {
	   nums.push_back(x);
   }
   size = nums.size();
   if (size == 0) {
	   cout << endl << "You must enter numbers. "
		   "Please try again." << endl;
	   return 1;
   }
   //define the quartiles
   int min = nums[0];
   int max = nums[size-1];
   int first = size % 4 == 0 ? nums[size / 4] : nums[(size / 4) + 1];
   int third = size % 4 == 0 ? nums[3*(size / 4)] : nums[(3*(size / 4)) + 1];

   //output
   cout << "min: " << min
	   << " 25%: " << first
	   << " 75%: " << third
	   << " max: " << max << endl;
   */
	/*
   //exercise 3/4

   //create container for vector size
	typedef vector<int>::size_type vec_sz;
	//create holder for input 
	vector<string> xs;
	vector<int> counts;

	//ask for input 
	cout << "Please input a list of words: " << endl;
	string x;
	int lng; int sht;
	//take in input
	while (cin >> x) {
		bool flag = false;

		for (vec_sz i = 0; i < xs.size(); i++) {
			if (x == xs[i]) {
				++counts[i];
				flag = true;
			}
		}
		if (!flag) {
			xs.push_back(x);
			counts.push_back(1);
		}
	}
	//output for exercise 3
	sht = xs[0].size();
	lng = xs[0].size();
	for (vec_sz i = 0; i < xs.size(); i++) {
		cout << xs[i] << " : " << counts[i] << endl;
		int size = xs[i].size();
		if (size > lng) {
			lng = size;
		}
		if (size < sht) {
			sht = size;
		}
	}
	//output for exercise 4
	cout << "smallest: " << sht << " largest: " << lng;
	*/
	
	//exercise 5
	//create container for vector size
	typedef vector<int>::size_type vec_sz;
	vec_sz hw_limit = 5;
	//create container for input 
	vector<string> names;
	vector<int> grades;

	//take in input 
	//invariant: after i steps names contains the i names so far
	//and grades contains i grades such that grades[i] is the grade of
	//names[i]
	cout << "what is the students name? " << endl;
	string name;
	while (cin >> name) {
		names.push_back(name);
		int sum = 0;
		int x = 0;
		//ask for hw_limit number of grades
		//invariant: sum contains the total of the i grades so far
		cout << "please input " << hw_limit << " grades:\n";
		for (vec_sz i = 0; i < hw_limit; i++) {
			cin >> x;
			sum += x;
		}
		int mean = sum / hw_limit;
		grades.push_back(mean);
		cout << "Please enter a new name or press ctrl-z:\n";
	}

	//output grades and names
	for (vec_sz i = 0; i < grades.size(); i++)
	{
		cout << names[i] << " : " << grades[i] << endl;
	}

	return 0;
	

}

