#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

int main() {

	std::vector<int> values = {1, 9, 2, 0, 3, 8, 4, 7, 5, 6};
	std::cout << "Values beffore partition:" << std::endl;
	std::cout << values << std::endl;

	// ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPredicate p );
	auto iter = std::partition(values.begin(), values.end(),
							   [](int v) { return v < 5; });

	std::cout << "Values after partition:" << std::endl;
	std::cout << values << std::endl;
	std::cout << "Iter: " << std::distance(values.begin(), iter) << ": " << *iter << std::endl;

	return 0;
}