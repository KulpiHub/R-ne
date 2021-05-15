#include <iostream>

int main() {
	double d;
	if (std::cin >> d) {
		for (double a; std::cin >> a;) {
			if (a < d) d = a;
		}
		std::cout << d;
	}
}
