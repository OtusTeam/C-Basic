#include "line_separator.h"

#include <array>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
void example_std_containers(const T &container) {
	auto iter = std::next(container.cbegin(), 3);
	std::cout << *iter << std::endl;

	++iter;
	std::cout << *iter << std::endl;

	--iter;
	--iter;
	std::cout << *iter << std::endl;

	for (auto itr = container.crbegin(); itr != container.crend(); ++itr) {
		std::cout << (*itr) << " ";
	}
	std::cout << std::endl;

	for (auto itr = container.cbegin(); itr != container.cend(); ++itr) {
		std::cout << (*itr) << " ";
	}
	std::cout << std::endl;
	std::cout << "front: " << container.front() << std::endl;
	std::cout << "back:  " << container.back() << std::endl;

	for (const auto &item : container) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

int main(int, char *[]) {
	LineSeparator::out(" Example 1 Array:");
	std::array<int, 10> array_8 = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	example_std_containers(array_8);

	LineSeparator::out(" Example 2 Vector:");
	std::vector<double> vector_8 = {1.0, 1.1, 1.2, 1.3, 1.4, 0.15, 160.5};
	example_std_containers(vector_8);

	LineSeparator::out(" Example 3 List:");
	std::list<std::string> list_8 = {
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten"};

	example_std_containers(list_8);

	return 0;
}
