//Source file for Median function

#include <algorithm> //sort
#include <stdexcept> //domain error
#include <vector> //vector
#include "median.h"
using std::domain_error; using std::sort; using std::vector;

//compute median of a vector<double>
//this fcn copies entire argument vector
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of empty vector");
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}