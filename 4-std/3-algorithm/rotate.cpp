#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

void test_rotate() {
	std::vector<int> values = {5, 4, 3, 2, 1, 0};

	// ForwardIt rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );

	std::cout << "values before rotate:\n"
			  << values << std::endl;
	std::rotate(values.begin(), std::next(values.begin(), 1), values.end());
	std::cout << "values after rotate:\n"
			  << values << std::endl;
	std::rotate(values.rbegin(), std::next(values.rbegin(), 1), values.rend());
	std::cout << "values after right rotate:\n"
			  << values << std::endl;
}

int main() {
	test_rotate();

	return 0;
}