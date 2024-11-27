#include <bitset>
#include <iostream>


int main(int, char *[]) {
	// 1. Arithmetic progression sum
	const int n_size = 10;
	int sum = 0;

	for (int i = 0; i < n_size; ++i) {
		std::cout << i << " ";
		sum += i;
	}
	std::cout << "\nsum : " << sum << std::endl;

	// 3.
	int i = 0;
	for (;;) {  
		if (++i > 100)
			break;
	}
	std::cout << "i = " << i << std::endl;

	// 4. Overflow
	int j = 0;
	for (std::size_t k = 100; k >= 0; k += 3) {
		std::bitset<32> buffer(k);
		std::cout << k << " ";
		std::cout << buffer << std::endl;
		;
		if (++j > 104)
			break;
	}

	// 5. Continue
	for (int i = 0; i < 10; ++i) {
		if (i % 2) {
			std::cout << "start next iteration for i = " << i << std::endl;
			continue;
		}

		std::cout << " full loop iteration " << i << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
