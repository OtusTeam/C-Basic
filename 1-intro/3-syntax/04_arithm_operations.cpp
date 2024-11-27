#include <iostream>

int main(int, char *[]) {
	// Integer
	int a(0);
	int b = -123;

	int d{456};
	std::cout << a << " " << b << " " << d << std::endl;
	
	// Warning here!
	int d1 = 9223372036854775807L;

	// Compilation error here!
	// int d2{9223372036854775807L};

	std::cout << "d -----> " << d1 << std::endl;
	// int d2{123.45};
	// std::cout << " " << d2 << std::endl;

	int sum1 = a + b * 2;
	std::cout << sum1 << std::endl;
	sum1 = 2345;

	// increment operators
	a = 42;
	++a;
	
	int prefix_inc = ++a;
	int postfix_inc = a++;
	std::cout << "prefix_inc: " << prefix_inc << std::endl;
	std::cout << "postfix_inc: " << postfix_inc << std::endl;
	std::cout << "a: " << a << std::endl;

	short x = 15;
	x = x / 4;
	std::cout << " x = " << x << std::endl;

	x /= 2;
	std::cout << " x = " << x << std::endl;

	// Floating point
	double x1 = 12.1;
	std::cout << " x1 = " << x1 << std::endl;
	// x1 = x1 - 5.2;
	x1 -= 5.2;
	std::cout << " x1 = " << x1 << std::endl;

	// Auto  (is intended to be used in templates)
	auto f = 4;
	auto g = 3e-5f;
	auto h = 9223372036854775807L;

	return 0;
}