#pragma once
#include <iostream>
#include <ios>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <iostream>

std::ostream& sqrn(std::ostream& o, int max);
std::ostream& sqrn(std::ostream& o, double max);
std::ostream& sqrn(std::ostream& o, double max, double inc);
int numwidth(int x);
int numwidth(double x);