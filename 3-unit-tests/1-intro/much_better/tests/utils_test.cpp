#include "../include/utils.h"

#include <sstream>

#include <cassert>

namespace tests
{

void read_sequence_test_simple() {
	// Arrange
	std::stringstream stream{"1 2 3 4 5 6 7 8 9 10"};
	const std::vector<int> ref_seq{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	};

	// Act
	std::vector<int> values = project::read_sequence(stream);

	// Assert
	assert(values.size() == ref_seq.size());
	for (size_t i = 0; i < values.size(); ++i) {
		assert(values[i] == ref_seq[i]);
	}

	// Попробуйте реализовать тесты остальных функций самостоятельно

} // namespace tests

}

int main() {

	tests::read_sequence_test_simple();

	std::cout << "Test success!" << '\n';

	return 0;
}