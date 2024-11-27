#include <algorithm>
#include <iostream>
#include <vector>

void test_any_of() {
	std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	bool any = std::any_of(
		values.cbegin(), values.cend(),
		[](int v) { return v == 5; });

	bool all = std::all_of(
		values.cbegin(), values.cend(),
		[](int v) { return v < 10; });

	bool none = std::none_of(
		values.cbegin(), values.cend(),
		[](int v) { return v > 100; });

	std::cout << "any = " << any << std::endl;
	std::cout << "all = " << all << std::endl;
	std::cout << "none = " << none << std::endl;
}

int main() {
	test_any_of();

	return 0;
}