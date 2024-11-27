#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

void permutations() {

	std::vector<int> values = {0, 1, 2, 3, 4};

	std::vector<int> test1 = {0, 1, 2, 3, 4, 5};

	std::cout << test1 << "is_permutation of: " << values;
	bool result = std::is_permutation(values.cbegin(), values.cend(), test1.cbegin());
	std::cout << " = " << std::boolalpha << result << std::endl;
	std::cout << std::endl;

	std::vector<int> test2 = {0, 1, 1, 3, 4, 5};

	std::cout << test2 << "is_permutation of: " << values;
	result = std::is_permutation(values.cbegin(), values.cend(), test2.cbegin());
	std::cout << " = " << std::boolalpha << result << std::endl;

	std::cout << std::endl;
	std::cout << "permutations for " << values << std::endl;
	int count = 5;
	for (int i = 0; i < count; ++i) {
		std::next_permutation(values.begin(), values.end());
		std::cout << "next: " << values << std::endl;
	}
}

int main() {

	permutations();

	return 0;
}