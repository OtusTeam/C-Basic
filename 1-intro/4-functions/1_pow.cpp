// OTUS C++ Basic course
// pow function example
#include <iostream>
#include <limits>

#include <cfloat>
#include <cmath>

// Write pow function code below
double pow(double a, double b)
{
	return 0;
}

// compare if two double are close enougth and can be interpteted as equal
bool is_close(double a, double b)
{
	if (std::isinf(a) && std::isinf(b))
	{
		return true;
	}
	if (std::isnan(a) && std::isnan(b))
	{
		return true;
	}
	return std::fabs(a - b) < std::numeric_limits<double>::epsilon() *
								  std::max(1.0, std::max(std::abs(a), std::abs(b)));
}

namespace float_precision
{
	int demo()
	{
		float value = 10'000'000'000.f;
		float diff = 1'000'000.f;
		std::cout << std::setprecision(20) << "value = " << value << std::endl;
		std::cout << std::setprecision(20) << "std::nextafterf(value, value+diff) = " << std::nextafterf(value, value + diff) << std::endl;

		std::cout << "value == value+diff : " << (value == (value + diff)) << std::endl;

		return 0;
	}
}

// Test compares results of pow function provided by programmer with std::pow
bool test_pow(double base, unsigned int exp)
{
	std::cout << "Testing pow(" << base << ", " << exp << ")\t";
	double expected = std::pow(base, exp);
	double actual = pow(base, exp);

	if (is_close(expected, actual))
	{
		std::cout << "OK\n";
		return true;
	}
	else
	{
		std::cout << "FAIL\n";
		std::cout << "expected: " << expected << ", actual: " << actual << "\n";
		return false;
	}
}

int main()
{
	float_precision::demo();

	bool all_success = true;

	all_success &= test_pow(2.0, 3);
	all_success &= test_pow(1.0, 1);
	all_success &= test_pow(5.0, 0);
	all_success &= test_pow(-5.0, 2);
	all_success &= test_pow(-5.0, 3);
	all_success &= test_pow(0.0, 2);
	all_success &= test_pow(1.1e+5, 10);
	all_success &= test_pow(1e-5, 10);
	all_success &= test_pow(INFINITY, 2);
	all_success &= test_pow(NAN, 2);

	return all_success;
}
