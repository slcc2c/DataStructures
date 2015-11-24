#include "square.h"
#include <cmath>
#include <algorithm>
#include <iostream>
using std::ostream; using std::setw; using std::endl;

ostream& sqrn(ostream& o, int max) {
	int maxlen1 = (int)log10(max)+1;
	int maxlen2 = (int)log10(max*max) + 1;
	for (int i = 0; i != max+1; i++) {
		o << setw(maxlen1) << i << " "<< setw(maxlen2) << i*i << "\n";
	}
	return o;
}


ostream& sqrn(ostream& o, double max, double inc) {
	double right = max - floor(max);
	int width1 = numwidth((int)(max - right)) + std::max(numwidth(right),numwidth(inc));
	int width2 = numwidth((int)(max - right) * (int)(max - right)) + std::max(numwidth(right*right), numwidth(inc *inc));
	for (double i = 0.0; i < max + inc; i+=inc) {
		o <<setw(0)<< setw(width1) << i << " " << setw(width2) << i*i << "\n";
	}
	return o;
}

int numwidth(int x) {
	return (int)log10(x) + 1;
}
int numwidth(double x) {
	int num = 1;
	double right;
	if (abs(x) >= 1) {
		int left = (int)floor(x);
		//std::cout << "LEFT->" << left << endl;
		right = x - left;
		//adds number of digits of the left to num
		num += numwidth(left);
	}
	else {
		right = x;
	}
	//std::cout <<"RIGHT "<<x<<"->"<< right << endl;
	int i = 0;
	while (ceil(right*(pow(10.0, i)) != right*(pow(10.0, i)))) {
		if (floor(right*(pow(10.0, i)) == right*(pow(10.0, i)))) {
			break;
		}
		i++;
		//std::cout << "!! R:"<<right<<" Num: " << num + i << " floor/norm "<<ceil(right*pow(10,i))<<"/"<< floor(right*pow(10.0, i)) <<" =? " << (right*pow(10.0, i)) << " ||" << endl;
	}
	return num + i;
}