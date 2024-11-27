#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::list<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

void test_remove() {
	std::cout << "\ntest_remove\n";

	std::vector<int> values{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	std::cout << "values before remove:\n"
			  << values << std::endl;

	// ForwardIt remove_if( ForwardIt first, ForwardIt last, UnaryPredicate p );
	auto iter = std::remove_if(values.begin(), values.end(),
							   [](int v) { return v < 5; });

	std::cout << "values after remove:\n"
			  << values << std::endl;
	std::cout << "iter: [" << std::distance(values.begin(), iter)
			  << "] = " << *iter << std::endl;

	values.erase(iter, values.end());
	std::cout << "values after erase:\n"
			  << values << std::endl;
}

void test_remove_copy() {
	std::cout << "\ntest_remove_copy\n";

	std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// ForwardIt2 remove_copy( ExecutionPolicy&& policy, ForwardIt1 first, ForwardIt1 last,
	//                     ForwardIt2 d_first, const T& value );

	// OutputIt remove_copy_if( InputIt first, InputIt last, OutputIt d_first,
	//                      UnaryPredicate p );

	std::list<int> dest;
	std::remove_copy_if(values.cbegin(), values.cend(),
						std::front_inserter(dest),
						[](int v) { return v < 5; });

	std::cout << "values after remove_copy_if:\n"
			  << values << std::endl;
	std::cout << "dest after remove_copy_if:\n"
			  << dest << std::endl;
}

int main() {
	test_remove();
	test_remove_copy();

	return 0;
}