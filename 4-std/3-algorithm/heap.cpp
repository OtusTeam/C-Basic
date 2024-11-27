#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

void test_heap() {

	std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "Values:\n"
			  << values << std::endl;

	// bool is_heap( RandomIt first, RandomIt last )

	std::cout << "is_heap = " << std::is_heap(values.cbegin(), values.cend()) << std::endl;

	// void make_heap( RandomIt first, RandomIt last );

	std::make_heap(values.begin(), values.end());

	std::cout << "Values in heap structure:\n"
			  << values << std::endl;

	// void push_heap( RandomIt first, RandomIt last );

	values.push_back(42);
	std::cout << "Values before push_heap:\n"
			  << values << std::endl;
	std::push_heap(values.begin(), values.end());
	std::cout << "Values after push_heap:\n"
			  << values << std::endl;

	std::pop_heap(values.begin(), values.end());
	std::cout << "Values after pop_heap:\n"
			  << values << std::endl;

	// WRONG!
	// values is not a heap now!
	// std::pop_heap(values.begin(), values.end());
	// std::cout << "Values after pop_heap:\n" << values << std::endl;

	// std::pop_heap(values.begin(), values.end());
	// std::cout << "Values after pop_heap:\n" << values << std::endl;

	// remove the last element
	values.pop_back();

	// now values is a heap again
	std::pop_heap(values.begin(), values.end());
	std::cout << "Values after pop_heap:\n"
			  << values << std::endl;
}

int main() {

	test_heap();

	return 0;
}