// OTUS C++ basic course example
// GCD with command line args

#include <cstdlib>
#include <iostream>

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " a b\n";
		return 1;
	}
	int a = std::atoi(argv[1]);
	int b = std::atoi(argv[2]);
	std::cout << gcd(a, b) << "\n";

	return 0;
}