#include <cmath>
#include <iomanip>
#include <iostream>

int main(int, char *[]) {
	bool condition_value = true; // false

	// 1. while
	int i = 0;
	while (condition_value) {
		std::cout << "i = " << i << std::endl;
		++i;
		if (i >= 10)
			break;
	}

	std::cout << "--------------------------\n";

	// 2. do-while
	int j = 0;
	do {
		std::cout << "j = " << j << std::endl;
		++j;
		if (j >= 10)
			break;

	} while (condition_value);

	// 3. Condition might change.
	const double eps = 1e-4;
	double a = -0.5;
	double b = 3.5;

	double fa = a * a - 1.;
	double fb = b * b - 1.;

	while (std::fabs(fa - fb) > eps) {
		const double xm = 0.5 * (a + b);
		const double fm = xm * xm - 1.;

		// std:: cout << "xm = " << xm << " fm = " << fm << std::endl;
		std::cout << "[" << std::setw(5) << std::setprecision(3) << std::right << a;
		std::cout << ", ";
		std::cout << std::setw(8) << std::setprecision(6) << std::left << b << "]" << std::endl;

		if (fm > 0.0) {
			b = xm;
			fb = fm;
		} else {
			a = xm;
			fa = fm;
		}
	}

	std::cout << "a = " << a << " fa = " << fa << std::endl;
	std::cout << "b = " << b << " fb = " << fb << std::endl;

	// 4. Arithmetic progression sum
	const int n_size = 10;
	int sum = 0;
	int k = 0;

	while (++k <= n_size) {
		std::cout << k << " ";
		sum += k;
	}
	std::cout << "\nsum : " << sum << std::endl;

	return 0;
}

//
