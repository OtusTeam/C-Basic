#include <algorithm>
#include <iostream>
#include <vector>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& values) {
	for (auto& v : values)
		std::cout << v << ' ';
	return os;
}

void test_copy() {
    std::cout << "\ntest_copy\n";

    std::vector<int> source = {0, 1, 2, 3, 4, 5, 6, 7};

    std::vector<int> dest;

    // OutputIt copy( InputIt first, InputIt last, OutputIt d_first );

    // Oooooops
    // std::copy(source.cbegin(), source.cend(), dest.begin());

    std::copy(source.cbegin(), source.cend(), 
        std::back_inserter(dest));

    std::cout << "Dest after copy:\n" << dest << std::endl;

    // OutputIt copy_if( InputIt first, InputIt last,
    //               OutputIt d_first,
    //               UnaryPredicate pred );
}

void test_generate() {
    std::cout << "\ntest_generate\n";

    std::vector<int> target(10, 0);
    std::cout << "target before generate:\n" << target << std::endl;

    std::generate(target.begin(), target.end(),
        [counter = 0]() mutable {
            return counter += 2;
        });

    std::cout << "target after generate:\n" << target << std::endl;
}

int main() {
    test_copy();
    test_generate();

    return 0;
}