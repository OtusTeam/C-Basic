// Calculate greatest common divisor using Euclidean algorithm

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string_view>

unsigned gcd(unsigned a, unsigned b);
unsigned parse_unsigned(char *str);

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cerr << "Usage: gcd a b\n";
		return EXIT_FAILURE;
	}
	unsigned a = parse_unsigned(argv[1]);
	if (!a) {
		return EXIT_FAILURE;
	}
	unsigned b = parse_unsigned(argv[2]);
	if (!b) {
		return EXIT_FAILURE;
	}
	unsigned result = gcd(a, b);
	if (!result) {
		return EXIT_FAILURE;
	}

	std::cout << result << "\n";
	return EXIT_SUCCESS;
}

unsigned gcd(unsigned a, unsigned b) {
	if (!b) {
		std::cerr << "GCD error: divison by zero\n";
		return 0;
	}
	do {
		unsigned r = a % b;
		a = b;
		b = r;
	} while (b);
	return a;
}

unsigned parse_unsigned(char *str) {
	std::string_view sw{str};
	if (!std::all_of(sw.begin(), sw.end(), ::isdigit)) {
		std::cerr << "Number parse error: all chars must be digits\n";
		return 0;
	}

	long val = std::atol(str);
	if (val < 0) {
		std::cerr << "Number parse error: input must be positive integer\n";
		return 0;
	}
	if (val > std::numeric_limits<unsigned>::max()) {
		std::cerr << "Number parse error: input number is too large\n";
		return 0;
	}
	return static_cast<unsigned>(val);
}
