// Calculate greatest common divisor using Euclidean algorithm

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string_view>
#include <system_error>

enum class GcdErrc {
	NoError = 0,
	DivizionByZero,
	NotEnoughParams,
	NonDigitChar,
	NegativeNumber,
	TooLargeNumber,
};

class gcd_category : public std::error_category {
public:
	const char *name() const noexcept override {
		return "gcd";
	}

	std::string message(int condition) const override;
};

std::error_condition make_error_condition(GcdErrc errc) {
	static gcd_category gcd_err_category;
	return std::error_condition{static_cast<int>(errc), gcd_err_category};
}

unsigned gcd(unsigned a, unsigned b, std::error_condition &err);
unsigned parse_unsigned(char *str, std::error_condition &err);

int main(int argc, char *argv[]) {
	std::error_condition err = make_error_condition(GcdErrc::NoError);
	int gcd_err = 0;
	do {
		if (argc < 3) {
			err = make_error_condition(GcdErrc::NotEnoughParams);
			break;
		}
		unsigned a = parse_unsigned(argv[1], err);
		if (err) {
			break;
		}
		unsigned b = parse_unsigned(argv[2], err);
		if (err) {
			break;
		}
		unsigned result = gcd(a, b, err);
		if (err) {
			break;
		}
		std::cout << result << "\n";
	} while (false);

	if (err) {
		std::cerr << err.message() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

unsigned gcd(unsigned a, unsigned b, std::error_condition &err) {
	if (!b) {
		std::cerr << "GCD error: divison by zero\n";
		err = make_error_condition(GcdErrc::DivizionByZero);
		return 0;
	}
	do {
		unsigned r = a % b;
		a = b;
		b = r;
	} while (b);

	err = make_error_condition(GcdErrc::NoError);
	return a;
}

unsigned parse_unsigned(char *str, std::error_condition &err) {
	std::string_view sw{str};
	if (!std::all_of(sw.begin(), sw.end(), ::isdigit)) {
		err = make_error_condition(GcdErrc::NonDigitChar);
		return 0;
	}

	long val = std::atol(str);
	if (val < 0) {
		err = make_error_condition(GcdErrc::NegativeNumber);
		return 0;
	}
	if (val > std::numeric_limits<unsigned>::max()) {
		err = make_error_condition(GcdErrc::TooLargeNumber);
		return 0;
	}
	return static_cast<unsigned>(val);
}

std::string gcd_category::message(int condition) const {
	switch (static_cast<GcdErrc>(condition)) {
	case GcdErrc::NoError:
		return "No error";
	case GcdErrc::DivizionByZero:
		return "Diviztion by zero";
	case GcdErrc::NotEnoughParams:
		return "Usage: gcd a b";
	case GcdErrc::NonDigitChar:
		return "Number parse error: all chars must be digits";
	case GcdErrc::NegativeNumber:
		return "Number parse error: input must be positive integer";
	case GcdErrc::TooLargeNumber:
		return "Number parse error: input number is too large";
	default:
		return "Unknown error";
	}
}