// Chapter4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include "grade.h"
#include "Student_info.h"
#include "square.h"
using std::cin;	using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;
using std::setw;

/*exercise 0
int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; //length of longest name

								  //read and store student data
								  //invariant:: students contains all student records read so far
								  //maxlen contains the legnth of the longest name in students
	while (read(cin, record)) {
		//find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//alphabetize records
	sort(students.begin(), students.end(), compare);

	//write out names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
		//write the name, padded on left to maxlen+1
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		//compute and write grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
*/
/*exercise 1 
//declare things as the same type
int main() {
	int maxlen;
	Student_info s;
	string::size_type maxstring = maxlen;
	max((int)s.name.size(), maxlen);
}
*/
/*exercise 2
int main() {
	for (int i = 0; i != 101; i++) {
		cout << setw(3) << i << setw(5)<<i*i << endl;
	}
}
*/
/*exercise 3
//need to change width to be dynamic
int main() {
	sqrn(cout, 1000);
}
*/
//exercise 4
//implement for doubles
int main() {
	double x;
	cin >> x;
	double inc;
	cin >> inc;
	cout << "EOF" << endl;
	double right = x - floor(x);
	int width1 = numwidth(x - right) + 1 + max(numwidth(right), numwidth(inc));
	int width2 = numwidth((int)(x - right) * (int)(x - right)) + std::max(numwidth(right*right), numwidth(inc *inc));
	cout << width1 << " " << width2 << "\n" << endl;
	cout <<width1<<"@:"<< numwidth((int)(x - right) * (int)(x - right)) << " " << numwidth(right)<< " ^2:" << numwidth(right*right)<<" "<< numwidth(inc *inc) << endl;
	sqrn(cout, x, inc);
}
//