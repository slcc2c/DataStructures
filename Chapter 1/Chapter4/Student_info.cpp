#include "Student_info.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}
istream& read(istream& is, Student_info& s) {
	//read and store names and test grades in struct
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework); //read and store hw
	return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//empty previous contents
		hw.clear();

		//read
		double x;
		while (in >> x)
			hw.push_back(x);
		//clear
		in.clear();
	}
	return in;
}