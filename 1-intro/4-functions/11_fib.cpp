// OTUS C++ basic course
// Recursive fibinacci numbers

#include <cstdlib>
#include <iostream>

// Eval nth fibanicci number
unsigned long fib(unsigned long n) {
	if (n < 2) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[]) {
	unsigned long n = 100;
	if (argc == 2) {
		long tmp = std::atol(argv[1]);
		if (tmp < 0) {
			std::cerr << "Only non-negative number allowed\n";
			return 1;
		}
		n = tmp;
	}
	for (unsigned long i = 0; i < n; ++i) {
		std::cout << fib(i) << "\n";
	}

	return 0;
}








// n -> calls count

// 0 -> 514229
// 1 -> 832040
// 2 -> 514229
// 3 -> 317811
// 4 -> 196418
// 5 -> 121393
// 6 -> 75025 
// 7 -> 46368 
// 8 -> 28657 
// 9 -> 17711 
// 10 -> 10946
// 11 -> 6765
// 12 -> 4181
// 13 -> 2584
// 14 -> 1597
// 15 -> 987
// 16 -> 610
// 17 -> 377
// 18 -> 233
// 19 -> 144
// 20 -> 89
// 21 -> 55
// 22 -> 34
// 23 -> 21
// 24 -> 13
// 25 -> 8
// 26 -> 5
// 27 -> 3
// 28 -> 2
// 29 -> 1
// 30 -> 1