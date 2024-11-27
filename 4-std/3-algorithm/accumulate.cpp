#include <iostream>
#include <numeric>
#include <vector>

void test_accumulate() {
	std::vector<int> values = {3, 5, 1, 2, 3, 6, 7, 8, 9, 9, 9, 9, 5, 4, 3, 0};

	// T accumulate( InputIt first, InputIt last, T init,
	//           BinaryOperation op )

	std::cout << "result = " << std::accumulate(values.cbegin(), values.cend(), 0, [](int sum, int v) {
		return sum + v;
	});
	std::cout << std::endl;

	// OutputIt partial_sum( InputIt first, InputIt last, OutputIt d_first );

	std::vector<int> results(values.size(), 0);
	std::partial_sum(values.cbegin(), values.cend(), results.begin());

	std::cout << "Results after partial_sum:" << std::endl;
	for (const auto &v : results)
		std::cout << v << ' ';
	std::cout << std::endl;
}

int main() {

	test_accumulate();

	return 0;
}