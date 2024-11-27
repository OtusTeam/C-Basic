// OTUS C++ basic course examples
// Greatest Common Divisor function implementation

#include <cstdlib>
#include <iostream>

// Greatest Common Divisor (GCD) function
// Uses Euclidean Algorithm - https://en.wikipedia.org/wiki/Euclidean_algorithm
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	using std::cin;
	using std::cout;

	int a, b;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "gcd(a,b) = " << gcd(a, b) << "\n";

	return 0;
}
