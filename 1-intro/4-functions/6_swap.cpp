// OTUS C++ basic course example
// pass parameters by reference to swap function

#include <iostream>

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

namespace reference {
	void demo() {

		int value = 42;
		int& ref = value;
		ref += 10;
		std::cout << "value = " << value << std::endl; // 52

	}
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " a b\n";
		return 1;
	}
	int a = std::atoi(argv[1]);
	int b = std::atoi(argv[2]);
	swap(a, b);
	std::cout << a << " " << b << "\n";
}
