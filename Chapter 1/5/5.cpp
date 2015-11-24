// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;	using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;

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
