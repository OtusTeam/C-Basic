#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

void test_min_max() {
	std::vector<int> values = {3, 5, 1, 2, 3, 6, 7, 8, 9, 9, 9, 9, 5, 4, 3, 0};

	// ForwardIt min_element( ForwardIt first, ForwardIt last, Compare comp );

	std::cout << "Values:\n"
			  << values << std::endl;

	auto min_iter = std::min_element(values.cbegin(), values.cend());
	if (min_iter != values.cbegin())
		std::cout << "Min element at: "
				  << std::distance(values.cbegin(), min_iter)
				  << " = " << *min_iter << std::endl;

	auto max_iter = std::max_element(values.cbegin(), values.cend());
	if (max_iter != values.cbegin())
		std::cout << "Max element at: "
				  << std::distance(values.cbegin(), max_iter)
				  << " = " << *max_iter << std::endl;

	auto min_max = std::minmax_element(values.cbegin(), values.cend());
	if (min_max.second != values.cend())
		std::cout << "Min-Max.second element at: "
				  << std::distance(values.cbegin(), min_max.second)
				  << " = " << *min_max.second << std::endl;
}

int main() {

	test_min_max();

	return 0;
}