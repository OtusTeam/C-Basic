#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

void test_transform() {
	std::vector<std::string> names{
		"Vasia",
		"Petia",
		"Alexander",
		"Liza"};

	std::vector<std::size_t> sizes;

	// OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first,
	//                           UnaryOperation unary_op );

	std::transform(names.cbegin(), names.cend(),
				   std::back_inserter(sizes),
				   [](const std::string &name) {
					   return name.size();
				   });

	std::cout << "sizes after transform:\n"
			  << sizes << std::endl;

	// OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
	//                 OutputIt d_first, BinaryOperation binary_op );

	std::vector<std::string> names_sizes;

	std::transform(names.cbegin(), names.cend(),
				   sizes.cbegin(),
				   std::back_inserter(names_sizes),
				   [](const std::string &name, std::size_t size) {
					   return name + '_' + std::to_string(size);
				   });

	std::cout << "names_sizes after transform:\n"
			  << names_sizes << std::endl;
}

int main() {
	test_transform();

	return 0;
}