#pragma once

#include <iostream>
#include <vector>

namespace project
{

	std::vector<int> read_sequence(std::istream& is);

	void print_sequence(const std::vector<int> &seq, std::ostream& os);

	std::vector<int> filter_even(const std::vector<int> &seq);

}
