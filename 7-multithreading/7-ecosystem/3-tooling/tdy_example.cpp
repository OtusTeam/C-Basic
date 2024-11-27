// clang-tidy -extra-arg="-std=c++17" -checks=-*, clang-analyzer-*,concurrency-*,cppcoreguidelines-*,performance-*,portability-*,readability-* tdy_example.cpp

// All checks:
// https://clang.llvm.org/extra/clang-tidy/checks/list.html

#include <iostream>

#include <vector>

int main() {

	//std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (auto& v : values) {
		std::cout << v << ' ';
	}

	std::cout << values[42] / 0 << std::endl;

	return 0;
}