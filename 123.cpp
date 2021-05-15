#include <iostream>
#include <cmath>

void fraction(double &integral, double &fractional, double param);
void fraction(double &integral, double &fractional, double param) {
	fractional = modf(param, &integral);
}

int main() {
	double integral;
	double fractional;
	fraction(integral, fractional, 3.14159);
	std::cout << integral << " " << fractional << std::endl;
}
