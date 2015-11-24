#include <stdexcept>
#include <vector>
#include "Grades.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

//compute a students overall grade from middterm and final and hw grades
double grade(double midterm, double final, double homework) {
	return .2*midterm + .4*final + .4*homework;
}
//compute overall grade from mid/final
//and vec of hw grades
//doesnt copy arg
double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size == 0)
		throw domain_error("student has done no hw");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}