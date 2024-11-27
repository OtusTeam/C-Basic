// OTUS C++ basic course
// Function overloading example

#include <cmath>
#include <cstdlib>
#include <iostream>

double module(double x) {
	return std::fabs(x);
}

double module(double x, double y) {
	return std::sqrt(x * x + y * y);
}

double module(double x, double y, double z) {
	return std::sqrt(x * x + y * y + z * z);
}

int main(int argc, char *argv[]) {
	switch (argc) {
	case 2: {
		double x = std::atof(argv[1]);
		std::cout << module(x) << "\n";
		break;
	}
	case 3: {
		double x = std::atof(argv[1]);
		double y = std::atof(argv[2]);
		std::cout << module(x, y) << "\n";
		break;
	}
	case 4: {
		double x = std::atof(argv[1]);
		double y = std::atof(argv[2]);
		double z = std::atof(argv[3]);
		std::cout << module(x, y, z) << "\n";
		break;
	}
	default: {
		std::cerr << "Usage: " << argv[0] << " x [y] [z]\n";
		return 1;
	}
	}
}